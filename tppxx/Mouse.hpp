#ifndef _MOUSE_HPP_
#define _MOUSE_HPP_

#include <SFML/Graphics.hpp>

#include <vector>

class Mouse : public sf::Sprite
{
public:
	enum POINTER{
		STDPOINTER, 
		CROSSHAIRS, 
		BRACKETCROSSHAIRS,
		UPARROWPTR,
		RIGHTARROWPTR,
		DOWNARROWPTR,
		LEFTARROWPTR,
		BUSYPOINTER,
		BLANKPOINTER
	};

	void SetPosition(int newX, int newY);
	void SetX(int newX);
	void SetY(int newY);

	void EnableDraw(bool value);

	void ChangeMouse(POINTER ptr);

	Mouse(std::vector<sf::Image>& images);
private:
	POINTER curPtr;

	std::vector<sf::Sprite> pointers;
	std::vector<int> offsetX, offsetY;

	bool draw; // if we should draw the pointer

	int x, y;

	int numPointers;

	virtual void Render(sf::RenderTarget& target, sf::Renderer& /*renderer*/) const;
};

#endif
