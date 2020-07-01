
// AUTO GENERATED by vnxcppcodegen

#include <pilot/usboard/package.hxx>
#include <pilot/usboard/sensor_config_t.hxx>

#include <vnx/vnx.h>


namespace pilot {
namespace usboard {


const vnx::Hash64 sensor_config_t::VNX_TYPE_HASH(0x4992d944965d7b92ull);
const vnx::Hash64 sensor_config_t::VNX_CODE_HASH(0x9869e4bb881b9c3aull);

vnx::Hash64 sensor_config_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* sensor_config_t::get_type_name() const {
	return "pilot.usboard.sensor_config_t";
}
const vnx::TypeCode* sensor_config_t::get_type_code() const {
	return pilot::usboard::vnx_native_type_code_sensor_config_t;
}

std::shared_ptr<sensor_config_t> sensor_config_t::create() {
	return std::make_shared<sensor_config_t>();
}

std::shared_ptr<sensor_config_t> sensor_config_t::clone() const {
	return std::make_shared<sensor_config_t>(*this);
}

void sensor_config_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void sensor_config_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void sensor_config_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = pilot::usboard::vnx_native_type_code_sensor_config_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, active);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, warn_distance);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, alarm_distance);
	_visitor.type_end(*_type_code);
}

void sensor_config_t::write(std::ostream& _out) const {
	_out << "{\"__type\": \"pilot.usboard.sensor_config_t\"";
	_out << ", \"active\": "; vnx::write(_out, active);
	_out << ", \"warn_distance\": "; vnx::write(_out, warn_distance);
	_out << ", \"alarm_distance\": "; vnx::write(_out, alarm_distance);
	_out << "}";
}

void sensor_config_t::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "active") {
			vnx::from_string(_entry.second, active);
		} else if(_entry.first == "alarm_distance") {
			vnx::from_string(_entry.second, alarm_distance);
		} else if(_entry.first == "warn_distance") {
			vnx::from_string(_entry.second, warn_distance);
		}
	}
}

vnx::Object sensor_config_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "pilot.usboard.sensor_config_t";
	_object["active"] = active;
	_object["warn_distance"] = warn_distance;
	_object["alarm_distance"] = alarm_distance;
	return _object;
}

void sensor_config_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "active") {
			_entry.second.to(active);
		} else if(_entry.first == "alarm_distance") {
			_entry.second.to(alarm_distance);
		} else if(_entry.first == "warn_distance") {
			_entry.second.to(warn_distance);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const sensor_config_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, sensor_config_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* sensor_config_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> sensor_config_t::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "pilot.usboard.sensor_config_t";
	type_code->type_hash = vnx::Hash64(0x4992d944965d7b92ull);
	type_code->code_hash = vnx::Hash64(0x9869e4bb881b9c3aull);
	type_code->is_native = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<sensor_config_t>>(); };
	type_code->fields.resize(3);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "active";
		field.code = {1};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.name = "warn_distance";
		field.value = vnx::to_string(1);
		field.code = {9};
	}
	{
		vnx::TypeField& field = type_code->fields[2];
		field.name = "alarm_distance";
		field.value = vnx::to_string(0.3);
		field.code = {9};
	}
	type_code->build();
	return type_code;
}


} // namespace pilot
} // namespace usboard


namespace vnx {

void read(TypeInput& in, ::pilot::usboard::sensor_config_t& value, const TypeCode* type_code, const uint16_t* code) {
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
				vnx::read_value(_buf + _field->offset, value.active, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[1];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.warn_distance, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[2];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.alarm_distance, _field->code.data());
			}
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::pilot::usboard::sensor_config_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = pilot::usboard::vnx_native_type_code_sensor_config_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::pilot::usboard::sensor_config_t>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(9);
	vnx::write_value(_buf + 0, value.active);
	vnx::write_value(_buf + 1, value.warn_distance);
	vnx::write_value(_buf + 5, value.alarm_distance);
}

void read(std::istream& in, ::pilot::usboard::sensor_config_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::pilot::usboard::sensor_config_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::pilot::usboard::sensor_config_t& value) {
	value.accept(visitor);
}

} // vnx
