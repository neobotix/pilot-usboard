/*
 * USBoardConfig.cpp
 *
 *  Created on: Jun 18, 2020
 *      Author: mad
 */

#include <pilot/usboard/USBoardConfig.hxx>


namespace pilot {
namespace usboard {

std::vector<base::CAN_Frame> USBoardConfig::to_can_frames() const
{
	std::vector<base::CAN_Frame> result;
	result.resize(9);

	for(size_t i=0; i<9; i++){
		// time, id and first byte are set by caller
		result[i].size = 8;
		result[i].set_uint(8, 8, i, 0);
	}

	uint8_t baudrate_id = 0;
	switch(can_baudrate){
	case 1000000:
		baudrate_id = 0;
		break;
	case 500000:
		baudrate_id = 1;
		break;
	case 250000:
		baudrate_id = 2;
		break;
	case 125000:
		baudrate_id = 3;
		break;
	case 100000:
		baudrate_id = 4;
		break;
	case 50000:
		baudrate_id = 5;
		break;
	}
	result[0].set_uint(16, 8, baudrate_id, 0);
	result[0].set_uint(24, 8, can_id & 0xFF, 0);
	result[0].set_uint(32, 8, (can_id & 0xFF00) >> 8, 0);
	result[0].set_uint(40, 8, (can_id & 0xFF0000) >> 16, 0);
	result[0].set_uint(48, 8, (can_id & 0xFF000000) >> 24, 0);
	result[0].set_bool(56, false); // use extended CAN id
	result[0].set_bool(57, enable_can_termination);
	result[0].set_bool(58, enable_analog_input);
	result[0].set_bool(59, enable_legacy_format);

	result[1].set_uint(16, 4, transmit_mode, 0);
	for(size_t i=0; i<4; i++){
		result[1].set_bool(20+i, group_config[i].transmission_enable);
	}
	uint8_t interval_id = 0;
	uint8_t custom_interval = 0;
	switch(update_interval_ms){
	case 500:
		interval_id = 0;
		break;
	case 1000:
		interval_id = 1;
		break;
	case 2000:
		interval_id = 2;
		break;
	case 200:
		interval_id = 3;
		break;
	default:
		interval_id = 15;
		custom_interval = (update_interval_ms / 50) - 1;
	}
	result[1].set_uint(24, 4, interval_id, 0);
	result[1].set_uint(28, 4, custom_interval, 0);
	for(size_t i=0; i<16; i++){
		result[1].set_bool(32+i, sensor_config[i].active);
	}

	for(size_t i=0; i<16; i++){
		size_t frameindex = ((i + 4) / 6) + 1;
		size_t byteindex  = ((i + 4) % 6) + 2;
		result[frameindex].set_uint(byteindex*8, 8, sensor_config[i].warn_distance*100, 0);
	}

	for(size_t i=0; i<16; i++){
		size_t frameindex = ((i + 2) / 6) + 4;
		size_t byteindex  = ((i + 2) % 6) + 2;
		result[frameindex].set_uint(byteindex*8, 8, sensor_config[i].alarm_distance*100, 0);
	}

	for(size_t i=0; i<4; i++){
		result[7].set_uint(16+i*2, 2, group_config[i].resolution, 0);
		result[7].set_bool(24+i, group_config[i].cross_echo_mode);
		result[7].set_bool(28+i, group_config[i].long_range);
		result[7].set_uint(32+i*2, 2, group_config[i].sending_sensor, 0);
		result[7].set_uint(40+i*4, 4, group_config[i].fire_interval_ms / 16, 0);
	}
	result[7].set_uint(56, 8, low_pass_gain * 100, 0);

	result[8].set_uint(24*8, 8, hardware_version, 0);
	if(hardware_version == 0){
		// USBoard V1
		result[8].set_uint(40*8, 3, serial_number, 0);
	}else if(hardware_version == 20){
		// USBoard V2 (USS5)
		result[8].set_uint(32*8, 4, serial_number, 0);
	}

	return result;
}

void USBoardConfig::from_can_frames(const std::vector<base::CAN_Frame>& frames)
{
	uint8_t baudrate_id = frames[0].get_uint(16, 8, 0);
	switch(baudrate_id){
	case 0:
		can_baudrate = 1000000;
		break;
	case 1:
		can_baudrate = 500000;
		break;
	case 2:
		can_baudrate = 250000;
		break;
	case 3:
		can_baudrate = 125000;
		break;
	case 4:
		can_baudrate = 100000;
		break;
	case 5:
		can_baudrate = 50000;
		break;
	}
	can_id = frames[0].get_uint(24, 8, 0) + (frames[0].get_uint(32, 8, 0) << 8) + (frames[0].get_uint(40, 8, 0) << 16) + (frames[0].get_uint(48, 8, 0) << 24);
	// extended can id = frames[0].get_bool(56)
	enable_can_termination = frames[0].get_bool(57);
	enable_analog_input = frames[0].get_bool(58);
	enable_legacy_format = frames[0].get_bool(59);

	transmit_mode = frames[1].get_uint(16, 4, 0);
	for(size_t i=0; i<4; i++){
		group_config[i].transmission_enable = frames[1].get_bool(20+i);
	}
	uint8_t interval_id = frames[1].get_uint(24, 4, 0);
	switch(interval_id){
	case 0:
		update_interval_ms = 500;
		break;
	case 1:
		update_interval_ms = 1000;
		break;
	case 2:
		update_interval_ms = 2000;
		break;
	case 3:
		update_interval_ms = 200;
		break;
	case 15:
		update_interval_ms = (frames[1].get_uint(28, 4, 0) + 1) * 50;
	}
	for(size_t i=0; i<16; i++){
		sensor_config[i].active = frames[1].get_bool(32+i);
	}

	for(size_t i=0; i<16; i++){
		size_t frameindex = ((i + 4) / 6) + 1;
		size_t byteindex  = ((i + 4) % 6) + 2;
		sensor_config[i].warn_distance = frames[frameindex].get_uint(byteindex*8, 8, 0) / 100.0;
	}

	for(size_t i=0; i<16; i++){
		size_t frameindex = ((i + 2) / 6) + 4;
		size_t byteindex  = ((i + 2) % 6) + 2;
		sensor_config[i].alarm_distance = frames[frameindex].get_uint(byteindex*8, 8, 0) / 100.0;
	}

	for(size_t i=0; i<4; i++){
		group_config[i].resolution = frames[7].get_uint(16+i*2, 2, 0);
		group_config[i].cross_echo_mode = frames[7].get_bool(24+i);
		group_config[i].long_range = frames[7].get_bool(28+i);
		group_config[i].sending_sensor = frames[7].get_uint(32+i*2, 2, 0);
		group_config[i].fire_interval_ms = frames[7].get_uint(40+i*4, 4, 0) * 16;
	}
	low_pass_gain = frames[7].get_uint(56, 8, 0) * 0.01;

	hardware_version = frames[8].get_uint(24*8, 8, 0);
	if(hardware_version == 0){
		// USBoard V1
		serial_number = frames[8].get_uint(40*8, 3, 0);
	}else if(hardware_version == 20){
		// USBoard V2 (USS5)
		serial_number = frames[8].get_uint(32*8, 4, 0);
	}
}


uint32_t USBoardConfig::count_transmitting_groups() const{
	if(transmit_mode == TRANSMIT_MODE_REQUEST) return 0;
	uint32_t result = 0;
	for(size_t i=0; i<4; i++){
		if(group_config[i].transmission_enable) result++;
	}
	return result;
}


} // usboard
} // pilot
