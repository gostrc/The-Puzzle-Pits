#include <string>

#include "GameVars.hpp"

#include "common.hpp"

GameVars::GameVars() : mouse(new Mouse) {
	std::string path("../data/images/tiles/");

	for(int i = 0; i < NUMTILES; i++) {
		ImagePtr img(new sf::Image);
		if(!img->LoadFromFile(path + PadItoA(3, i) + ".png")) {
			exit(EXIT_FAILURE);
		}
		tileImages.push_back(img);

		SpritePtr spr(new sf::Sprite);
		spr->SetImage(*tileImages[i]);
		tileSprites.push_back(spr);
	}
}
