#include <string>

#include "GameVars.hpp"

#include "common.hpp"

static std::string soundFilenames[] = { "crack", "magic", "plateoff", "plateon",
										"scrape", "water", "lava", "splinter", "glass" };

GameVars::GameVars() : mouse(new Mouse) {
	std::string path("../data/images/tiles/");
	std::string soundpath("../data/sounds/");

	for(int i = 0; i < NUMTILES; i++) {
		ImagePtr img(new sf::Image);
		if(!img->LoadFromFile(path + PadItoA(3, i) + ".png")) {
			exit(EXIT_FAILURE);
		}
		tileImages.push_back(img);

		SpritePtr spr(new sf::Sprite(*tileImages[i]));
		//spr->SetImage(*tileImages[i]);
		tileSprites.push_back(spr);
	}

	for(int i = 0; i < NUMSOUNDS; i++) {
		SoundBufferPtr sbp(new sf::SoundBuffer);
		sbp->LoadFromFile(soundpath + soundFilenames[i] + ".wav");
		SoundBuffers.push_back(sbp);
		SoundPtr sp(new sf::Sound(*sbp));
		Sounds.push_back(sp);
	}
}

void GameVars::PlaySound(int soundNum) {
	Sounds[soundNum]->Play();
}
