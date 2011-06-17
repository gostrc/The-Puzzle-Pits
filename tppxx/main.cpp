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
	window.SetFramerateLimit(60);

	gamevars.mouse->EnableDraw(true);
	gamevars.mouse->ChangeMouse(CROSSHAIRS);

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
			} else if(event.Type == sf::Event::KeyPressed) {
				if(event.Key.Code == sf::Key::Left) {
					cout << "left button pressed" << endl;
					gamevars.PlaySound(SND_MAGIC);
				}
				if(event.Key.Code == sf::Key::Right) {
					cout << "right button pressed" << endl;
					gamevars.PlaySound(SND_CRACK);
				}
				if(event.Key.Code == sf::Key::Up) {
					cout << "up button pressed" << endl;
					gamevars.PlaySound(SND_WATER);
				}
				if(event.Key.Code == sf::Key::Down) {
					cout << "down button pressed" << endl;
					gamevars.PlaySound(SND_LAVA);
				}
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
