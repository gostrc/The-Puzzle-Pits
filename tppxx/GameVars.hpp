#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Mouse.hpp"

class GameVars {
public:
	GameVars();

	Mouse* mouse;
private:
	std::vector<sf::Image> tileImages;
	std::vector<sf::Sprite> tileSprites;
};
