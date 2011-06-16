#include <boost/shared_ptr.hpp>

#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "common.hpp"
#include "Mouse.hpp"

class GameVars {
public:
	GameVars();

	MousePtr mouse;
private:
	std::vector<ImagePtr> tileImages;
	std::vector<SpritePtr> tileSprites;
};
