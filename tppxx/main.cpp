#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "GameVars.hpp"
#include "common.hpp"

#include <iostream>
using namespace std;

GameVars gamevars;

int main() {
	sf::RenderWindow window(sf::VideoMode(320, 200), "tppxx");
	window.ShowMouseCursor(false);

	gamevars.mouse->EnableDraw(true);

	while(window.IsOpened()) {
		// process events
		sf::Event event;
		while(window.PollEvent(event)) {
			// close window
			if(event.Type == sf::Event::Closed) {
				// close the window
				window.Close();
			} else if(event.Type == sf::Event::MouseMoved) {
				// update the mouse position
				gamevars.mouse->SetPosition(event.MouseMove.X, event.MouseMove.Y);
			}
		}

		// clear screen
		window.Clear();

		// draw the mouse pointer
		window.Draw(*gamevars.mouse);

		// update window
		window.Display();
	}

	return EXIT_SUCCESS;
}
