/*
 * USBoardData.cpp
 *
 *  Created on: Jun 24, 2020
 *      Author: mad
 */

#include <pilot/usboard/USBoardData.hxx>


namespace pilot {
namespace usboard {


void USBoardData::from_can_frames_1to8(const std::vector<base::CAN_Frame> &frames)
{
	for(size_t i=0; i<4; i++){
		sensor[i] = frames[0].get_uint((2+i)*8, 8, 0) / 100.0;
	}
	for(size_t i=4; i<8; i++){
		sensor[i] = frames[1].get_uint((2+i-4)*8, 8, 0) / 100.0;
	}
}

void USBoardData::from_can_frames_9to16(const std::vector<base::CAN_Frame> &frames)
{
	for(size_t i=8; i<12; i++){
		sensor[i] = frames[0].get_uint((2+i-8)*8, 8, 0) / 100.0;
	}
	for(size_t i=12; i<16; i++){
		sensor[i] = frames[1].get_uint((2+i-12)*8, 8, 0) / 100.0;
	}
}

void USBoardData::from_can_frames_analog(const std::vector<base::CAN_Frame> &frames)
{
	const base::CAN_Frame &fr = frames[0];
	for(size_t i=0; i<4; i++){
		analog_input[i] = fr.get_uint(8+i*8, 8, 0)  + (fr.get_uint(40+i*4, 4, 0) << 8);
	}
}

void USBoardData::from_can_frames_data(const std::vector<base::CAN_Frame> &frames)
{
	size_t numframes = frames.size();
	for(size_t i=0; i<numframes; i++){
		const base::CAN_Frame &fr = frames[i];
		uint8_t groupid = fr.get_uint(8, 2, 0);
		uint8_t resolution_id = fr.get_uint(8+2, 2, 0);
		unsigned int resolution = 0.01;
		switch(resolution_id){
		case 0:
			resolution = 0.01;
			break;
		case 1:
			resolution = 0.005;
			break;
		case 2:
			resolution = 0.0025;
			break;
		case 3:
			resolution = 0.00125;
			break;
		}
		if(fr.get_uint(8+4, 4, 0) == 0xF){
			signal_source[groupid] = -1;
		}else{
			for(char j=0; j<4; j++){
				if(fr.get_bool(8+4+j*4)){
					signal_source[groupid] = j;
					break;
				}
			}
		}
		for(size_t k=0; k<4; k++){
			uint16_t sensork = fr.get_uint(16+k*8, 8, 0) + (fr.get_uint(48+k*4, 4, 0) << 4);
			sensor[groupid*4 + k] = sensork*resolution;
		}
	}
}


} // usboard
} // pilot
