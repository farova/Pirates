#if !defined(_SHIPCANNONSOT_H)
#define _SHIPCANNONSOT_H

#include <SFML/Graphics.hpp>
#include "Cannon.h"

namespace Pirates
{
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
}

#endif  //_SHIPCANNONSOT_H