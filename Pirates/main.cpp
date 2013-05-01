#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	int windowHeight = 800;
	int windowWidth = 800;
	sf::RenderWindow window(sf::VideoMode(windowHeight, windowWidth), "Pirates", sf::Style::Close);

	window.setFramerateLimit(60);

	Game *gameController = new Game();
	gameController->setWindowSize(windowWidth, windowHeight);
	gameController->initialize();

	
	sf::Clock frameClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			switch(event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
					
				case sf::Event::MouseButtonPressed:
					switch (event.mouseButton.button)
					{
						case sf::Mouse::Left:
							gameController->handleMouseClick(event.mouseButton.x, event.mouseButton.y);
							break;
					}
					break;
					
				case sf::Event::KeyPressed:
					gameController->handleMouseClick(event.mouseButton.x, event.mouseButton.y);
					break;
			}
        }

        window.clear();
		gameController->drawAll(window);
        window.display();
    }

    return 0;
}