#include "Ship.h"


Ship::Ship()
{

}

Ship::~Ship()
{

}
void Ship::setMapPosition( int x, int y, int blockSize )
{
    _x = x;
    _y = y;
    
    _smallSprite.setPosition( ( int ) x * blockSize, ( int ) y * blockSize );
}

sf::Vector2i Ship::getMapPosition()
{
    return sf::Vector2i( _x, _y );
}

void Ship::initializeNewShip(
    std::shared_ptr<sf::Texture> smallShipTxtr, //small ship texture
    std::shared_ptr<sf::Texture> largeShipTxtr, //large ship texture
    std::shared_ptr<sf::Texture> largeShipOverlayTxtr  //large ship overlay texture
)
{
    _smallSprite.setTexture( *smallShipTxtr );
    _largeSprite.setTexture( *largeShipTxtr );
    _largeOverlaySprite.setTexture( *largeShipOverlayTxtr );
}

void Ship::drawSmallShip( sf::RenderWindow & window )
{
    window.draw( _smallSprite );
}

void Ship::drawLargeShip( sf::RenderWindow & window )
{
    window.draw( _largeSprite );
    window.draw( _largeOverlaySprite );
}