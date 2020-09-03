
// AUTO GENERATED by vnxcppcodegen

#include <pilot/usboard/package.hxx>
#include <pilot/usboard/USBoardModule_request_data_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace pilot {
namespace usboard {


const vnx::Hash64 USBoardModule_request_data_return::VNX_TYPE_HASH(0xb6a4183451605df3ull);
const vnx::Hash64 USBoardModule_request_data_return::VNX_CODE_HASH(0xe1f717f5d1d19e8aull);

vnx::Hash64 USBoardModule_request_data_return::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* USBoardModule_request_data_return::get_type_name() const {
	return "pilot.usboard.USBoardModule.request_data.return";
}

const vnx::TypeCode* USBoardModule_request_data_return::get_type_code() const {
	return pilot::usboard::vnx_native_type_code_USBoardModule_request_data_return;
}

std::shared_ptr<USBoardModule_request_data_return> USBoardModule_request_data_return::create() {
	return std::make_shared<USBoardModule_request_data_return>();
}

std::shared_ptr<vnx::Value> USBoardModule_request_data_return::clone() const {
	return std::make_shared<USBoardModule_request_data_return>(*this);
}

void USBoardModule_request_data_return::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void USBoardModule_request_data_return::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void USBoardModule_request_data_return::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = pilot::usboard::vnx_native_type_code_USBoardModule_request_data_return;
	_visitor.type_begin(*_type_code);
	_visitor.type_end(*_type_code);
}

void USBoardModule_request_data_return::write(std::ostream& _out) const {
	_out << "{\"__type\": \"pilot.usboard.USBoardModule.request_data.return\"";
	_out << "}";
}

void USBoardModule_request_data_return::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
}

vnx::Object USBoardModule_request_data_return::to_object() const {
	vnx::Object _object;
	_object["__type"] = "pilot.usboard.USBoardModule.request_data.return";
	return _object;
}

void USBoardModule_request_data_return::from_object(const vnx::Object& _object) {
}

vnx::Variant USBoardModule_request_data_return::get_field(const std::string& _name) const {
	return vnx::Variant();
}

void USBoardModule_request_data_return::set_field(const std::string& _name, const vnx::Variant& _value) {
	throw std::logic_error("no such field: '" + _name + "'");
}

/// \private
std::ostream& operator<<(std::ostream& _out, const USBoardModule_request_data_return& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, USBoardModule_request_data_return& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* USBoardModule_request_data_return::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> USBoardModule_request_data_return::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "pilot.usboard.USBoardModule.request_data.return";
	type_code->type_hash = vnx::Hash64(0xb6a4183451605df3ull);
	type_code->code_hash = vnx::Hash64(0xe1f717f5d1d19e8aull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_return = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<USBoardModule_request_data_return>(); };
	type_code->build();
	return type_code;
}


} // namespace pilot
} // namespace usboard


namespace vnx {

void read(TypeInput& in, ::pilot::usboard::USBoardModule_request_data_return& value, const TypeCode* type_code, const uint16_t* code) {
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
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::pilot::usboard::USBoardModule_request_data_return& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = pilot::usboard::vnx_native_type_code_USBoardModule_request_data_return;
		out.write_type_code(type_code);
		vnx::write_class_header<::pilot::usboard::USBoardModule_request_data_return>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
}

void read(std::istream& in, ::pilot::usboard::USBoardModule_request_data_return& value) {
	value.read(in);
}

void write(std::ostream& out, const ::pilot::usboard::USBoardModule_request_data_return& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::pilot::usboard::USBoardModule_request_data_return& value) {
	value.accept(visitor);
}

} // vnx
