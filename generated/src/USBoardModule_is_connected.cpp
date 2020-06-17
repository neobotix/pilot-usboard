
// AUTO GENERATED by vnxcppcodegen

#include <vnx/vnx.h>
#include <pilot/usboard/package.hxx>
#include <pilot/usboard/USBoardModule_is_connected.hxx>
#include <pilot/usboard/USBoardModule_is_connected_return.hxx>
#include <vnx/Value.h>



namespace pilot {
namespace usboard {


const vnx::Hash64 USBoardModule_is_connected::VNX_TYPE_HASH(0x67dc4b6f55cdaf01ull);
const vnx::Hash64 USBoardModule_is_connected::VNX_CODE_HASH(0xf8787e8e40541a14ull);

vnx::Hash64 USBoardModule_is_connected::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* USBoardModule_is_connected::get_type_name() const {
	return "pilot.usboard.USBoardModule.is_connected";
}
const vnx::TypeCode* USBoardModule_is_connected::get_type_code() const {
	return pilot::usboard::vnx_native_type_code_USBoardModule_is_connected;
}

std::shared_ptr<USBoardModule_is_connected> USBoardModule_is_connected::create() {
	return std::make_shared<USBoardModule_is_connected>();
}

std::shared_ptr<vnx::Value> USBoardModule_is_connected::clone() const {
	return std::make_shared<USBoardModule_is_connected>(*this);
}

void USBoardModule_is_connected::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void USBoardModule_is_connected::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void USBoardModule_is_connected::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = pilot::usboard::vnx_native_type_code_USBoardModule_is_connected;
	_visitor.type_begin(*_type_code);
	_visitor.type_end(*_type_code);
}

void USBoardModule_is_connected::write(std::ostream& _out) const {
	_out << "{\"__type\": \"pilot.usboard.USBoardModule.is_connected\"";
	_out << "}";
}

void USBoardModule_is_connected::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
	}
}

vnx::Object USBoardModule_is_connected::to_object() const {
	vnx::Object _object;
	_object["__type"] = "pilot.usboard.USBoardModule.is_connected";
	return _object;
}

void USBoardModule_is_connected::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const USBoardModule_is_connected& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, USBoardModule_is_connected& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* USBoardModule_is_connected::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> USBoardModule_is_connected::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "pilot.usboard.USBoardModule.is_connected";
	type_code->type_hash = vnx::Hash64(0x67dc4b6f55cdaf01ull);
	type_code->code_hash = vnx::Hash64(0xf8787e8e40541a14ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<USBoardModule_is_connected>(); };
	type_code->return_type = ::pilot::usboard::USBoardModule_is_connected_return::static_get_type_code();
	type_code->build();
	return type_code;
}


} // namespace pilot
} // namespace usboard


namespace vnx {

void read(TypeInput& in, ::pilot::usboard::USBoardModule_is_connected& value, const TypeCode* type_code, const uint16_t* code) {
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
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::pilot::usboard::USBoardModule_is_connected& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = pilot::usboard::vnx_native_type_code_USBoardModule_is_connected;
		out.write_type_code(type_code);
		vnx::write_class_header<::pilot::usboard::USBoardModule_is_connected>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
}

void read(std::istream& in, ::pilot::usboard::USBoardModule_is_connected& value) {
	value.read(in);
}

void write(std::ostream& out, const ::pilot::usboard::USBoardModule_is_connected& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::pilot::usboard::USBoardModule_is_connected& value) {
	value.accept(visitor);
}

} // vnx
