
// AUTO GENERATED by vnxcppcodegen

#include <vnx/vnx.h>

#include <pilot/usboard/USBoardConfig.hxx>
#include <pilot/usboard/USBoardData.hxx>
#include <pilot/usboard/USBoardModuleBase.hxx>
#include <pilot/usboard/USBoardModule_get_config.hxx>
#include <pilot/usboard/USBoardModule_get_config_return.hxx>
#include <pilot/usboard/USBoardModule_save_config.hxx>
#include <pilot/usboard/USBoardModule_save_config_return.hxx>
#include <pilot/usboard/USBoardModule_set_config.hxx>
#include <pilot/usboard/USBoardModule_set_config_return.hxx>
#include <pilot/usboard/group_config_t.hxx>
#include <pilot/usboard/sensor_config_t.hxx>



namespace pilot {
namespace usboard {


static void register_all_types() {
	vnx::register_type_code(::pilot::usboard::USBoardConfig::static_create_type_code());
	vnx::register_type_code(::pilot::usboard::USBoardData::static_create_type_code());
	vnx::register_type_code(::pilot::usboard::USBoardModuleBase::static_create_type_code());
	vnx::register_type_code(::pilot::usboard::USBoardModule_get_config::static_create_type_code());
	vnx::register_type_code(::pilot::usboard::USBoardModule_get_config_return::static_create_type_code());
	vnx::register_type_code(::pilot::usboard::USBoardModule_save_config::static_create_type_code());
	vnx::register_type_code(::pilot::usboard::USBoardModule_save_config_return::static_create_type_code());
	vnx::register_type_code(::pilot::usboard::USBoardModule_set_config::static_create_type_code());
	vnx::register_type_code(::pilot::usboard::USBoardModule_set_config_return::static_create_type_code());
	vnx::register_type_code(::pilot::usboard::group_config_t::static_create_type_code());
	vnx::register_type_code(::pilot::usboard::sensor_config_t::static_create_type_code());
}

static struct vnx_static_init {
	vnx_static_init() {
		register_all_types();
	}
} vnx_static_init_;

const vnx::TypeCode* const vnx_native_type_code_USBoardConfig = vnx::get_type_code(vnx::Hash64(0x9c0fb140354b6e4cull));
const vnx::TypeCode* const vnx_native_type_code_USBoardData = vnx::get_type_code(vnx::Hash64(0xbd08b8f30252bcb1ull));
const vnx::TypeCode* const vnx_native_type_code_USBoardModuleBase = vnx::get_type_code(vnx::Hash64(0x43f03ccffe42b23full));
const vnx::TypeCode* const vnx_native_type_code_USBoardModule_get_config = vnx::get_type_code(vnx::Hash64(0xe7bebc86c32def4eull));
const vnx::TypeCode* const vnx_native_type_code_USBoardModule_get_config_return = vnx::get_type_code(vnx::Hash64(0x358de7d95fe51641ull));
const vnx::TypeCode* const vnx_native_type_code_USBoardModule_save_config = vnx::get_type_code(vnx::Hash64(0xc5d8f1fd2323ac3bull));
const vnx::TypeCode* const vnx_native_type_code_USBoardModule_save_config_return = vnx::get_type_code(vnx::Hash64(0x4a4217094e238854ull));
const vnx::TypeCode* const vnx_native_type_code_USBoardModule_set_config = vnx::get_type_code(vnx::Hash64(0x6a53e1b7e450656dull));
const vnx::TypeCode* const vnx_native_type_code_USBoardModule_set_config_return = vnx::get_type_code(vnx::Hash64(0xe84890a511198faeull));
const vnx::TypeCode* const vnx_native_type_code_group_config_t = vnx::get_type_code(vnx::Hash64(0x54c195694cac61efull));
const vnx::TypeCode* const vnx_native_type_code_sensor_config_t = vnx::get_type_code(vnx::Hash64(0x4992d944965d7b92ull));

} // namespace pilot
} // namespace usboard
