
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_pilot_usboard_USBoardModule_CLIENT_HXX_
#define INCLUDE_pilot_usboard_USBoardModule_CLIENT_HXX_

#include <vnx/Client.h>
#include <pilot/usboard/USBoardConfig.hxx>
#include <vnx/Module.h>
#include <vnx/TopicPtr.hpp>


namespace pilot {
namespace usboard {

class USBoardModuleClient : public vnx::Client {
public:
	USBoardModuleClient(const std::string& service_name);
	
	USBoardModuleClient(vnx::Hash64 service_addr);
	
	std::shared_ptr<const ::pilot::usboard::USBoardConfig> get_config();
	
	void save_config();
	
	void save_config_async();
	
	void set_config(const std::shared_ptr<const ::pilot::usboard::USBoardConfig>& config);
	
	void set_config_async(const std::shared_ptr<const ::pilot::usboard::USBoardConfig>& config);
	
};


} // namespace pilot
} // namespace usboard

#endif // INCLUDE_pilot_usboard_USBoardModule_CLIENT_HXX_