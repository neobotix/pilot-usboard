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
	void init() override;

	void main() override;

	std::shared_ptr<const USBoardConfig> get_config() const override;

	vnx::bool_t is_connected() const override;

	void request_config() override;

	void request_data(const std::vector<vnx::bool_t>& groups) override;

	void request_analog_data() override;

	void send_config_async(	const std::shared_ptr<const USBoardConfig>& config,
							const vnx::request_id_t& request_id) override;

	void save_config_async(	const std::shared_ptr<const USBoardConfig>& config,
							const vnx::request_id_t& request_id) override;

	void set_channel_active(const std::vector<vnx::bool_t>& sensors) override;

private:
	void async_timeout_callback(const vnx::request_id_t& request_id);

private:
	std::shared_ptr<const USBoardConfig> m_config;

};


} // usboard
} // pilot

#endif /* INCLUDE_PILOT_USBOARD_USBOARDMODULE_H_ */
