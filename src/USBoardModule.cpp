/*
 * USBoardModule.cpp
 *
 *  Created on: Jun 18, 2020
 *      Author: mad
 */

#include <pilot/usboard/USBoardModule.h>
#include <pilot/usboard/USBoardData.hxx>


namespace pilot {
namespace usboard {

USBoardModule::USBoardModule(const std::string& _vnx_name)
	:	USBoardModuleBase(_vnx_name),
		m_gotConfig(9),
		m_gotData1To8(2),
		m_gotData9To16(2),
		m_gotData(0)
{
}

void USBoardModule::init()
{
	vnx::open_pipe(vnx_name, this, 100);
}

void USBoardModule::main()
{
	subscribe(input_can, UNLIMITED);
	subscribe(input_serial, 100);
	subscribe(topic_can_request, 100);

	request_config();

	Super::main();
}

std::shared_ptr<const USBoardConfig> USBoardModule::get_config() const
{
	return m_config;
}

vnx::bool_t USBoardModule::is_connected() const
{
	return false;
}

void USBoardModule::request_config()
{
	std::shared_ptr<base::CAN_Frame> frame = base::CAN_Frame::create();
	frame->time = vnx::get_time_micros();
	frame->id = m_config->can_id;
	frame->size = 8;
	frame->set_int(0, 8, CMD_READ_PARASET, 0);
	publish(frame, topic_can_request, BLOCKING);
}

void USBoardModule::request_data(const std::vector<vnx::bool_t>& groups)
{
	std::shared_ptr<base::CAN_Frame> frame = base::CAN_Frame::create();
	frame->time = vnx::get_time_micros();
	frame->id = m_config->can_id;
	frame->size = 8;
	frame->set_int(0, 8, CMD_GET_DATA, 0);
	size_t bitpos = 8;
	size_t numreq = 0;
	for(const vnx::bool_t &bit : groups){
		frame->set_bit(bitpos++, bit);
		if(bit) numreq++;
	}
	m_gotData.clear();
	m_gotData.setTargetSize(numreq);
	publish(frame, topic_can_request);
}

void USBoardModule::request_analog_data()
{
	std::shared_ptr<base::CAN_Frame> frame = base::CAN_Frame::create();
	frame->time = vnx::get_time_micros();
	frame->id = m_config->can_id;
	frame->size = 8;
	frame->set_int(0, 8, CMD_GET_ANALOG_IN, 0);
	publish(frame, topic_can_request);
}

void USBoardModule::send_config_async(	const std::shared_ptr<const USBoardConfig>& config,
										const vnx::request_id_t& request_id)
{
	send_config(config, request_id, CMD_WRITE_PARASET);
}

void USBoardModule::save_config_async(	const std::shared_ptr<const USBoardConfig>& config,
										const vnx::request_id_t& request_id)
{
	send_config(config, request_id, CMD_WRITE_PARASET_TO_EEPROM);
}

void USBoardModule::send_config(const std::shared_ptr<const USBoardConfig>& config, const vnx::request_id_t& request_id, Command command){
	m_sentConfigRequest = request_id;
	m_sentConfig = config;
	m_sentConfigAck = 8;

	std::vector<base::CAN_Frame> frames = config->to_can_frames();
	uint8_t baseplus = (command == CMD_WRITE_PARASET) ? 8 : 9;
	uint16_t bytesum = 0;
	for(base::CAN_Frame &frame : frames){
		frame.time = vnx::get_time_micros();
		frame.id = m_config->can_id + baseplus;
		frame.set_uint(0, 8, command, 0);
		for(size_t i=2; i<8; i++){
			bytesum += frame.get_uint(i*8, 8, 0);
		}
		publish(frame, topic_can_request, BLOCKING);
	}

	m_sentConfigSum = bytesum;
	m_sentConfigTimer = set_timeout_millis(5000, std::bind(&USBoardModule::async_timeout_callback, this, request_id));
}


void USBoardModule::set_channel_active(const std::vector<vnx::bool_t>& sensors)
{
	std::shared_ptr<base::CAN_Frame> frame = base::CAN_Frame::create();
	frame->time = vnx::get_time_micros();
	frame->id = m_config->can_id;
	frame->size = 8;
	frame->set_int(0, 8, CMD_SET_CHANNEL_ACTIVE, 0);
	size_t bitpos = 8;
	for(const vnx::bool_t &bit : sensors){
		frame->set_bit(bitpos++, bit);
	}
	publish(frame, topic_can_request, BLOCKING);
}


void USBoardModule::handle(std::shared_ptr<const ::pilot::base::CAN_Frame> frame){
	uint32_t baseplus = frame->id - m_config->can_id;
	// the frame is either a command message that we relayed to ourselves or an actual answer
	if(baseplus == 0){
		// one of our own messages -> wrap into serial data
		std::shared_ptr<base::DataPacket> packet = base::DataPacket::create();
		packet->time = frame->time;
		packet->payload.resize(frame->size);
		for(size_t i=0; i<frame->size; i++){
			packet->payload[i] = frame->get_uint(i*8, 8, 0);
		}
		publish(packet, topic_serial_request, vnx_sample->flags);
	}else if(baseplus == 1){
		// CMD_CONNECT
		// TODO
	}else if(baseplus == 2 || baseplus == 3){
		// CMD_GET_DATA_1TO8 part 1 + 2
		uint8_t index = frame->get_uint(8, 8, 0);
		m_gotData1To8.push(*frame, index);
		if(m_gotData1To8.complete()){
			// complete
			std::shared_ptr<USBoardData> data = USBoardData::create();
			data->from_can_frames_1to8(m_gotData1To8.clear());
			publish(data, output_data);
		}
	}else if(baseplus == 4 || baseplus == 5){
		// CMD_GET_DATA_9To16 part 1 + 2
		uint8_t index = frame->get_uint(8, 8, 0);
		m_gotData9To16.push(*frame, index);
		if(m_gotData9To16.complete()){
			// complete
			std::shared_ptr<USBoardData> data = USBoardData::create();
			data->from_can_frames_9to16(m_gotData9To16.clear());
			publish(data, output_data);
		}
	}else if(baseplus == 6){
		// CMD_READ_PARASET
		uint8_t index = frame->get_uint(8, 8, 0);
		if(!m_gotConfig.push(*frame, index)){
			throw new std::runtime_error("Received out of band part of parameter set");
		}

		if(m_gotConfig.complete()){
			std::shared_ptr<USBoardConfig> config = USBoardConfig::create();
			config->from_can_frames(m_gotConfig.clear());
			m_config = config;
			publish(config, output_config, BLOCKING);
		}
	}else if(baseplus == 7){
		// CMD_GET_ANALOGIN
		std::shared_ptr<USBoardData> data = USBoardData::create();
		std::vector<base::CAN_Frame> frames = {*frame};
		data->from_can_frames_analog(frames);
		publish(data, output_data);
	}else if(baseplus == 8 || baseplus == 9){
		// CMD_WRITE_PARASET  and  CMD_WRITE_PARASET_TO_EEPROM
		uint8_t d1 = frame->get_uint(8, 8, 0);
		uint8_t d2 = frame->get_uint(16, 8, 0);
		if(m_sentConfigAck == 0 || d1 != 0 || d2 != 0){
			// 9-th (final) frame arrived
			std::shared_ptr<vnx::Timer> t = m_sentConfigTimer.lock();
			if(t) t->stop();
			send_config_async_return(m_sentConfigRequest);

			uint16_t bytesum = d1 + (d2 << 8);
			if(bytesum == m_sentConfigSum){
				m_config = m_sentConfig;
			}else{
				throw std::runtime_error("Wrong config checksum");
			}
		}else{
			m_sentConfigAck--;
		}
	}else if(baseplus >= 11 && baseplus <= 14){
		// CMD_GET_DATA
		std::shared_ptr<vnx::Timer> t = m_gotDataTimer.lock();
		if(t) t->stop();

		m_gotData.push_noindex(*frame);
		if(m_gotData.complete()){
			getdata_send();
		}else if(t){
			t->reset();
		}else{
			m_gotDataTimer = set_timeout_millis(25, std::bind(&USBoardModule::getdata_send, this));
		}
	}else{
		throw std::runtime_error("Unknown CAN frame id " + std::to_string(frame->id));
	}
}


void USBoardModule::handle(std::shared_ptr<const ::pilot::base::DataPacket> data){
	// input as serial data -> convert to CAN frame
	// 1 byte 0xFF  +  n[=8] byte data  +  2 byte checksum
	size_t totalsize = data->payload.size();
	if(totalsize != 11) throw std::runtime_error("invalid data package: length " + std::to_string(totalsize) + " bytes");
	if(!check_checksum(data->payload, 1)) throw std::runtime_error("Wrong checksum");

	size_t datasize = totalsize - 3;
	std::shared_ptr<base::CAN_Frame> frame = base::CAN_Frame::create();
	frame->time = data->time;
	frame->size = datasize;
	// set the frame id based on the first byte(s)
	uint32_t baseplus = 0;
	bool blocking = false;
	switch(data->payload[1]){
	case CMD_CONNECT:
		baseplus = 1;
		break;
	case CMD_GET_DATA_1TO8:
		if(data->payload[2] == 0){
			// part 1
			baseplus = 2;
		}else{
			// part 2
			baseplus = 3;
		}
		break;
	case CMD_GET_DATA_9TO16:
		if(data->payload[2] == 0){
			// part 1
			baseplus = 4;
		}else{
			// part 2
			baseplus = 5;
		}
		break;
	case CMD_WRITE_PARASET:
		baseplus = 8;
		blocking = true;
		break;
	case CMD_WRITE_PARASET_TO_EEPROM:
		baseplus = 9;
		blocking = true;
		break;
	case CMD_READ_PARASET:
		baseplus = 6;
		break;
	case CMD_GET_ANALOG_IN:
		baseplus = 7;
		break;
	case CMD_GET_DATA:{
		uint8_t group = (data->payload[2] & 0b11000000) >> 6;
		baseplus = 11 + group;
		break;
	}
	default:
		throw std::runtime_error("received packet with invalid command byte " + std::to_string(data->payload[1]));
	}
	frame->id = m_config->can_id + baseplus;
	for(size_t i=0; i<datasize; i++){
		frame->set_uint(i*8, 8, data->payload[i+1], 0);
	}
	if(blocking){
		publish(frame, input_can, BLOCKING);
	}else{
		publish(frame, input_can);
	}
}


bool USBoardModule::check_checksum(const std::vector<uint8_t> &message, size_t offset){
	// Actually, with CRC, we are supposed to iterate over the whole
	// message (including the checksum) and check for 0.
	// Does not work here because, apparently, the algorithm is flawed. Funny.
	size_t length = message.size()-2;
	uint16_t uCrc16 = 0;
	uint8_t ucData[2] = {0, 0};

	for(size_t i=offset; i<length; i++){
		ucData[1]= ucData[0];
		ucData[0] = message[i];

		if(uCrc16 & 0x8000){
			uCrc16 = (uCrc16 & 0x7fff)<<1;
			uCrc16^= 0x1021;
		}else{
			uCrc16 <<= 1;
		}
		uCrc16^= (unsigned int)(ucData[0])|((unsigned int)(ucData[1]) << 8);
	}

	uint16_t inmessage = (message[length] << 8) + message[length+1];
	return (uCrc16 == inmessage);
}


void USBoardModule::async_timeout_callback(const vnx::request_id_t& request_id)
{
	auto ex = vnx::Exception::create();
	ex->what = "receive timeout";
	vnx_async_callback(request_id, ex);
}


void USBoardModule::getdata_send(){
	std::shared_ptr<USBoardData> data = USBoardData::create();
	data->from_can_frames_data(m_gotData.clear());
	publish(data, output_data);
}


} // usboard
} // pilot
