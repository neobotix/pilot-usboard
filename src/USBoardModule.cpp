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

void USBoardModule::async_timeout_callback(const vnx::request_id_t& request_id)
{
	auto ex = vnx::Exception::create();
	ex->what = "receive timeout";
	vnx_async_callback(request_id, ex);
}


} // usboard
} // pilot
