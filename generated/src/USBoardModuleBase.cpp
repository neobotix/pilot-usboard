
// AUTO GENERATED by vnxcppcodegen

#include <pilot/usboard/package.hxx>
#include <pilot/usboard/USBoardModuleBase.hxx>
#include <vnx/NoSuchMethod.hxx>
#include <pilot/base/CAN_Frame.hxx>
#include <pilot/base/DataPacket.hxx>
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
#include <vnx/ModuleInterface_vnx_get_config.hxx>
#include <vnx/ModuleInterface_vnx_get_config_return.hxx>
#include <vnx/ModuleInterface_vnx_get_config_object.hxx>
#include <vnx/ModuleInterface_vnx_get_config_object_return.hxx>
#include <vnx/ModuleInterface_vnx_get_module_info.hxx>
#include <vnx/ModuleInterface_vnx_get_module_info_return.hxx>
#include <vnx/ModuleInterface_vnx_get_type_code.hxx>
#include <vnx/ModuleInterface_vnx_get_type_code_return.hxx>
#include <vnx/ModuleInterface_vnx_restart.hxx>
#include <vnx/ModuleInterface_vnx_restart_return.hxx>
#include <vnx/ModuleInterface_vnx_self_test.hxx>
#include <vnx/ModuleInterface_vnx_self_test_return.hxx>
#include <vnx/ModuleInterface_vnx_set_config.hxx>
#include <vnx/ModuleInterface_vnx_set_config_return.hxx>
#include <vnx/ModuleInterface_vnx_set_config_object.hxx>
#include <vnx/ModuleInterface_vnx_set_config_object_return.hxx>
#include <vnx/ModuleInterface_vnx_stop.hxx>
#include <vnx/ModuleInterface_vnx_stop_return.hxx>
#include <vnx/TopicPtr.hpp>

#include <vnx/vnx.h>


namespace pilot {
namespace usboard {


const vnx::Hash64 USBoardModuleBase::VNX_TYPE_HASH(0x43f03ccffe42b23full);
const vnx::Hash64 USBoardModuleBase::VNX_CODE_HASH(0xc6f2a8b94f01f5d6ull);

USBoardModuleBase::USBoardModuleBase(const std::string& _vnx_name)
	:	Module::Module(_vnx_name)
{
	vnx::read_config(vnx_name + ".input_can", input_can);
	vnx::read_config(vnx_name + ".input_serial", input_serial);
	vnx::read_config(vnx_name + ".topic_can_request", topic_can_request);
	vnx::read_config(vnx_name + ".topic_serial_request", topic_serial_request);
	vnx::read_config(vnx_name + ".output_data", output_data);
	vnx::read_config(vnx_name + ".output_config", output_config);
	vnx::read_config(vnx_name + ".config_file", config_file);
	vnx::read_config(vnx_name + ".can_id", can_id);
	vnx::read_config(vnx_name + ".connect_interval_ms", connect_interval_ms);
	vnx::read_config(vnx_name + ".write_timeout_ms", write_timeout_ms);
}

vnx::Hash64 USBoardModuleBase::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string USBoardModuleBase::get_type_name() const {
	return "pilot.usboard.USBoardModule";
}

const vnx::TypeCode* USBoardModuleBase::get_type_code() const {
	return pilot::usboard::vnx_native_type_code_USBoardModuleBase;
}

void USBoardModuleBase::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = pilot::usboard::vnx_native_type_code_USBoardModuleBase;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, input_can);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, input_serial);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, topic_can_request);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, topic_serial_request);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, output_data);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, output_config);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, config_file);
	_visitor.type_field(_type_code->fields[7], 7); vnx::accept(_visitor, can_id);
	_visitor.type_field(_type_code->fields[8], 8); vnx::accept(_visitor, connect_interval_ms);
	_visitor.type_field(_type_code->fields[9], 9); vnx::accept(_visitor, write_timeout_ms);
	_visitor.type_end(*_type_code);
}

void USBoardModuleBase::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"input_can\": "; vnx::write(_out, input_can);
	_out << ", \"input_serial\": "; vnx::write(_out, input_serial);
	_out << ", \"topic_can_request\": "; vnx::write(_out, topic_can_request);
	_out << ", \"topic_serial_request\": "; vnx::write(_out, topic_serial_request);
	_out << ", \"output_data\": "; vnx::write(_out, output_data);
	_out << ", \"output_config\": "; vnx::write(_out, output_config);
	_out << ", \"config_file\": "; vnx::write(_out, config_file);
	_out << ", \"can_id\": "; vnx::write(_out, can_id);
	_out << ", \"connect_interval_ms\": "; vnx::write(_out, connect_interval_ms);
	_out << ", \"write_timeout_ms\": "; vnx::write(_out, write_timeout_ms);
	_out << "}";
}

void USBoardModuleBase::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object USBoardModuleBase::to_object() const {
	vnx::Object _object;
	_object["__type"] = "pilot.usboard.USBoardModule";
	_object["input_can"] = input_can;
	_object["input_serial"] = input_serial;
	_object["topic_can_request"] = topic_can_request;
	_object["topic_serial_request"] = topic_serial_request;
	_object["output_data"] = output_data;
	_object["output_config"] = output_config;
	_object["config_file"] = config_file;
	_object["can_id"] = can_id;
	_object["connect_interval_ms"] = connect_interval_ms;
	_object["write_timeout_ms"] = write_timeout_ms;
	return _object;
}

void USBoardModuleBase::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "can_id") {
			_entry.second.to(can_id);
		} else if(_entry.first == "config_file") {
			_entry.second.to(config_file);
		} else if(_entry.first == "connect_interval_ms") {
			_entry.second.to(connect_interval_ms);
		} else if(_entry.first == "input_can") {
			_entry.second.to(input_can);
		} else if(_entry.first == "input_serial") {
			_entry.second.to(input_serial);
		} else if(_entry.first == "output_config") {
			_entry.second.to(output_config);
		} else if(_entry.first == "output_data") {
			_entry.second.to(output_data);
		} else if(_entry.first == "topic_can_request") {
			_entry.second.to(topic_can_request);
		} else if(_entry.first == "topic_serial_request") {
			_entry.second.to(topic_serial_request);
		} else if(_entry.first == "write_timeout_ms") {
			_entry.second.to(write_timeout_ms);
		}
	}
}

vnx::Variant USBoardModuleBase::get_field(const std::string& _name) const {
	if(_name == "input_can") {
		return vnx::Variant(input_can);
	}
	if(_name == "input_serial") {
		return vnx::Variant(input_serial);
	}
	if(_name == "topic_can_request") {
		return vnx::Variant(topic_can_request);
	}
	if(_name == "topic_serial_request") {
		return vnx::Variant(topic_serial_request);
	}
	if(_name == "output_data") {
		return vnx::Variant(output_data);
	}
	if(_name == "output_config") {
		return vnx::Variant(output_config);
	}
	if(_name == "config_file") {
		return vnx::Variant(config_file);
	}
	if(_name == "can_id") {
		return vnx::Variant(can_id);
	}
	if(_name == "connect_interval_ms") {
		return vnx::Variant(connect_interval_ms);
	}
	if(_name == "write_timeout_ms") {
		return vnx::Variant(write_timeout_ms);
	}
	return vnx::Variant();
}

void USBoardModuleBase::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "input_can") {
		_value.to(input_can);
	} else if(_name == "input_serial") {
		_value.to(input_serial);
	} else if(_name == "topic_can_request") {
		_value.to(topic_can_request);
	} else if(_name == "topic_serial_request") {
		_value.to(topic_serial_request);
	} else if(_name == "output_data") {
		_value.to(output_data);
	} else if(_name == "output_config") {
		_value.to(output_config);
	} else if(_name == "config_file") {
		_value.to(config_file);
	} else if(_name == "can_id") {
		_value.to(can_id);
	} else if(_name == "connect_interval_ms") {
		_value.to(connect_interval_ms);
	} else if(_name == "write_timeout_ms") {
		_value.to(write_timeout_ms);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const USBoardModuleBase& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, USBoardModuleBase& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* USBoardModuleBase::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> USBoardModuleBase::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "pilot.usboard.USBoardModule";
	type_code->type_hash = vnx::Hash64(0x43f03ccffe42b23full);
	type_code->code_hash = vnx::Hash64(0xc6f2a8b94f01f5d6ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::pilot::usboard::USBoardModuleBase);
	type_code->methods.resize(17);
	type_code->methods[0] = ::vnx::ModuleInterface_vnx_get_config_object::static_get_type_code();
	type_code->methods[1] = ::vnx::ModuleInterface_vnx_get_config::static_get_type_code();
	type_code->methods[2] = ::vnx::ModuleInterface_vnx_set_config_object::static_get_type_code();
	type_code->methods[3] = ::vnx::ModuleInterface_vnx_set_config::static_get_type_code();
	type_code->methods[4] = ::vnx::ModuleInterface_vnx_get_type_code::static_get_type_code();
	type_code->methods[5] = ::vnx::ModuleInterface_vnx_get_module_info::static_get_type_code();
	type_code->methods[6] = ::vnx::ModuleInterface_vnx_restart::static_get_type_code();
	type_code->methods[7] = ::vnx::ModuleInterface_vnx_stop::static_get_type_code();
	type_code->methods[8] = ::vnx::ModuleInterface_vnx_self_test::static_get_type_code();
	type_code->methods[9] = ::pilot::usboard::USBoardModule_is_connected::static_get_type_code();
	type_code->methods[10] = ::pilot::usboard::USBoardModule_request_data::static_get_type_code();
	type_code->methods[11] = ::pilot::usboard::USBoardModule_request_analog_data::static_get_type_code();
	type_code->methods[12] = ::pilot::usboard::USBoardModule_request_config::static_get_type_code();
	type_code->methods[13] = ::pilot::usboard::USBoardModule_get_config::static_get_type_code();
	type_code->methods[14] = ::pilot::usboard::USBoardModule_set_channel_active::static_get_type_code();
	type_code->methods[15] = ::pilot::usboard::USBoardModule_send_config::static_get_type_code();
	type_code->methods[16] = ::pilot::usboard::USBoardModule_save_config::static_get_type_code();
	type_code->fields.resize(10);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "input_can";
		field.code = {12, 5};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "input_serial";
		field.code = {12, 5};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "topic_can_request";
		field.code = {12, 5};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "topic_serial_request";
		field.code = {12, 5};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "output_data";
		field.code = {12, 5};
	}
	{
		auto& field = type_code->fields[5];
		field.is_extended = true;
		field.name = "output_config";
		field.code = {12, 5};
	}
	{
		auto& field = type_code->fields[6];
		field.is_extended = true;
		field.name = "config_file";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[7];
		field.data_size = 4;
		field.name = "can_id";
		field.value = vnx::to_string(1024);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[8];
		field.data_size = 4;
		field.name = "connect_interval_ms";
		field.value = vnx::to_string(1000);
		field.code = {7};
	}
	{
		auto& field = type_code->fields[9];
		field.data_size = 4;
		field.name = "write_timeout_ms";
		field.value = vnx::to_string(10000);
		field.code = {7};
	}
	type_code->build();
	return type_code;
}

void USBoardModuleBase::vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) {
	const auto* _type_code = _value->get_type_code();
	while(_type_code) {
		switch(_type_code->type_hash) {
			case 0x4d70a2725dc4def6ull:
				handle(std::static_pointer_cast<const ::pilot::base::CAN_Frame>(_value));
				return;
			case 0xcd0d2bd202ac0fb0ull:
				handle(std::static_pointer_cast<const ::pilot::base::DataPacket>(_value));
				return;
			default:
				_type_code = _type_code->super;
		}
	}
	handle(std::static_pointer_cast<const vnx::Value>(_value));
}

std::shared_ptr<vnx::Value> USBoardModuleBase::vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) {
	switch(_method->get_type_hash()) {
		case 0x17f58f68bf83abc0ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_object>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_config_object_return::create();
			_return_value->_ret_0 = vnx_get_config_object();
			return _return_value;
		}
		case 0xbbc7f1a01044d294ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_config_return::create();
			_return_value->_ret_0 = vnx_get_config(_args->name);
			return _return_value;
		}
		case 0xca30f814f17f322full: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_set_config_object>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_set_config_object_return::create();
			vnx_set_config_object(_args->config);
			return _return_value;
		}
		case 0x362aac91373958b7ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_set_config>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_set_config_return::create();
			vnx_set_config(_args->name, _args->value);
			return _return_value;
		}
		case 0x305ec4d628960e5dull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_type_code>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_type_code_return::create();
			_return_value->_ret_0 = vnx_get_type_code();
			return _return_value;
		}
		case 0xf6d82bdf66d034a1ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_module_info>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_module_info_return::create();
			_return_value->_ret_0 = vnx_get_module_info();
			return _return_value;
		}
		case 0x9e95dc280cecca1bull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_restart>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_restart_return::create();
			vnx_restart();
			return _return_value;
		}
		case 0x7ab49ce3d1bfc0d2ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_stop>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_stop_return::create();
			vnx_stop();
			return _return_value;
		}
		case 0x6ce3775b41a42697ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_self_test>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_self_test_return::create();
			_return_value->_ret_0 = vnx_self_test();
			return _return_value;
		}
		case 0x67dc4b6f55cdaf01ull: {
			auto _args = std::static_pointer_cast<const ::pilot::usboard::USBoardModule_is_connected>(_method);
			auto _return_value = ::pilot::usboard::USBoardModule_is_connected_return::create();
			_return_value->_ret_0 = is_connected();
			return _return_value;
		}
		case 0xc7bf45418c654bbfull: {
			auto _args = std::static_pointer_cast<const ::pilot::usboard::USBoardModule_request_data>(_method);
			auto _return_value = ::pilot::usboard::USBoardModule_request_data_return::create();
			request_data(_args->groups);
			return _return_value;
		}
		case 0x623eabf252eec344ull: {
			auto _args = std::static_pointer_cast<const ::pilot::usboard::USBoardModule_request_analog_data>(_method);
			auto _return_value = ::pilot::usboard::USBoardModule_request_analog_data_return::create();
			request_analog_data();
			return _return_value;
		}
		case 0xf38e6a2521f9f008ull: {
			auto _args = std::static_pointer_cast<const ::pilot::usboard::USBoardModule_request_config>(_method);
			auto _return_value = ::pilot::usboard::USBoardModule_request_config_return::create();
			request_config();
			return _return_value;
		}
		case 0xe7bebc86c32def4eull: {
			auto _args = std::static_pointer_cast<const ::pilot::usboard::USBoardModule_get_config>(_method);
			auto _return_value = ::pilot::usboard::USBoardModule_get_config_return::create();
			_return_value->_ret_0 = get_config();
			return _return_value;
		}
		case 0x4d5fe6cf9c152a42ull: {
			auto _args = std::static_pointer_cast<const ::pilot::usboard::USBoardModule_set_channel_active>(_method);
			auto _return_value = ::pilot::usboard::USBoardModule_set_channel_active_return::create();
			set_channel_active(_args->sensors);
			return _return_value;
		}
		case 0xc95ed3ee2bff3228ull: {
			auto _args = std::static_pointer_cast<const ::pilot::usboard::USBoardModule_send_config>(_method);
			send_config_async(_args->config, _request_id);
			return nullptr;
		}
		case 0xc5d8f1fd2323ac3bull: {
			auto _args = std::static_pointer_cast<const ::pilot::usboard::USBoardModule_save_config>(_method);
			save_config_async(_args->config, _request_id);
			return nullptr;
		}
	}
	auto _ex = vnx::NoSuchMethod::create();
	_ex->dst_mac = vnx_request ? vnx_request->dst_mac : vnx::Hash64();
	_ex->method = _method->get_type_name();
	return _ex;
}

void USBoardModuleBase::send_config_async_return(const vnx::request_id_t& _request_id) const {
	auto _return_value = ::pilot::usboard::USBoardModule_send_config_return::create();
	vnx_async_return(_request_id, _return_value);
}

void USBoardModuleBase::save_config_async_return(const vnx::request_id_t& _request_id) const {
	auto _return_value = ::pilot::usboard::USBoardModule_save_config_return::create();
	vnx_async_return(_request_id, _return_value);
}


} // namespace pilot
} // namespace usboard


namespace vnx {

void read(TypeInput& in, ::pilot::usboard::USBoardModuleBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		switch(code[0]) {
			case CODE_OBJECT:
			case CODE_ALT_OBJECT: {
				Object tmp;
				vnx::read(in, tmp, type_code, code);
				value.from_object(tmp);
				return;
			}
			case CODE_DYNAMIC:
			case CODE_ALT_DYNAMIC:
				vnx::read_dynamic(in, value);
				return;
		}
	}
	if(!type_code) {
		vnx::skip(in, type_code, code);
		return;
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: {
				vnx::skip(in, type_code, code);
				return;
			}
		}
	}
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[7]) {
			vnx::read_value(_buf + _field->offset, value.can_id, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[8]) {
			vnx::read_value(_buf + _field->offset, value.connect_interval_ms, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[9]) {
			vnx::read_value(_buf + _field->offset, value.write_timeout_ms, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.input_can, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.input_serial, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.topic_can_request, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.topic_serial_request, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.output_data, type_code, _field->code.data()); break;
			case 5: vnx::read(in, value.output_config, type_code, _field->code.data()); break;
			case 6: vnx::read(in, value.config_file, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::pilot::usboard::USBoardModuleBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = pilot::usboard::vnx_native_type_code_USBoardModuleBase;
		out.write_type_code(type_code);
		vnx::write_class_header<::pilot::usboard::USBoardModuleBase>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(12);
	vnx::write_value(_buf + 0, value.can_id);
	vnx::write_value(_buf + 4, value.connect_interval_ms);
	vnx::write_value(_buf + 8, value.write_timeout_ms);
	vnx::write(out, value.input_can, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.input_serial, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.topic_can_request, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.topic_serial_request, type_code, type_code->fields[3].code.data());
	vnx::write(out, value.output_data, type_code, type_code->fields[4].code.data());
	vnx::write(out, value.output_config, type_code, type_code->fields[5].code.data());
	vnx::write(out, value.config_file, type_code, type_code->fields[6].code.data());
}

void read(std::istream& in, ::pilot::usboard::USBoardModuleBase& value) {
	value.read(in);
}

void write(std::ostream& out, const ::pilot::usboard::USBoardModuleBase& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::pilot::usboard::USBoardModuleBase& value) {
	value.accept(visitor);
}

} // vnx
