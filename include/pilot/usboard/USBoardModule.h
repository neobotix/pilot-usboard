/*
 * USBoardModule.h
 *
 *  Created on: Jun 17, 2020
 *      Author: mad
 */

#ifndef INCLUDE_PILOT_USBOARD_USBOARDMODULE_H_
#define INCLUDE_PILOT_USBOARD_USBOARDMODULE_H_

#include <pilot/usboard/USBoardModuleBase.hxx>


namespace pilot {
namespace usboard {

class USBoardModule : public USBoardModuleBase {
public:
	USBoardModule(const std::string& _vnx_name);

protected:
	void main() override;

	std::shared_ptr<const USBoardConfig> get_config() const override;

	vnx::bool_t is_connected() const override;

	void request_config() override;

	void request_data(const int32_t& group_set) override;

	void request_analog_data() override;

	void save_config() override;

	void send_config(const std::shared_ptr<const USBoardConfig>& config) override;

	void set_channel_active(const std::vector<vnx::bool_t>& sensors) override;

private:
	std::shared_ptr<const USBoardConfig> m_config;

};


} // usboard
} // pilot

#endif /* INCLUDE_PILOT_USBOARD_USBOARDMODULE_H_ */
