/*
 * USBoardModule.h
 *
 *  Created on: Jun 17, 2020
 *      Author: mad
 */

#ifndef INCLUDE_PILOT_USBOARD_USBOARDMODULE_H_
#define INCLUDE_PILOT_USBOARD_USBOARDMODULE_H_

#include <pilot/usboard/USBoardModuleBase.hxx>
#include <pilot/usboard/IndexCollector.h>
#include <pilot/usboard/USBoardData.hxx>


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

	void handle(std::shared_ptr<const ::pilot::base::CAN_Frame> frame);
	void handle(std::shared_ptr<const ::pilot::base::DataPacket> data);

private:
	enum Command{
		CMD_CONNECT = 0,
		CMD_SET_CHANNEL_ACTIVE = 1,
		CMD_GET_DATA_1TO8 = 2,
		CMD_GET_DATA_9TO16 = 3,
		CMD_WRITE_PARASET = 4,
		CMD_WRITE_PARASET_TO_EEPROM = 5,
		CMD_READ_PARASET = 6,
		CMD_GET_ANALOG_IN = 7,
		CMD_GET_DATA = 11,
	};

	std::shared_ptr<const USBoardConfig> m_config;
	// m_data collects all the most recent data. At certain events, the whole collection is published.
	USBoardData m_data;

	vnx::request_id_t m_sentConfigRequest;
	std::shared_ptr<const USBoardConfig> m_sentConfig;
	std::weak_ptr<vnx::Timer> m_sentConfigTimer;
	unsigned int m_sentConfigAck = 0;
	uint16_t m_sentConfigSum;

	IndexCollector<base::CAN_Frame> m_gotConfig;
	IndexCollector<base::CAN_Frame> m_gotData1To8;
	IndexCollector<base::CAN_Frame> m_gotData9To16;
	IndexCollector<base::CAN_Frame> m_gotData;
	std::weak_ptr<vnx::Timer> m_gotDataTimer;

	void async_timeout_callback(const vnx::request_id_t& request_id);
	void getdata_send();
	bool check_checksum(const std::vector<uint8_t> &message, size_t offset=0);
	void send_config(const std::shared_ptr<const USBoardConfig>& config, const vnx::request_id_t& request_id, Command command);

};


} // usboard
} // pilot

#endif /* INCLUDE_PILOT_USBOARD_USBOARDMODULE_H_ */
