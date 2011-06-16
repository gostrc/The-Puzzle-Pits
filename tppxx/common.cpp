#include "common.hpp"

std::string PadItoA(int numPad, int number) {
	std::ostringstream strnum;
	strnum << std::setw(numPad) << std::setfill('0') << number;
	return strnum.str();
}
