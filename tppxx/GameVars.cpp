#include <string>

#include "GameVars.hpp"

#include "common.hpp"

static std::string soundFilenames[] = { "crack", "magic", "plateoff", "plateon",
										"scrape", "water", "lava", "splinter", "glass" };

GameVars::GameVars() : mouse(new Mouse) {
	std::string path("../data/images/tiles/");
	std::string soundpath("../data/sounds/");
	std::string logotitlepath("../data/images/");

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

	// load title and logo
	titleImage = ImagePtr(new sf::Image);
	titleImage->LoadFromFile(logotitlepath + "title.png");
	titleSprite = SpritePtr(new sf::Sprite(*titleImage));

	logoImage = ImagePtr(new sf::Image);
	logoImage->LoadFromFile(logotitlepath + "logo.png");
	logoSprite = SpritePtr(new sf::Sprite(*logoImage));
}

void GameVars::PlaySound(int soundNum) {
	Sounds[soundNum]->Play();
}
