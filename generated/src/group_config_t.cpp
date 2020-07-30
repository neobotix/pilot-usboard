
// AUTO GENERATED by vnxcppcodegen

#include <pilot/usboard/package.hxx>
#include <pilot/usboard/group_config_t.hxx>

#include <vnx/vnx.h>


namespace pilot {
namespace usboard {

const uint32_t group_config_t::RESOLUTION_0125_CM;
const uint32_t group_config_t::RESOLUTION_025_CM;
const uint32_t group_config_t::RESOLUTION_05_CM;
const uint32_t group_config_t::RESOLUTION_1_CM;

const vnx::Hash64 group_config_t::VNX_TYPE_HASH(0x54c195694cac61efull);
const vnx::Hash64 group_config_t::VNX_CODE_HASH(0x918b0e41c2993a1full);

vnx::Hash64 group_config_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* group_config_t::get_type_name() const {
	return "pilot.usboard.group_config_t";
}
const vnx::TypeCode* group_config_t::get_type_code() const {
	return pilot::usboard::vnx_native_type_code_group_config_t;
}

std::shared_ptr<group_config_t> group_config_t::create() {
	return std::make_shared<group_config_t>();
}

std::shared_ptr<group_config_t> group_config_t::clone() const {
	return std::make_shared<group_config_t>(*this);
}

void group_config_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void group_config_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void group_config_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = pilot::usboard::vnx_native_type_code_group_config_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, enable_transmission);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, resolution);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, fire_interval_ms);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, sending_sensor);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, long_range);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, cross_echo_mode);
	_visitor.type_end(*_type_code);
}

void group_config_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"enable_transmission\": "; vnx::write(_out, enable_transmission);
	_out << ", \"resolution\": "; vnx::write(_out, resolution);
	_out << ", \"fire_interval_ms\": "; vnx::write(_out, fire_interval_ms);
	_out << ", \"sending_sensor\": "; vnx::write(_out, sending_sensor);
	_out << ", \"long_range\": "; vnx::write(_out, long_range);
	_out << ", \"cross_echo_mode\": "; vnx::write(_out, cross_echo_mode);
	_out << "}";
}

void group_config_t::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "cross_echo_mode") {
			vnx::from_string(_entry.second, cross_echo_mode);
		} else if(_entry.first == "enable_transmission") {
			vnx::from_string(_entry.second, enable_transmission);
		} else if(_entry.first == "fire_interval_ms") {
			vnx::from_string(_entry.second, fire_interval_ms);
		} else if(_entry.first == "long_range") {
			vnx::from_string(_entry.second, long_range);
		} else if(_entry.first == "resolution") {
			vnx::from_string(_entry.second, resolution);
		} else if(_entry.first == "sending_sensor") {
			vnx::from_string(_entry.second, sending_sensor);
		}
	}
}

vnx::Object group_config_t::to_object() const {
	vnx::Object _object;
	_object["enable_transmission"] = enable_transmission;
	_object["resolution"] = resolution;
	_object["fire_interval_ms"] = fire_interval_ms;
	_object["sending_sensor"] = sending_sensor;
	_object["long_range"] = long_range;
	_object["cross_echo_mode"] = cross_echo_mode;
	return _object;
}

void group_config_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "cross_echo_mode") {
			_entry.second.to(cross_echo_mode);
		} else if(_entry.first == "enable_transmission") {
			_entry.second.to(enable_transmission);
		} else if(_entry.first == "fire_interval_ms") {
			_entry.second.to(fire_interval_ms);
		} else if(_entry.first == "long_range") {
			_entry.second.to(long_range);
		} else if(_entry.first == "resolution") {
			_entry.second.to(resolution);
		} else if(_entry.first == "sending_sensor") {
			_entry.second.to(sending_sensor);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const group_config_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, group_config_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* group_config_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> group_config_t::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "pilot.usboard.group_config_t";
	type_code->type_hash = vnx::Hash64(0x54c195694cac61efull);
	type_code->code_hash = vnx::Hash64(0x918b0e41c2993a1full);
	type_code->is_native = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<group_config_t>>(); };
	type_code->fields.resize(6);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "enable_transmission";
		field.value = vnx::to_string(true);
		field.code = {31};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.name = "resolution";
		field.value = vnx::to_string(1);
		field.code = {3};
	}
	{
		vnx::TypeField& field = type_code->fields[2];
		field.name = "fire_interval_ms";
		field.value = vnx::to_string(16);
		field.code = {3};
	}
	{
		vnx::TypeField& field = type_code->fields[3];
		field.name = "sending_sensor";
		field.value = vnx::to_string(-1);
		field.code = {7};
	}
	{
		vnx::TypeField& field = type_code->fields[4];
		field.name = "long_range";
		field.value = vnx::to_string(false);
		field.code = {31};
	}
	{
		vnx::TypeField& field = type_code->fields[5];
		field.name = "cross_echo_mode";
		field.value = vnx::to_string(false);
		field.code = {31};
	}
	type_code->build();
	return type_code;
}


} // namespace pilot
} // namespace usboard


namespace vnx {

void read(TypeInput& in, ::pilot::usboard::group_config_t& value, const TypeCode* type_code, const uint16_t* code) {
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
				vnx::read_value(_buf + _field->offset, value.enable_transmission, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[1];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.resolution, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[2];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.fire_interval_ms, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[3];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.sending_sensor, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[4];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.long_range, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[5];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.cross_echo_mode, _field->code.data());
			}
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::pilot::usboard::group_config_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = pilot::usboard::vnx_native_type_code_group_config_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::pilot::usboard::group_config_t>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(15);
	vnx::write_value(_buf + 0, value.enable_transmission);
	vnx::write_value(_buf + 1, value.resolution);
	vnx::write_value(_buf + 5, value.fire_interval_ms);
	vnx::write_value(_buf + 9, value.sending_sensor);
	vnx::write_value(_buf + 13, value.long_range);
	vnx::write_value(_buf + 14, value.cross_echo_mode);
}

void read(std::istream& in, ::pilot::usboard::group_config_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::pilot::usboard::group_config_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::pilot::usboard::group_config_t& value) {
	value.accept(visitor);
}

} // vnx
