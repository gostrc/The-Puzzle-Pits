#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(320, 200), "tppxx");
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

		// update window
		window.Display();
	}

	return EXIT_SUCCESS;
}
