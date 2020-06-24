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
	// TODO
}

void USBoardModule::request_data(const std::vector<vnx::bool_t>& groups)
{
	// TODO
}

void USBoardModule::request_analog_data()
{
	// TODO
}

void USBoardModule::send_config_async(	const std::shared_ptr<const USBoardConfig>& config,
										const vnx::request_id_t& request_id)
{
	throw std::logic_error("not implemented yet");
	// TODO: send to board and wait for return
	m_config = config;
	send_config_async_return(request_id);
}

void USBoardModule::save_config_async(	const std::shared_ptr<const USBoardConfig>& config,
										const vnx::request_id_t& request_id)
{
	throw std::logic_error("not implemented yet");
	// TODO: send to board and wait for return
	save_config_async_return(request_id);
}

void USBoardModule::set_channel_active(const std::vector<vnx::bool_t>& sensors)
{
	// TODO
	throw std::logic_error("not implemented yet");
}


} // usboard
} // pilot
