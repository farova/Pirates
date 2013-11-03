#if !defined(_SHIP_H)
#define _SHIP_H

#include <list>
#include <memory>
#include <SFML/Graphics.hpp>

class Ship
{

    public:
        Ship();
        ~Ship();
        
        void drawSmallShip( sf::RenderWindow & );
        void drawLargeShip( sf::RenderWindow & );

		void setMapPosition( int, int, int );
		void initializeNewShip(
			std::shared_ptr<sf::Texture>, //small ship texture
			std::shared_ptr<sf::Texture>, //large ship texture
			std::shared_ptr<sf::Texture>  //large ship overlay texture
		);
        
    private:
    
        int _x;
        int _y;

		sf::Sprite _smallSprite;
        sf::Sprite _largeSprite;
        sf::Sprite _largeOverlaySprite;
        
};

#endif