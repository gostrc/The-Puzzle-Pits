#include "Mouse.hpp"

void Mouse::SetPosition(int newX, int newY) {
	x = newX;
	y = newY;

	for(int i = 0; i < numPointers; i++) {
		pointers[i].SetPosition((float)x, (float)y);
	}
}

void Mouse::SetX(int newX) {
	x = newX;

	for(int i = 0; i < numPointers; i++) {
		pointers[i].SetX((float)x);
	}
}

void Mouse::SetY(int newY) {
	y = newY;

	for(int i = 0; i < numPointers; i++) {
		pointers[i].SetY((float)y);
	}
}

void Mouse::EnableDraw(bool value) {
	draw = value;
}

void Mouse::ChangeMouse(POINTER ptr) {
	curPtr = ptr;
}

Mouse::Mouse(std::vector<sf::Image>& images) {
	numPointers = 9;

	// set the default mouse pointer
	curPtr = STDPOINTER;

	// allocate only as much as we need, 9 pointers total
	pointers.resize(numPointers);
	offsetX.resize(numPointers);
	offsetY.resize(numPointers);

	draw = false;

	x = y = 0;

	// create sprites that we are able to use to draw the cursor from
	for(int i = 0; i < numPointers; i++) {
		// 276 is the offset the pointer images start
		pointers[i] = sf::Sprite(images[i + 276]);
	}

	pointers[STDPOINTER].SetOrigin(0.0f, 0.0f);
	pointers[CROSSHAIRS].SetOrigin(7.0f, 7.0f);
	pointers[BRACKETCROSSHAIRS].SetOrigin(7.0f, 7.0f);
	pointers[UPARROWPTR].SetOrigin(7.0f, 0.0f);
	pointers[RIGHTARROWPTR].SetOrigin(15.0f, 7.0f);
	pointers[DOWNARROWPTR].SetOrigin(7.0f, 15.0f);
	pointers[LEFTARROWPTR].SetOrigin(0.0f, 7.0f);
	pointers[BUSYPOINTER].SetOrigin(7.0f, 7.0f);
	pointers[BLANKPOINTER].SetOrigin(7.0f, 7.0f);
}

void Mouse::Render(sf::RenderTarget& target, sf::Renderer& /*renderer*/) const {
	if(draw) {
		target.Draw(pointers[curPtr]);
	}
}
