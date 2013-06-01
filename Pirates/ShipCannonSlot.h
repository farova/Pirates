#if !defined(_SHIPCANNONSOT_H)
#define _SHIPCANNONSOT_H

#include "Constants.h"
#include "Cannon.h"
#include <SFML/Graphics.hpp>

class ShipCannonSlot
{

    public:
    
        ShipCannonSlot( float, float );
        ~ShipCannonSlot();
        
        void draw( sf::RenderWindow & );
        
        void setCannon( Cannon * );
        void removeCannon();
        
        Cannon* getCannon();
        
        bool isOccupied();
        
    private:
    
        Cannon* cannon;
        bool occupied;
        sf::Vector2f coordinates;
        
};

#endif  //_SHIPCANNONSOT_H