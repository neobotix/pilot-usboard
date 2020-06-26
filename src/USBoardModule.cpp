/*
 * USBoardModule.cpp
 *
 *  Created on: Jun 18, 2020
 *      Author: mad
 */

#include <pilot/usboard/USBoardModule.h>


namespace pilot {
namespace usboard {

USBoardModule::USBoardModule(const std::string& _vnx_name)
	:	USBoardModuleBase(_vnx_name)
{
}

void USBoardModule::init()
{
	vnx::open_pipe(vnx_name, this, 100);
}

void USBoardModule::main()
{
	subscribe(input_can, 100);
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
	for(size_t i=8; i<64; i++){
		frame->set_bit(i, false);
	}
	publish(frame, topic_can_request);
}

void USBoardModule::request_data(const std::vector<vnx::bool_t>& groups)
{
	std::shared_ptr<base::CAN_Frame> frame = base::CAN_Frame::create();
	frame->time = vnx::get_time_micros();
	frame->id = m_config->can_id;
	frame->size = 8;
	frame->set_int(0, 8, CMD_GET_DATA, 0);
	size_t bitpos = 8;
	for(const vnx::bool_t &bit : groups){
		frame->set_bit(bitpos++, bit);
	}
	for(size_t i=bitpos; i<64; i++){
		frame->set_bit(i, false);
	}
	publish(frame, topic_can_request);
}

void USBoardModule::request_analog_data()
{
	std::shared_ptr<base::CAN_Frame> frame = base::CAN_Frame::create();
	frame->time = vnx::get_time_micros();
	frame->id = m_config->can_id;
	frame->size = 8;
	frame->set_int(0, 8, CMD_GET_ANALOG_IN, 0);
	for(size_t i=8; i<64; i++){
		frame->set_bit(i, false);
	}
	publish(frame, topic_can_request);
}

void USBoardModule::send_config_async(	const std::shared_ptr<const USBoardConfig>& config,
										const vnx::request_id_t& request_id)
{
	throw std::logic_error("not implemented yet");
	// TODO: send to board and wait for return

	// create timeout callback
//	timer = set_timeout_millis(5000, std::bind(&USBoardModule::async_timeout_callback, this, request_id));

	// this will be called in handle() when we get the reply from the board
//	send_config_async_return(request_id);

	// once we got the reply we cancel the timeout callback also
//	timer.get().stop();

	// store the new config if it was set successfully
//	m_config = config;
}

void USBoardModule::save_config_async(	const std::shared_ptr<const USBoardConfig>& config,
										const vnx::request_id_t& request_id)
{
	throw std::logic_error("not implemented yet");
	// TODO: send to board and wait for return

	// create timeout callback
//	timer = set_timeout_millis(5000, std::bind(&USBoardModule::async_timeout_callback, this, request_id));

	// this will be called in handle() when we get the reply from the board
//	save_config_async_return(request_id);

	// once we got the reply we cancel the timeout callback also
//	timer.get().stop();

	// store the new config if it was set successfully
//	m_config = config;
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
	for(size_t i=bitpos; i<64; i++){
		frame->set_bit(i, false);
	}
	publish(frame, topic_can_request);
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
		publish(packet, topic_serial_request);
	}else if(baseplus == 1){
		// CMD_CONNECT
		// TODO
	}else if(baseplus == 2){
		// CMD_GET_DATA_1TO8 part 1
		// TODO
	}else if(baseplus == 3){
		// CMD_GET_DATA_1TO8 part 2
		// TODO
	}else if(baseplus == 4){
		// CMD_GET_DATA_9To16 part 1
		// TODO
	}else if(baseplus == 5){
		// CMD_GET_DATA_9TO16 part 2
		// TODO
	}else if(baseplus == 6){
		// CMD_READ_PARASET
		// TODO
	}else if(baseplus == 7){
		// CMD_GET_ANALOGIN
		// TODO
	}else if(baseplus == 8){
		// CMD_WRITE_PARASET
		// TODO
	}else if(baseplus == 9){
		// CMD_WRITE_PARASET_TO_EEPROM
		// TODO
	}else if(baseplus >= 11 && baseplus <= 14){
		// CMD_GET_DATA
		uint8_t group = baseplus - 11;
		// TODO
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
		break;
	case CMD_WRITE_PARASET_TO_EEPROM:
		baseplus = 9;
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
	publish(frame, input_can);
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


} // usboard
} // pilot
