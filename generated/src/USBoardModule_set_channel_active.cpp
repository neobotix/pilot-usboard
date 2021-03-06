
// AUTO GENERATED by vnxcppcodegen

#include <pilot/usboard/package.hxx>
#include <pilot/usboard/USBoardModule_set_channel_active.hxx>
#include <pilot/usboard/USBoardModule_set_channel_active_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace pilot {
namespace usboard {


const vnx::Hash64 USBoardModule_set_channel_active::VNX_TYPE_HASH(0x4d5fe6cf9c152a42ull);
const vnx::Hash64 USBoardModule_set_channel_active::VNX_CODE_HASH(0x59ba2cf5e570d8f3ull);

vnx::Hash64 USBoardModule_set_channel_active::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string USBoardModule_set_channel_active::get_type_name() const {
	return "pilot.usboard.USBoardModule.set_channel_active";
}

const vnx::TypeCode* USBoardModule_set_channel_active::get_type_code() const {
	return pilot::usboard::vnx_native_type_code_USBoardModule_set_channel_active;
}

std::shared_ptr<USBoardModule_set_channel_active> USBoardModule_set_channel_active::create() {
	return std::make_shared<USBoardModule_set_channel_active>();
}

std::shared_ptr<vnx::Value> USBoardModule_set_channel_active::clone() const {
	return std::make_shared<USBoardModule_set_channel_active>(*this);
}

void USBoardModule_set_channel_active::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void USBoardModule_set_channel_active::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void USBoardModule_set_channel_active::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = pilot::usboard::vnx_native_type_code_USBoardModule_set_channel_active;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, sensors);
	_visitor.type_end(*_type_code);
}

void USBoardModule_set_channel_active::write(std::ostream& _out) const {
	_out << "{\"__type\": \"pilot.usboard.USBoardModule.set_channel_active\"";
	_out << ", \"sensors\": "; vnx::write(_out, sensors);
	_out << "}";
}

void USBoardModule_set_channel_active::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object USBoardModule_set_channel_active::to_object() const {
	vnx::Object _object;
	_object["__type"] = "pilot.usboard.USBoardModule.set_channel_active";
	_object["sensors"] = sensors;
	return _object;
}

void USBoardModule_set_channel_active::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "sensors") {
			_entry.second.to(sensors);
		}
	}
}

vnx::Variant USBoardModule_set_channel_active::get_field(const std::string& _name) const {
	if(_name == "sensors") {
		return vnx::Variant(sensors);
	}
	return vnx::Variant();
}

void USBoardModule_set_channel_active::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "sensors") {
		_value.to(sensors);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const USBoardModule_set_channel_active& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, USBoardModule_set_channel_active& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* USBoardModule_set_channel_active::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> USBoardModule_set_channel_active::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "pilot.usboard.USBoardModule.set_channel_active";
	type_code->type_hash = vnx::Hash64(0x4d5fe6cf9c152a42ull);
	type_code->code_hash = vnx::Hash64(0x59ba2cf5e570d8f3ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::pilot::usboard::USBoardModule_set_channel_active);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<USBoardModule_set_channel_active>(); };
	type_code->return_type = ::pilot::usboard::USBoardModule_set_channel_active_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "sensors";
		field.code = {12, 31};
	}
	type_code->build();
	return type_code;
}


} // namespace pilot
} // namespace usboard


namespace vnx {

void read(TypeInput& in, ::pilot::usboard::USBoardModule_set_channel_active& value, const TypeCode* type_code, const uint16_t* code) {
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
	if(type_code->is_matched) {
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.sensors, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::pilot::usboard::USBoardModule_set_channel_active& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = pilot::usboard::vnx_native_type_code_USBoardModule_set_channel_active;
		out.write_type_code(type_code);
		vnx::write_class_header<::pilot::usboard::USBoardModule_set_channel_active>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.sensors, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::pilot::usboard::USBoardModule_set_channel_active& value) {
	value.read(in);
}

void write(std::ostream& out, const ::pilot::usboard::USBoardModule_set_channel_active& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::pilot::usboard::USBoardModule_set_channel_active& value) {
	value.accept(visitor);
}

} // vnx
