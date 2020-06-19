
// AUTO GENERATED by vnxcppcodegen

#include <vnx/vnx.h>
#include <pilot/usboard/package.hxx>
#include <pilot/usboard/USBoardConfig.hxx>
#include <pilot/base/CAN_Frame.hxx>
#include <pilot/usboard/group_config_t.hxx>
#include <pilot/usboard/sensor_config_t.hxx>
#include <vnx/Value.h>



namespace pilot {
namespace usboard {

const int32_t USBoardConfig::SENSOR_SETUP_4;
const int32_t USBoardConfig::SENSOR_SETUP_8;
const int32_t USBoardConfig::SENSOR_SETUP_16;
const int32_t USBoardConfig::TRANSMIT_MODE_REQUEST;
const int32_t USBoardConfig::TRANSMIT_MODE_CAN;
const int32_t USBoardConfig::TRANSMIT_MODE_SERIAL;
const int32_t USBoardConfig::TRANSMIT_MODE_CAN_SERIAL;

const vnx::Hash64 USBoardConfig::VNX_TYPE_HASH(0x9c0fb140354b6e4cull);
const vnx::Hash64 USBoardConfig::VNX_CODE_HASH(0xabdc1ad7b9846597ull);

vnx::Hash64 USBoardConfig::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* USBoardConfig::get_type_name() const {
	return "pilot.usboard.USBoardConfig";
}
const vnx::TypeCode* USBoardConfig::get_type_code() const {
	return pilot::usboard::vnx_native_type_code_USBoardConfig;
}

std::shared_ptr<USBoardConfig> USBoardConfig::create() {
	return std::make_shared<USBoardConfig>();
}

std::shared_ptr<vnx::Value> USBoardConfig::clone() const {
	return std::make_shared<USBoardConfig>(*this);
}

void USBoardConfig::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void USBoardConfig::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void USBoardConfig::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = pilot::usboard::vnx_native_type_code_USBoardConfig;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, serial_number);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, can_id);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, can_baudrate);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, update_interval_ms);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, sensor_setup);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, transmit_mode);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, sensor_config);
	_visitor.type_field(_type_code->fields[7], 7); vnx::accept(_visitor, group_config);
	_visitor.type_field(_type_code->fields[8], 8); vnx::accept(_visitor, low_pass_gain);
	_visitor.type_field(_type_code->fields[9], 9); vnx::accept(_visitor, enable_analog_input);
	_visitor.type_field(_type_code->fields[10], 10); vnx::accept(_visitor, enable_legacy_format);
	_visitor.type_field(_type_code->fields[11], 11); vnx::accept(_visitor, enable_can_termination);
	_visitor.type_end(*_type_code);
}

void USBoardConfig::write(std::ostream& _out) const {
	_out << "{\"__type\": \"pilot.usboard.USBoardConfig\"";
	_out << ", \"serial_number\": "; vnx::write(_out, serial_number);
	_out << ", \"can_id\": "; vnx::write(_out, can_id);
	_out << ", \"can_baudrate\": "; vnx::write(_out, can_baudrate);
	_out << ", \"update_interval_ms\": "; vnx::write(_out, update_interval_ms);
	_out << ", \"sensor_setup\": "; vnx::write(_out, sensor_setup);
	_out << ", \"transmit_mode\": "; vnx::write(_out, transmit_mode);
	_out << ", \"sensor_config\": "; vnx::write(_out, sensor_config);
	_out << ", \"group_config\": "; vnx::write(_out, group_config);
	_out << ", \"low_pass_gain\": "; vnx::write(_out, low_pass_gain);
	_out << ", \"enable_analog_input\": "; vnx::write(_out, enable_analog_input);
	_out << ", \"enable_legacy_format\": "; vnx::write(_out, enable_legacy_format);
	_out << ", \"enable_can_termination\": "; vnx::write(_out, enable_can_termination);
	_out << "}";
}

void USBoardConfig::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "can_baudrate") {
			vnx::from_string(_entry.second, can_baudrate);
		} else if(_entry.first == "can_id") {
			vnx::from_string(_entry.second, can_id);
		} else if(_entry.first == "enable_analog_input") {
			vnx::from_string(_entry.second, enable_analog_input);
		} else if(_entry.first == "enable_can_termination") {
			vnx::from_string(_entry.second, enable_can_termination);
		} else if(_entry.first == "enable_legacy_format") {
			vnx::from_string(_entry.second, enable_legacy_format);
		} else if(_entry.first == "group_config") {
			vnx::from_string(_entry.second, group_config);
		} else if(_entry.first == "low_pass_gain") {
			vnx::from_string(_entry.second, low_pass_gain);
		} else if(_entry.first == "sensor_config") {
			vnx::from_string(_entry.second, sensor_config);
		} else if(_entry.first == "sensor_setup") {
			vnx::from_string(_entry.second, sensor_setup);
		} else if(_entry.first == "serial_number") {
			vnx::from_string(_entry.second, serial_number);
		} else if(_entry.first == "transmit_mode") {
			vnx::from_string(_entry.second, transmit_mode);
		} else if(_entry.first == "update_interval_ms") {
			vnx::from_string(_entry.second, update_interval_ms);
		}
	}
}

vnx::Object USBoardConfig::to_object() const {
	vnx::Object _object;
	_object["__type"] = "pilot.usboard.USBoardConfig";
	_object["serial_number"] = serial_number;
	_object["can_id"] = can_id;
	_object["can_baudrate"] = can_baudrate;
	_object["update_interval_ms"] = update_interval_ms;
	_object["sensor_setup"] = sensor_setup;
	_object["transmit_mode"] = transmit_mode;
	_object["sensor_config"] = sensor_config;
	_object["group_config"] = group_config;
	_object["low_pass_gain"] = low_pass_gain;
	_object["enable_analog_input"] = enable_analog_input;
	_object["enable_legacy_format"] = enable_legacy_format;
	_object["enable_can_termination"] = enable_can_termination;
	return _object;
}

void USBoardConfig::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "can_baudrate") {
			_entry.second.to(can_baudrate);
		} else if(_entry.first == "can_id") {
			_entry.second.to(can_id);
		} else if(_entry.first == "enable_analog_input") {
			_entry.second.to(enable_analog_input);
		} else if(_entry.first == "enable_can_termination") {
			_entry.second.to(enable_can_termination);
		} else if(_entry.first == "enable_legacy_format") {
			_entry.second.to(enable_legacy_format);
		} else if(_entry.first == "group_config") {
			_entry.second.to(group_config);
		} else if(_entry.first == "low_pass_gain") {
			_entry.second.to(low_pass_gain);
		} else if(_entry.first == "sensor_config") {
			_entry.second.to(sensor_config);
		} else if(_entry.first == "sensor_setup") {
			_entry.second.to(sensor_setup);
		} else if(_entry.first == "serial_number") {
			_entry.second.to(serial_number);
		} else if(_entry.first == "transmit_mode") {
			_entry.second.to(transmit_mode);
		} else if(_entry.first == "update_interval_ms") {
			_entry.second.to(update_interval_ms);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const USBoardConfig& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, USBoardConfig& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* USBoardConfig::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> USBoardConfig::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "pilot.usboard.USBoardConfig";
	type_code->type_hash = vnx::Hash64(0x9c0fb140354b6e4cull);
	type_code->code_hash = vnx::Hash64(0xabdc1ad7b9846597ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<USBoardConfig>(); };
	type_code->depends.resize(2);
	type_code->depends[0] = ::pilot::usboard::sensor_config_t::static_get_type_code();
	type_code->depends[1] = ::pilot::usboard::group_config_t::static_get_type_code();
	type_code->fields.resize(12);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "serial_number";
		field.value = vnx::to_string(-1);
		field.code = {7};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.name = "can_id";
		field.value = vnx::to_string(1024);
		field.code = {7};
	}
	{
		vnx::TypeField& field = type_code->fields[2];
		field.name = "can_baudrate";
		field.value = vnx::to_string(1000000);
		field.code = {7};
	}
	{
		vnx::TypeField& field = type_code->fields[3];
		field.name = "update_interval_ms";
		field.value = vnx::to_string(200);
		field.code = {7};
	}
	{
		vnx::TypeField& field = type_code->fields[4];
		field.name = "sensor_setup";
		field.value = vnx::to_string(4);
		field.code = {7};
	}
	{
		vnx::TypeField& field = type_code->fields[5];
		field.name = "transmit_mode";
		field.value = vnx::to_string(1);
		field.code = {7};
	}
	{
		vnx::TypeField& field = type_code->fields[6];
		field.is_extended = true;
		field.name = "sensor_config";
		field.code = {11, 16, 19, 0};
	}
	{
		vnx::TypeField& field = type_code->fields[7];
		field.is_extended = true;
		field.name = "group_config";
		field.code = {11, 4, 19, 1};
	}
	{
		vnx::TypeField& field = type_code->fields[8];
		field.name = "low_pass_gain";
		field.value = vnx::to_string(1);
		field.code = {9};
	}
	{
		vnx::TypeField& field = type_code->fields[9];
		field.name = "enable_analog_input";
		field.value = vnx::to_string(false);
		field.code = {1};
	}
	{
		vnx::TypeField& field = type_code->fields[10];
		field.name = "enable_legacy_format";
		field.value = vnx::to_string(false);
		field.code = {1};
	}
	{
		vnx::TypeField& field = type_code->fields[11];
		field.name = "enable_can_termination";
		field.value = vnx::to_string(false);
		field.code = {1};
	}
	type_code->build();
	return type_code;
}


} // namespace pilot
} // namespace usboard


namespace vnx {

void read(TypeInput& in, ::pilot::usboard::USBoardConfig& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code) {
		throw std::logic_error("read(): type_code == 0");
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: vnx::skip(in, type_code, code); return;
		}
	}
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		{
			const vnx::TypeField* const _field = type_code->field_map[0];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.serial_number, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[1];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.can_id, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[2];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.can_baudrate, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[3];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.update_interval_ms, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[4];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.sensor_setup, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[5];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.transmit_mode, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[8];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.low_pass_gain, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[9];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.enable_analog_input, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[10];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.enable_legacy_format, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[11];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.enable_can_termination, _field->code.data());
			}
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 6: vnx::read(in, value.sensor_config, type_code, _field->code.data()); break;
			case 7: vnx::read(in, value.group_config, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::pilot::usboard::USBoardConfig& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = pilot::usboard::vnx_native_type_code_USBoardConfig;
		out.write_type_code(type_code);
		vnx::write_class_header<::pilot::usboard::USBoardConfig>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(31);
	vnx::write_value(_buf + 0, value.serial_number);
	vnx::write_value(_buf + 4, value.can_id);
	vnx::write_value(_buf + 8, value.can_baudrate);
	vnx::write_value(_buf + 12, value.update_interval_ms);
	vnx::write_value(_buf + 16, value.sensor_setup);
	vnx::write_value(_buf + 20, value.transmit_mode);
	vnx::write_value(_buf + 24, value.low_pass_gain);
	vnx::write_value(_buf + 28, value.enable_analog_input);
	vnx::write_value(_buf + 29, value.enable_legacy_format);
	vnx::write_value(_buf + 30, value.enable_can_termination);
	vnx::write(out, value.sensor_config, type_code, type_code->fields[6].code.data());
	vnx::write(out, value.group_config, type_code, type_code->fields[7].code.data());
}

void read(std::istream& in, ::pilot::usboard::USBoardConfig& value) {
	value.read(in);
}

void write(std::ostream& out, const ::pilot::usboard::USBoardConfig& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::pilot::usboard::USBoardConfig& value) {
	value.accept(visitor);
}

} // vnx
