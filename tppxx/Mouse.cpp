#include "Mouse.hpp"

#include "common.hpp"

void Mouse::SetPosition(int newX, int newY) {
	x = newX;
	y = newY;

	for(int i = 0; i < NUMPOINTERS; i++) {
		tileSprites[i]->SetPosition((float)x, (float)y);
	}
}

void Mouse::SetX(int newX) {
	x = newX;

	for(int i = 0; i < NUMPOINTERS; i++) {
		tileSprites[i]->SetX((float)x);
	}
}

void Mouse::SetY(int newY) {
	y = newY;

	for(int i = 0; i < NUMPOINTERS; i++) {
		tileSprites[i]->SetY((float)y);
	}
}

void Mouse::EnableDraw(bool value) {
	draw = value;
}

void Mouse::ChangeMouse(POINTER ptr) {
	curPtr = ptr;
}

Mouse::Mouse() {
	std::string path("../data/images/pointers/");

	// set the default mouse pointer
	curPtr = STDPOINTER;

	draw = false;

	x = y = 0;

	for(int i = 0; i < NUMPOINTERS; i++) {
		ImagePtr img(new sf::Image);
		if(!img->LoadFromFile(path + PadItoA(1, i) + ".png")) {
			exit(EXIT_FAILURE);
		}
		tileImages.push_back(img);

		SpritePtr spr(new sf::Sprite(*tileImages[i]));
		//spr->SetImage(*tileImages[i]);
		tileSprites.push_back(spr);
	}

	tileSprites[STDPOINTER]->SetOrigin(0.0f, 0.0f);
	tileSprites[CROSSHAIRS]->SetOrigin(7.0f, 7.0f);
	tileSprites[BRACKETCROSSHAIRS]->SetOrigin(7.0f, 7.0f);
	tileSprites[UPARROWPTR]->SetOrigin(7.0f, 0.0f);
	tileSprites[RIGHTARROWPTR]->SetOrigin(15.0f, 7.0f);
	tileSprites[DOWNARROWPTR]->SetOrigin(7.0f, 15.0f);
	tileSprites[LEFTARROWPTR]->SetOrigin(0.0f, 7.0f);
	tileSprites[BUSYPOINTER]->SetOrigin(7.0f, 7.0f);
	tileSprites[BLANKPOINTER]->SetOrigin(7.0f, 7.0f);
}

void Mouse::Render(sf::RenderTarget& target, sf::Renderer& /*renderer*/) const {
	if(draw) {
		target.Draw(*(tileSprites[curPtr]));
	}
}
