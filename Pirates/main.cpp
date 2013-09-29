#include <SFML/Graphics.hpp>
#include "GameController.h"

int main()
{
    int windowHeight = 1024;
    int windowWidth = 768;
    sf::RenderWindow window( sf::VideoMode( windowHeight, windowWidth ), "Pirates", sf::Style::Close );
    
    window.setFramerateLimit( 60 );
    
    GameController gameController = GameController( windowWidth, windowHeight );
    
    bool mousePressed = false;
    
	// seeds the random number generator with the current system time
    srand( ( unsigned int )time( NULL ) );
    
    while ( window.isOpen() )
    {
        sf::Event event;
        
        while ( window.pollEvent( event ) )
        {
            switch( event.type )
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::MouseButtonReleased:
                    mousePressed = false;
                    gameController.handleMouseRelease( event.mouseButton.x, event.mouseButton.y, event.mouseButton.button );
                    break;
                    
                case sf::Event::MouseMoved:
                    if( mousePressed )
                    {
                        gameController.handleMouseDrag( event.mouseMove.x, event.mouseMove.y );
                    }
                    
                    break;
                    
                case sf::Event::MouseButtonPressed:
                    mousePressed = true;
                    gameController.handleMouseClick( event.mouseButton.x, event.mouseButton.y, event.mouseButton.button );
                    break;
                    
                case sf::Event::KeyPressed:
                    gameController.handleKeyPress( event.key.code );
                    break;
            }
        }
        
        window.clear();
        gameController.draw( window );
        window.display();
    }
    
    return 0;
}