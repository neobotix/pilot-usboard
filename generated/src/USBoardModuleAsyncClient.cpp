
// AUTO GENERATED by vnxcppcodegen

#include <vnx/vnx.h>
#include <pilot/usboard/package.hxx>
#include <pilot/usboard/USBoardModuleAsyncClient.hxx>
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

USBoardModuleAsyncClient::USBoardModuleAsyncClient(const std::string& service_name)
	:	AsyncClient::AsyncClient(vnx::Hash64(service_name))
{
}

USBoardModuleAsyncClient::USBoardModuleAsyncClient(vnx::Hash64 service_addr)
	:	AsyncClient::AsyncClient(service_addr)
{
}

uint64_t USBoardModuleAsyncClient::get_config(const std::function<void(std::shared_ptr<const ::pilot::usboard::USBoardConfig>)>& _callback, const std::function<void(const std::exception&)>& _error_callback) {
	auto _method = ::pilot::usboard::USBoardModule_get_config::create();
	const auto _request_id = vnx_request(_method);
	vnx_queue_get_config[_request_id] = std::make_pair(_callback, _error_callback);
	vnx_num_pending++;
	return _request_id;
}

uint64_t USBoardModuleAsyncClient::is_connected(const std::function<void(vnx::bool_t)>& _callback, const std::function<void(const std::exception&)>& _error_callback) {
	auto _method = ::pilot::usboard::USBoardModule_is_connected::create();
	const auto _request_id = vnx_request(_method);
	vnx_queue_is_connected[_request_id] = std::make_pair(_callback, _error_callback);
	vnx_num_pending++;
	return _request_id;
}

uint64_t USBoardModuleAsyncClient::request_analog_data(const std::function<void()>& _callback, const std::function<void(const std::exception&)>& _error_callback) {
	auto _method = ::pilot::usboard::USBoardModule_request_analog_data::create();
	const auto _request_id = vnx_request(_method);
	vnx_queue_request_analog_data[_request_id] = std::make_pair(_callback, _error_callback);
	vnx_num_pending++;
	return _request_id;
}

uint64_t USBoardModuleAsyncClient::request_config(const std::function<void()>& _callback, const std::function<void(const std::exception&)>& _error_callback) {
	auto _method = ::pilot::usboard::USBoardModule_request_config::create();
	const auto _request_id = vnx_request(_method);
	vnx_queue_request_config[_request_id] = std::make_pair(_callback, _error_callback);
	vnx_num_pending++;
	return _request_id;
}

uint64_t USBoardModuleAsyncClient::request_data(const std::vector<vnx::bool_t>& groups, const std::function<void()>& _callback, const std::function<void(const std::exception&)>& _error_callback) {
	auto _method = ::pilot::usboard::USBoardModule_request_data::create();
	_method->groups = groups;
	const auto _request_id = vnx_request(_method);
	vnx_queue_request_data[_request_id] = std::make_pair(_callback, _error_callback);
	vnx_num_pending++;
	return _request_id;
}

uint64_t USBoardModuleAsyncClient::save_config(const std::shared_ptr<const ::pilot::usboard::USBoardConfig>& config, const std::function<void()>& _callback, const std::function<void(const std::exception&)>& _error_callback) {
	auto _method = ::pilot::usboard::USBoardModule_save_config::create();
	_method->config = config;
	const auto _request_id = vnx_request(_method);
	vnx_queue_save_config[_request_id] = std::make_pair(_callback, _error_callback);
	vnx_num_pending++;
	return _request_id;
}

uint64_t USBoardModuleAsyncClient::send_config(const std::shared_ptr<const ::pilot::usboard::USBoardConfig>& config, const std::function<void()>& _callback, const std::function<void(const std::exception&)>& _error_callback) {
	auto _method = ::pilot::usboard::USBoardModule_send_config::create();
	_method->config = config;
	const auto _request_id = vnx_request(_method);
	vnx_queue_send_config[_request_id] = std::make_pair(_callback, _error_callback);
	vnx_num_pending++;
	return _request_id;
}

uint64_t USBoardModuleAsyncClient::set_channel_active(const std::vector<vnx::bool_t>& sensors, const std::function<void()>& _callback, const std::function<void(const std::exception&)>& _error_callback) {
	auto _method = ::pilot::usboard::USBoardModule_set_channel_active::create();
	_method->sensors = sensors;
	const auto _request_id = vnx_request(_method);
	vnx_queue_set_channel_active[_request_id] = std::make_pair(_callback, _error_callback);
	vnx_num_pending++;
	return _request_id;
}

std::vector<uint64_t> USBoardModuleAsyncClient::vnx_get_pending_ids() const {
	std::vector<uint64_t> _list;
	for(const auto& entry : vnx_queue_get_config) {
		_list.push_back(entry.first);
	}
	for(const auto& entry : vnx_queue_is_connected) {
		_list.push_back(entry.first);
	}
	for(const auto& entry : vnx_queue_request_analog_data) {
		_list.push_back(entry.first);
	}
	for(const auto& entry : vnx_queue_request_config) {
		_list.push_back(entry.first);
	}
	for(const auto& entry : vnx_queue_request_data) {
		_list.push_back(entry.first);
	}
	for(const auto& entry : vnx_queue_save_config) {
		_list.push_back(entry.first);
	}
	for(const auto& entry : vnx_queue_send_config) {
		_list.push_back(entry.first);
	}
	for(const auto& entry : vnx_queue_set_channel_active) {
		_list.push_back(entry.first);
	}
	return _list;
}

void USBoardModuleAsyncClient::vnx_purge_request(uint64_t _request_id, const std::exception& _ex) {
	{
		const auto _iter = vnx_queue_get_config.find(_request_id);
		if(_iter != vnx_queue_get_config.end()) {
			if(_iter->second.second) {
				_iter->second.second(_ex);
			}
			vnx_queue_get_config.erase(_iter);
			vnx_num_pending--;
		}
	}
	{
		const auto _iter = vnx_queue_is_connected.find(_request_id);
		if(_iter != vnx_queue_is_connected.end()) {
			if(_iter->second.second) {
				_iter->second.second(_ex);
			}
			vnx_queue_is_connected.erase(_iter);
			vnx_num_pending--;
		}
	}
	{
		const auto _iter = vnx_queue_request_analog_data.find(_request_id);
		if(_iter != vnx_queue_request_analog_data.end()) {
			if(_iter->second.second) {
				_iter->second.second(_ex);
			}
			vnx_queue_request_analog_data.erase(_iter);
			vnx_num_pending--;
		}
	}
	{
		const auto _iter = vnx_queue_request_config.find(_request_id);
		if(_iter != vnx_queue_request_config.end()) {
			if(_iter->second.second) {
				_iter->second.second(_ex);
			}
			vnx_queue_request_config.erase(_iter);
			vnx_num_pending--;
		}
	}
	{
		const auto _iter = vnx_queue_request_data.find(_request_id);
		if(_iter != vnx_queue_request_data.end()) {
			if(_iter->second.second) {
				_iter->second.second(_ex);
			}
			vnx_queue_request_data.erase(_iter);
			vnx_num_pending--;
		}
	}
	{
		const auto _iter = vnx_queue_save_config.find(_request_id);
		if(_iter != vnx_queue_save_config.end()) {
			if(_iter->second.second) {
				_iter->second.second(_ex);
			}
			vnx_queue_save_config.erase(_iter);
			vnx_num_pending--;
		}
	}
	{
		const auto _iter = vnx_queue_send_config.find(_request_id);
		if(_iter != vnx_queue_send_config.end()) {
			if(_iter->second.second) {
				_iter->second.second(_ex);
			}
			vnx_queue_send_config.erase(_iter);
			vnx_num_pending--;
		}
	}
	{
		const auto _iter = vnx_queue_set_channel_active.find(_request_id);
		if(_iter != vnx_queue_set_channel_active.end()) {
			if(_iter->second.second) {
				_iter->second.second(_ex);
			}
			vnx_queue_set_channel_active.erase(_iter);
			vnx_num_pending--;
		}
	}
}

void USBoardModuleAsyncClient::vnx_callback_switch(uint64_t _request_id, std::shared_ptr<const vnx::Value> _value) {
	const auto _type_hash = _value->get_type_hash();
	if(_type_hash == vnx::Hash64(0x358de7d95fe51641ull)) {
		auto _result = std::dynamic_pointer_cast<const ::pilot::usboard::USBoardModule_get_config_return>(_value);
		if(!_result) {
			throw std::logic_error("USBoardModuleAsyncClient: !_result");
		}
		const auto _iter = vnx_queue_get_config.find(_request_id);
		if(_iter != vnx_queue_get_config.end()) {
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_get_config.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback(_result->_ret_0);
			}
		} else {
			throw std::runtime_error("USBoardModuleAsyncClient: invalid return received");
		}
	}
	else if(_type_hash == vnx::Hash64(0x9f92f79790f0b41cull)) {
		auto _result = std::dynamic_pointer_cast<const ::pilot::usboard::USBoardModule_is_connected_return>(_value);
		if(!_result) {
			throw std::logic_error("USBoardModuleAsyncClient: !_result");
		}
		const auto _iter = vnx_queue_is_connected.find(_request_id);
		if(_iter != vnx_queue_is_connected.end()) {
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_is_connected.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback(_result->_ret_0);
			}
		} else {
			throw std::runtime_error("USBoardModuleAsyncClient: invalid return received");
		}
	}
	else if(_type_hash == vnx::Hash64(0xb138d24fde224a5cull)) {
		const auto _iter = vnx_queue_request_analog_data.find(_request_id);
		if(_iter != vnx_queue_request_analog_data.end()) {
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_request_analog_data.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback();
			}
		} else {
			throw std::runtime_error("USBoardModuleAsyncClient: invalid return received");
		}
	}
	else if(_type_hash == vnx::Hash64(0x33da5f4894481a92ull)) {
		const auto _iter = vnx_queue_request_config.find(_request_id);
		if(_iter != vnx_queue_request_config.end()) {
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_request_config.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback();
			}
		} else {
			throw std::runtime_error("USBoardModuleAsyncClient: invalid return received");
		}
	}
	else if(_type_hash == vnx::Hash64(0xb6a4183451605df3ull)) {
		const auto _iter = vnx_queue_request_data.find(_request_id);
		if(_iter != vnx_queue_request_data.end()) {
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_request_data.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback();
			}
		} else {
			throw std::runtime_error("USBoardModuleAsyncClient: invalid return received");
		}
	}
	else if(_type_hash == vnx::Hash64(0x4a4217094e238854ull)) {
		const auto _iter = vnx_queue_save_config.find(_request_id);
		if(_iter != vnx_queue_save_config.end()) {
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_save_config.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback();
			}
		} else {
			throw std::runtime_error("USBoardModuleAsyncClient: invalid return received");
		}
	}
	else if(_type_hash == vnx::Hash64(0xf264043ea1b4721dull)) {
		const auto _iter = vnx_queue_send_config.find(_request_id);
		if(_iter != vnx_queue_send_config.end()) {
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_send_config.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback();
			}
		} else {
			throw std::runtime_error("USBoardModuleAsyncClient: invalid return received");
		}
	}
	else if(_type_hash == vnx::Hash64(0x7cba331721c32a6ull)) {
		const auto _iter = vnx_queue_set_channel_active.find(_request_id);
		if(_iter != vnx_queue_set_channel_active.end()) {
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_set_channel_active.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback();
			}
		} else {
			throw std::runtime_error("USBoardModuleAsyncClient: invalid return received");
		}
	}
	else {
		throw std::runtime_error("USBoardModuleAsyncClient: unknown return type");
	}
}


} // namespace pilot
} // namespace usboard
