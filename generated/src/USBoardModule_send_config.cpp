
// AUTO GENERATED by vnxcppcodegen

#include <pilot/usboard/package.hxx>
#include <pilot/usboard/USBoardModule_send_config.hxx>
#include <pilot/usboard/USBoardConfig.hxx>
#include <pilot/usboard/USBoardModule_send_config_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace pilot {
namespace usboard {


const vnx::Hash64 USBoardModule_send_config::VNX_TYPE_HASH(0xc95ed3ee2bff3228ull);
const vnx::Hash64 USBoardModule_send_config::VNX_CODE_HASH(0x60217afe181d8a1eull);

vnx::Hash64 USBoardModule_send_config::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* USBoardModule_send_config::get_type_name() const {
	return "pilot.usboard.USBoardModule.send_config";
}
const vnx::TypeCode* USBoardModule_send_config::get_type_code() const {
	return pilot::usboard::vnx_native_type_code_USBoardModule_send_config;
}

std::shared_ptr<USBoardModule_send_config> USBoardModule_send_config::create() {
	return std::make_shared<USBoardModule_send_config>();
}

std::shared_ptr<vnx::Value> USBoardModule_send_config::clone() const {
	return std::make_shared<USBoardModule_send_config>(*this);
}

void USBoardModule_send_config::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void USBoardModule_send_config::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void USBoardModule_send_config::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = pilot::usboard::vnx_native_type_code_USBoardModule_send_config;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, config);
	_visitor.type_end(*_type_code);
}

void USBoardModule_send_config::write(std::ostream& _out) const {
	_out << "{\"__type\": \"pilot.usboard.USBoardModule.send_config\"";
	_out << ", \"config\": "; vnx::write(_out, config);
	_out << "}";
}

void USBoardModule_send_config::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "config") {
			vnx::from_string(_entry.second, config);
		}
	}
}

vnx::Object USBoardModule_send_config::to_object() const {
	vnx::Object _object;
	_object["__type"] = "pilot.usboard.USBoardModule.send_config";
	_object["config"] = config;
	return _object;
}

void USBoardModule_send_config::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "config") {
			_entry.second.to(config);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const USBoardModule_send_config& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, USBoardModule_send_config& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* USBoardModule_send_config::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> USBoardModule_send_config::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "pilot.usboard.USBoardModule.send_config";
	type_code->type_hash = vnx::Hash64(0xc95ed3ee2bff3228ull);
	type_code->code_hash = vnx::Hash64(0x60217afe181d8a1eull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<USBoardModule_send_config>(); };
	type_code->return_type = ::pilot::usboard::USBoardModule_send_config_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "config";
		field.code = {16};
	}
	type_code->build();
	return type_code;
}


} // namespace pilot
} // namespace usboard


namespace vnx {

void read(TypeInput& in, ::pilot::usboard::USBoardModule_send_config& value, const TypeCode* type_code, const uint16_t* code) {
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
	if(type_code->is_matched) {
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.config, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::pilot::usboard::USBoardModule_send_config& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = pilot::usboard::vnx_native_type_code_USBoardModule_send_config;
		out.write_type_code(type_code);
		vnx::write_class_header<::pilot::usboard::USBoardModule_send_config>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.config, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::pilot::usboard::USBoardModule_send_config& value) {
	value.read(in);
}

void write(std::ostream& out, const ::pilot::usboard::USBoardModule_send_config& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::pilot::usboard::USBoardModule_send_config& value) {
	value.accept(visitor);
}

} // vnx
