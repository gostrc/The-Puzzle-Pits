#ifndef _COMMON_HPP_
#define _COMMON_HPP_

#include <boost/shared_ptr.hpp>

#include <SFML/Graphics.hpp>

#include <sstream>
#include <iomanip>

const int STDPOINTER = 0;
const int CROSSHAIRS = 1;
const int BRACKETCROSSHAIRS = 2;
const int UPARROWPTR = 3;
const int RIGHTARROWPTR = 4;
const int DOWNARROWPTR = 5;
const int LEFTARROWPTR = 6;
const int BUSYPOINTER = 7;
const int BLANKPOINTER = 8;

typedef int POINTER;
const int NUMPOINTERS = 9;

const int NUMTILES = 276;

class Mouse;
typedef boost::shared_ptr<Mouse> MousePtr;

typedef boost::shared_ptr<sf::Image> ImagePtr;
typedef boost::shared_ptr<sf::Sprite> SpritePtr;

// returns a padded string representation of a number
std::string PadItoA(int numPad, int number);

#endif
