#include "ShipCannonSlot.h"


ShipCannonSlot::ShipCannonSlot( float x, float y )
    : coordinates( sf::Vector2f( x, y ) )
{

}

ShipCannonSlot::~ShipCannonSlot()
{

}

void ShipCannonSlot::setCannon( Cannon * cannon )
{
    if( cannon == NULL )
        return;
        
    occupied = true;
    this->cannon = cannon;
}

Cannon* ShipCannonSlot::getCannon()
{
    return cannon;
}

void ShipCannonSlot::removeCannon()
{
    cannon = NULL;
    occupied = false;
}

void ShipCannonSlot::draw( sf::RenderWindow & window )
{
    cannon->draw( window );
}

bool ShipCannonSlot::isOccupied()
{
    return occupied;
}
