#if !defined(_SHIP_H)
#define _SHIP_H

#include <list>
#include <SFML/Graphics.hpp>


class Ship
{

    public:
        Ship();
        ~Ship();

		void drawSmallShip( sf::RenderWindow & );
		void drawLargeShip( sf::RenderWindow & );
        
        
    private:

        sf::Sprite largeSprite;
        sf::Sprite largeOverlaySprite;
        
};

#endif