#ifndef _COMMON_HPP_
#define _COMMON_HPP_

#include <memory>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <sstream>
#include <iomanip>

typedef int POINTER;
const int STDPOINTER = 0;
const int CROSSHAIRS = 1;
const int BRACKETCROSSHAIRS = 2;
const int UPARROWPTR = 3;
const int RIGHTARROWPTR = 4;
const int DOWNARROWPTR = 5;
const int LEFTARROWPTR = 6;
const int BUSYPOINTER = 7;
const int BLANKPOINTER = 8;
const int NUMPOINTERS = 9;

const int SND_CRACK = 0;
const int SND_MAGIC = 1;
const int SND_PLATEOFF = 2;
const int SND_PLATEON = 3;
const int SND_SCRAPE = 4;
const int SND_WATER = 5;
const int SND_LAVA = 6;
const int SND_SPLINTER = 7;
const int SND_GLASS = 8;
const int NUMSOUNDS = 9;

const int NUMTILES = 276;

class Mouse;
typedef std::shared_ptr<Mouse> MousePtr;

typedef std::shared_ptr<sf::Image> ImagePtr;
typedef std::shared_ptr<sf::Sprite> SpritePtr;

typedef std::shared_ptr<sf::SoundBuffer> SoundBufferPtr;
typedef std::shared_ptr<sf::Sound> SoundPtr;

// returns a padded string representation of a number
std::string PadItoA(int numPad, int number);

#endif
