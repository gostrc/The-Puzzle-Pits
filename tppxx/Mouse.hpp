#ifndef _MOUSE_HPP_
#define _MOUSE_HPP_

#include <SFML/Graphics.hpp>

#include <vector>

#include "common.hpp"

class Mouse : public sf::Drawable
{
public:
	void SetPosition(int newX, int newY);
	void SetX(int newX);
	void SetY(int newY);

	void EnableDraw(bool value);

	void ChangeMouse(POINTER ptr);

	Mouse();
private:
	POINTER curPtr;

	std::vector<ImagePtr> tileImages;
	std::vector<SpritePtr> tileSprites;

	bool draw; // if we should draw the pointer

	int x, y;

	int numPointers;

	virtual void Render(sf::RenderTarget& target, sf::Renderer& /*renderer*/) const;
};

#endif
