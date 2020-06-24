
// AUTO GENERATED by vnxcppcodegen

#include <vnx/vnx.h>
#include <pilot/usboard/package.hxx>
#include <pilot/usboard/USBoardModuleClient.hxx>
#include <pilot/usboard/USBoardConfig.hxx>
#include <pilot/usboard/USBoardModule_get_config.hxx>
#include <pilot/usboard/USBoardModule_get_config_return.hxx>
#include <pilot/usboard/USBoardModule_is_connected.hxx>
#include <pilot/usboard/USBoardModule_is_connected_return.hxx>
#include <pilot/usboard/USBoardModule_request_analog_data.hxx>
#include <pilot/usboard/USBoardModule_request_analog_data_return.hxx>
#include <pilot/usboard/USBoardModule_request_config.hxx>
#include <pilot/usboard/USBoardModule_request_config_return.hxx>
#include <pilot/usboard/USBoardModule_request_data.hxx>
#include <pilot/usboard/USBoardModule_request_data_return.hxx>
#include <pilot/usboard/USBoardModule_save_config.hxx>
#include <pilot/usboard/USBoardModule_save_config_return.hxx>
#include <pilot/usboard/USBoardModule_send_config.hxx>
#include <pilot/usboard/USBoardModule_send_config_return.hxx>
#include <pilot/usboard/USBoardModule_set_channel_active.hxx>
#include <pilot/usboard/USBoardModule_set_channel_active_return.hxx>
#include <vnx/Module.h>
#include <vnx/TopicPtr.hpp>



namespace pilot {
namespace usboard {

USBoardModuleClient::USBoardModuleClient(const std::string& service_name)
	:	Client::Client(vnx::Hash64(service_name))
{
}

USBoardModuleClient::USBoardModuleClient(vnx::Hash64 service_addr)
	:	Client::Client(service_addr)
{
}

std::shared_ptr<const ::pilot::usboard::USBoardConfig> USBoardModuleClient::get_config() {
	auto _method = ::pilot::usboard::USBoardModule_get_config::create();
	auto _return_value = vnx_request(_method);
	auto _result = std::dynamic_pointer_cast<const ::pilot::usboard::USBoardModule_get_config_return>(_return_value);
	if(!_result) {
		throw std::logic_error("USBoardModuleClient: !_result");
	}
	return _result->_ret_0;
}

vnx::bool_t USBoardModuleClient::is_connected() {
	auto _method = ::pilot::usboard::USBoardModule_is_connected::create();
	auto _return_value = vnx_request(_method);
	auto _result = std::dynamic_pointer_cast<const ::pilot::usboard::USBoardModule_is_connected_return>(_return_value);
	if(!_result) {
		throw std::logic_error("USBoardModuleClient: !_result");
	}
	return _result->_ret_0;
}

void USBoardModuleClient::request_analog_data() {
	auto _method = ::pilot::usboard::USBoardModule_request_analog_data::create();
	auto _return_value = vnx_request(_method);
}

void USBoardModuleClient::request_analog_data_async() {
	vnx_is_async = true;
	request_analog_data();
}

void USBoardModuleClient::request_config() {
	auto _method = ::pilot::usboard::USBoardModule_request_config::create();
	auto _return_value = vnx_request(_method);
}

void USBoardModuleClient::request_config_async() {
	vnx_is_async = true;
	request_config();
}

void USBoardModuleClient::request_data(const int32_t& group_set) {
	auto _method = ::pilot::usboard::USBoardModule_request_data::create();
	_method->group_set = group_set;
	auto _return_value = vnx_request(_method);
}

void USBoardModuleClient::request_data_async(const int32_t& group_set) {
	vnx_is_async = true;
	request_data(group_set);
}

void USBoardModuleClient::save_config() {
	auto _method = ::pilot::usboard::USBoardModule_save_config::create();
	auto _return_value = vnx_request(_method);
}

void USBoardModuleClient::save_config_async() {
	vnx_is_async = true;
	save_config();
}

void USBoardModuleClient::send_config(const std::shared_ptr<const ::pilot::usboard::USBoardConfig>& config) {
	auto _method = ::pilot::usboard::USBoardModule_send_config::create();
	_method->config = config;
	auto _return_value = vnx_request(_method);
}

void USBoardModuleClient::send_config_async(const std::shared_ptr<const ::pilot::usboard::USBoardConfig>& config) {
	vnx_is_async = true;
	send_config(config);
}

void USBoardModuleClient::set_channel_active(const std::vector<vnx::bool_t>& sensors) {
	auto _method = ::pilot::usboard::USBoardModule_set_channel_active::create();
	_method->sensors = sensors;
	auto _return_value = vnx_request(_method);
}

void USBoardModuleClient::set_channel_active_async(const std::vector<vnx::bool_t>& sensors) {
	vnx_is_async = true;
	set_channel_active(sensors);
}


} // namespace pilot
} // namespace usboard
