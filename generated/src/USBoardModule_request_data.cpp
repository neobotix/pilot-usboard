
// AUTO GENERATED by vnxcppcodegen

#include <vnx/vnx.h>
#include <pilot/usboard/package.hxx>
#include <pilot/usboard/USBoardModule_request_data.hxx>
#include <pilot/usboard/USBoardModule_request_data_return.hxx>
#include <vnx/Value.h>



namespace pilot {
namespace usboard {


const vnx::Hash64 USBoardModule_request_data::VNX_TYPE_HASH(0xc7bf45418c654bbfull);
const vnx::Hash64 USBoardModule_request_data::VNX_CODE_HASH(0x8de34564efdcc7ccull);

vnx::Hash64 USBoardModule_request_data::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* USBoardModule_request_data::get_type_name() const {
	return "pilot.usboard.USBoardModule.request_data";
}
const vnx::TypeCode* USBoardModule_request_data::get_type_code() const {
	return pilot::usboard::vnx_native_type_code_USBoardModule_request_data;
}

std::shared_ptr<USBoardModule_request_data> USBoardModule_request_data::create() {
	return std::make_shared<USBoardModule_request_data>();
}

std::shared_ptr<vnx::Value> USBoardModule_request_data::clone() const {
	return std::make_shared<USBoardModule_request_data>(*this);
}

void USBoardModule_request_data::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void USBoardModule_request_data::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void USBoardModule_request_data::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = pilot::usboard::vnx_native_type_code_USBoardModule_request_data;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, group_set);
	_visitor.type_end(*_type_code);
}

void USBoardModule_request_data::write(std::ostream& _out) const {
	_out << "{\"__type\": \"pilot.usboard.USBoardModule.request_data\"";
	_out << ", \"group_set\": "; vnx::write(_out, group_set);
	_out << "}";
}

void USBoardModule_request_data::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "group_set") {
			vnx::from_string(_entry.second, group_set);
		}
	}
}

vnx::Object USBoardModule_request_data::to_object() const {
	vnx::Object _object;
	_object["__type"] = "pilot.usboard.USBoardModule.request_data";
	_object["group_set"] = group_set;
	return _object;
}

void USBoardModule_request_data::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "group_set") {
			_entry.second.to(group_set);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const USBoardModule_request_data& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, USBoardModule_request_data& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* USBoardModule_request_data::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> USBoardModule_request_data::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "pilot.usboard.USBoardModule.request_data";
	type_code->type_hash = vnx::Hash64(0xc7bf45418c654bbfull);
	type_code->code_hash = vnx::Hash64(0x8de34564efdcc7ccull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<USBoardModule_request_data>(); };
	type_code->return_type = ::pilot::usboard::USBoardModule_request_data_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "group_set";
		field.code = {7};
	}
	type_code->build();
	return type_code;
}


} // namespace pilot
} // namespace usboard


namespace vnx {

void read(TypeInput& in, ::pilot::usboard::USBoardModule_request_data& value, const TypeCode* type_code, const uint16_t* code) {
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
				vnx::read_value(_buf + _field->offset, value.group_set, _field->code.data());
			}
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::pilot::usboard::USBoardModule_request_data& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = pilot::usboard::vnx_native_type_code_USBoardModule_request_data;
		out.write_type_code(type_code);
		vnx::write_class_header<::pilot::usboard::USBoardModule_request_data>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.group_set);
}

void read(std::istream& in, ::pilot::usboard::USBoardModule_request_data& value) {
	value.read(in);
}

void write(std::ostream& out, const ::pilot::usboard::USBoardModule_request_data& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::pilot::usboard::USBoardModule_request_data& value) {
	value.accept(visitor);
}

} // vnx