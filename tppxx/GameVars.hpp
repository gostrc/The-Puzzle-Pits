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

	void PlaySound(int soundNum);

	SpritePtr logoSprite, titleSprite;
private:
	std::vector<ImagePtr> tileImages;
	std::vector<SpritePtr> tileSprites;

	std::vector<SoundBufferPtr> SoundBuffers;
	std::vector<SoundPtr> Sounds;

	ImagePtr logoImage, titleImage;
};
