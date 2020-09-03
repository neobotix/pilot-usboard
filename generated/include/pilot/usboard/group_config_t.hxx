
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_pilot_usboard_group_config_t_HXX_
#define INCLUDE_pilot_usboard_group_config_t_HXX_

#include <vnx/Type.h>
#include <pilot/usboard/package.hxx>


namespace pilot {
namespace usboard {

struct group_config_t {
	
	static const uint32_t RESOLUTION_0125_CM = 3;
	static const uint32_t RESOLUTION_025_CM = 2;
	static const uint32_t RESOLUTION_05_CM = 1;
	static const uint32_t RESOLUTION_1_CM = 0;
	
	vnx::bool_t enable_transmission = true;
	uint32_t resolution = 1;
	uint32_t fire_interval_ms = 16;
	int32_t sending_sensor = -1;
	vnx::bool_t long_range = false;
	vnx::bool_t cross_echo_mode = false;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	vnx::Hash64 get_type_hash() const;
	const char* get_type_name() const;
	const vnx::TypeCode* get_type_code() const;
	
	static std::shared_ptr<group_config_t> create();
	std::shared_ptr<group_config_t> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	vnx::Variant get_field(const std::string& name) const;
	void set_field(const std::string& name, const vnx::Variant& value);
	
	friend std::ostream& operator<<(std::ostream& _out, const group_config_t& _value);
	friend std::istream& operator>>(std::istream& _in, group_config_t& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};


} // namespace pilot
} // namespace usboard

#endif // INCLUDE_pilot_usboard_group_config_t_HXX_
