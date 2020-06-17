
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_pilot_usboard_USBoardModule_save_config_HXX_
#define INCLUDE_pilot_usboard_USBoardModule_save_config_HXX_

#include <pilot/usboard/package.hxx>
#include <vnx/Value.h>


namespace pilot {
namespace usboard {

class USBoardModule_save_config : public ::vnx::Value {
public:
	
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	vnx::Hash64 get_type_hash() const override;
	const char* get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<USBoardModule_save_config> create();
	std::shared_ptr<vnx::Value> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	friend std::ostream& operator<<(std::ostream& _out, const USBoardModule_save_config& _value);
	friend std::istream& operator>>(std::istream& _in, USBoardModule_save_config& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};


} // namespace pilot
} // namespace usboard

#endif // INCLUDE_pilot_usboard_USBoardModule_save_config_HXX_
