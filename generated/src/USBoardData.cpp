
// AUTO GENERATED by vnxcppcodegen

#include <vnx/vnx.h>
#include <pilot/usboard/package.hxx>
#include <pilot/usboard/USBoardData.hxx>
#include <pilot/base/Sample.hxx>



namespace pilot {
namespace usboard {


const vnx::Hash64 USBoardData::VNX_TYPE_HASH(0xbd08b8f30252bcb1ull);
const vnx::Hash64 USBoardData::VNX_CODE_HASH(0x66e73f707e53c6baull);

vnx::Hash64 USBoardData::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* USBoardData::get_type_name() const {
	return "pilot.usboard.USBoardData";
}
const vnx::TypeCode* USBoardData::get_type_code() const {
	return pilot::usboard::vnx_native_type_code_USBoardData;
}

std::shared_ptr<USBoardData> USBoardData::create() {
	return std::make_shared<USBoardData>();
}

std::shared_ptr<vnx::Value> USBoardData::clone() const {
	return std::make_shared<USBoardData>(*this);
}

void USBoardData::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void USBoardData::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void USBoardData::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = pilot::usboard::vnx_native_type_code_USBoardData;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, time);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, sensor);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, signal_source);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, analog_input);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, analog_input_scale);
	_visitor.type_end(*_type_code);
}

void USBoardData::write(std::ostream& _out) const {
	_out << "{\"__type\": \"pilot.usboard.USBoardData\"";
	_out << ", \"time\": "; vnx::write(_out, time);
	_out << ", \"sensor\": "; vnx::write(_out, sensor);
	_out << ", \"signal_source\": "; vnx::write(_out, signal_source);
	_out << ", \"analog_input\": "; vnx::write(_out, analog_input);
	_out << ", \"analog_input_scale\": "; vnx::write(_out, analog_input_scale);
	_out << "}";
}

void USBoardData::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "analog_input") {
			vnx::from_string(_entry.second, analog_input);
		} else if(_entry.first == "analog_input_scale") {
			vnx::from_string(_entry.second, analog_input_scale);
		} else if(_entry.first == "sensor") {
			vnx::from_string(_entry.second, sensor);
		} else if(_entry.first == "signal_source") {
			vnx::from_string(_entry.second, signal_source);
		} else if(_entry.first == "time") {
			vnx::from_string(_entry.second, time);
		}
	}
}

vnx::Object USBoardData::to_object() const {
	vnx::Object _object;
	_object["__type"] = "pilot.usboard.USBoardData";
	_object["time"] = time;
	_object["sensor"] = sensor;
	_object["signal_source"] = signal_source;
	_object["analog_input"] = analog_input;
	_object["analog_input_scale"] = analog_input_scale;
	return _object;
}

void USBoardData::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "analog_input") {
			_entry.second.to(analog_input);
		} else if(_entry.first == "analog_input_scale") {
			_entry.second.to(analog_input_scale);
		} else if(_entry.first == "sensor") {
			_entry.second.to(sensor);
		} else if(_entry.first == "signal_source") {
			_entry.second.to(signal_source);
		} else if(_entry.first == "time") {
			_entry.second.to(time);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const USBoardData& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, USBoardData& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* USBoardData::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> USBoardData::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "pilot.usboard.USBoardData";
	type_code->type_hash = vnx::Hash64(0xbd08b8f30252bcb1ull);
	type_code->code_hash = vnx::Hash64(0x66e73f707e53c6baull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->parents.resize(1);
	type_code->parents[0] = ::pilot::base::Sample::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<USBoardData>(); };
	type_code->fields.resize(5);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "time";
		field.code = {8};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.name = "sensor";
		field.code = {11, 16, 9};
	}
	{
		vnx::TypeField& field = type_code->fields[2];
		field.name = "signal_source";
		field.code = {11, 4, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[3];
		field.name = "analog_input";
		field.code = {11, 4, 6};
	}
	{
		vnx::TypeField& field = type_code->fields[4];
		field.name = "analog_input_scale";
		field.value = vnx::to_string(0.004887);
		field.code = {9};
	}
	type_code->build();
	return type_code;
}


} // namespace pilot
} // namespace usboard


namespace vnx {

void read(TypeInput& in, ::pilot::usboard::USBoardData& value, const TypeCode* type_code, const uint16_t* code) {
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
				vnx::read_value(_buf + _field->offset, value.time, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[1];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.sensor, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[2];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.signal_source, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[3];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.analog_input, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[4];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.analog_input_scale, _field->code.data());
			}
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::pilot::usboard::USBoardData& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = pilot::usboard::vnx_native_type_code_USBoardData;
		out.write_type_code(type_code);
		vnx::write_class_header<::pilot::usboard::USBoardData>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(88);
	vnx::write_value(_buf + 0, value.time);
	vnx::write_value(_buf + 8, value.sensor);
	vnx::write_value(_buf + 72, value.signal_source);
	vnx::write_value(_buf + 76, value.analog_input);
	vnx::write_value(_buf + 84, value.analog_input_scale);
}

void read(std::istream& in, ::pilot::usboard::USBoardData& value) {
	value.read(in);
}

void write(std::ostream& out, const ::pilot::usboard::USBoardData& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::pilot::usboard::USBoardData& value) {
	value.accept(visitor);
}

} // vnx
