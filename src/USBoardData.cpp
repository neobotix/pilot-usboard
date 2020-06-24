/*
 * USBoardData.cpp
 *
 *  Created on: Jun 24, 2020
 *      Author: mad
 */

#include <pilot/usboard/USBoardData.hxx>


namespace pilot {
namespace usboard {

std::vector<base::CAN_Frame> USBoardData::to_can_frames() const
{
	// TODO
	return std::vector<base::CAN_Frame>();
}

void USBoardData::from_can_frames(const std::vector<base::CAN_Frame>& frames)
{
	// TODO
}


} // usboard
} // pilot
