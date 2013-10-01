#include "ShipCannonSlot.h"

namespace Pirates
{
    ShipCannonSlot::ShipCannonSlot( float x, float y )
        : coordinates( sf::Vector2f( x, y ) ), occupied( false )
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
        
        cannon->getActionObject()->setPosition( coordinates.x, coordinates.y );
        cannon->getActionObject()->setUsageCoordinates( coordinates.x, coordinates.y );
        
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
        cannon->getActionObject()->draw( window );
    }
    
    bool ShipCannonSlot::isOccupied()
    {
        return occupied;
    }
}