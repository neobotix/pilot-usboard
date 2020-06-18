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
	return true;
}

void USBoardModule::request_config()
{
	// TODO
}

void USBoardModule::request_data(const int32_t& group_set)
{
	// TODO
}

void USBoardModule::save_config()
{
	// TODO
}

void USBoardModule::set_config(const std::shared_ptr<const USBoardConfig>& config)
{
	m_config = config;
	// TODO: send to board
}


} // usboard
} // pilot
