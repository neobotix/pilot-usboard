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
	// TODO
	return std::vector<base::CAN_Frame>();
}

void USBoardConfig::from_can_frames(const std::vector<base::CAN_Frame>& frames)
{
	// TODO
}


} // usboard
} // pilot
