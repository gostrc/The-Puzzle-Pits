#include <SFML/Graphics.hpp>

#include <vector>
using std::vector;

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

	void SetX(int newX);
	void SetY(int newY);

	void EnableDraw(bool value);

	void ChangeMouse(POINTER ptr);

	Mouse(vector<sf::Image>& images);
private:
	POINTER curPtr;

	vector<sf::Sprite> pointers;
	vector<int> offsetX, offsetY;

	bool draw; // if we should draw the pointer

	int x, y;

	virtual void Render(sf::RenderTarget& target, sf::Renderer& /*renderer*/) const;
};
