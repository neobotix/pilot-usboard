
// AUTO GENERATED by vnxcppcodegen

#include <vnx/vnx.h>
#include <pilot/usboard/package.hxx>
#include <pilot/usboard/USBoardModule_is_connected_return.hxx>
#include <vnx/Value.h>



namespace pilot {
namespace usboard {


const vnx::Hash64 USBoardModule_is_connected_return::VNX_TYPE_HASH(0x9f92f79790f0b41cull);
const vnx::Hash64 USBoardModule_is_connected_return::VNX_CODE_HASH(0x7e8e2ed6cb92114cull);

vnx::Hash64 USBoardModule_is_connected_return::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* USBoardModule_is_connected_return::get_type_name() const {
	return "pilot.usboard.USBoardModule.is_connected.return";
}
const vnx::TypeCode* USBoardModule_is_connected_return::get_type_code() const {
	return pilot::usboard::vnx_native_type_code_USBoardModule_is_connected_return;
}

std::shared_ptr<USBoardModule_is_connected_return> USBoardModule_is_connected_return::create() {
	return std::make_shared<USBoardModule_is_connected_return>();
}

std::shared_ptr<vnx::Value> USBoardModule_is_connected_return::clone() const {
	return std::make_shared<USBoardModule_is_connected_return>(*this);
}

void USBoardModule_is_connected_return::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void USBoardModule_is_connected_return::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void USBoardModule_is_connected_return::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = pilot::usboard::vnx_native_type_code_USBoardModule_is_connected_return;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, _ret_0);
	_visitor.type_end(*_type_code);
}

void USBoardModule_is_connected_return::write(std::ostream& _out) const {
	_out << "{\"__type\": \"pilot.usboard.USBoardModule.is_connected.return\"";
	_out << ", \"_ret_0\": "; vnx::write(_out, _ret_0);
	_out << "}";
}

void USBoardModule_is_connected_return::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "_ret_0") {
			vnx::from_string(_entry.second, _ret_0);
		}
	}
}

vnx::Object USBoardModule_is_connected_return::to_object() const {
	vnx::Object _object;
	_object["__type"] = "pilot.usboard.USBoardModule.is_connected.return";
	_object["_ret_0"] = _ret_0;
	return _object;
}

void USBoardModule_is_connected_return::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "_ret_0") {
			_entry.second.to(_ret_0);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const USBoardModule_is_connected_return& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, USBoardModule_is_connected_return& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* USBoardModule_is_connected_return::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> USBoardModule_is_connected_return::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "pilot.usboard.USBoardModule.is_connected.return";
	type_code->type_hash = vnx::Hash64(0x9f92f79790f0b41cull);
	type_code->code_hash = vnx::Hash64(0x7e8e2ed6cb92114cull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_return = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<USBoardModule_is_connected_return>(); };
	type_code->fields.resize(1);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "_ret_0";
		field.code = {1};
	}
	type_code->build();
	return type_code;
}


} // namespace pilot
} // namespace usboard


namespace vnx {

void read(TypeInput& in, ::pilot::usboard::USBoardModule_is_connected_return& value, const TypeCode* type_code, const uint16_t* code) {
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
				vnx::read_value(_buf + _field->offset, value._ret_0, _field->code.data());
			}
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::pilot::usboard::USBoardModule_is_connected_return& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = pilot::usboard::vnx_native_type_code_USBoardModule_is_connected_return;
		out.write_type_code(type_code);
		vnx::write_class_header<::pilot::usboard::USBoardModule_is_connected_return>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(1);
	vnx::write_value(_buf + 0, value._ret_0);
}

void read(std::istream& in, ::pilot::usboard::USBoardModule_is_connected_return& value) {
	value.read(in);
}

void write(std::ostream& out, const ::pilot::usboard::USBoardModule_is_connected_return& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::pilot::usboard::USBoardModule_is_connected_return& value) {
	value.accept(visitor);
}

} // vnx