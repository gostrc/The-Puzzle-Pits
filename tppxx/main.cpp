#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "GameVars.hpp"
#include "common.hpp"

GameVars gamevars;

int main() {
	sf::RenderWindow window(sf::VideoMode(320, 200), "tppxx");
	gamevars.mouse->EnableDraw(true);
	while(window.IsOpened()) {
		// process events
		sf::Event event;
		while(window.PollEvent(event)) {
			// close window
			if(event.Type == sf::Event::Closed) {
				window.Close();
			}
		}

		// clear screen
		window.Clear();

		window.Draw(*gamevars.mouse);

		// update window
		window.Display();
	}

	return EXIT_SUCCESS;
}
