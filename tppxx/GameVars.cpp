#include <string>
#include <sstream>
#include <iomanip>

#include "GameVars.hpp"

// returns a padded string representation of a number
static std::string PadItoA(int numPad, int number) {
	std::ostringstream strnum;
	strnum << std::setw(numPad) << std::setfill('0') << number;
	return strnum.str();
}

GameVars::GameVars() {
	std::string path("../data/images/tiles/");

	// 285 tiles
	tileImages.resize(285);
	tileSprites.resize(285);

	for(int i = 0; i < 285; i++) {
		if(!tileImages[i].LoadFromFile(path + PadItoA(3, i) + ".png")) {
			exit(EXIT_FAILURE);
		}
		tileSprites[i].SetImage(tileImages[i]);
	}

	mouse = new Mouse(tileImages);
}
