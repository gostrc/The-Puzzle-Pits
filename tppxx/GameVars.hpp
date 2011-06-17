#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "common.hpp"
#include "Mouse.hpp"

class GameVars {
public:
	GameVars();

	std::shared_ptr<Mouse> mouse;

	void PlaySound(int soundNum);

	std::shared_ptr<sf::Sprite> logoSprite, titleSprite;
private:
	std::vector<std::shared_ptr<sf::Image>> tileImages;
	std::vector<std::shared_ptr<sf::Sprite>> tileSprites;

	std::vector<std::shared_ptr<sf::SoundBuffer>> SoundBuffers;
	std::vector<std::shared_ptr<sf::Sound>> Sounds;

	std::shared_ptr<sf::Image> logoImage, titleImage;
};
