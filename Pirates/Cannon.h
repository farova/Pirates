#if !defined(_CANNON_H)
#define _CANNON_H

#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include "ShipActionObject.h"

namespace Pirates
{
    class Cannon : public Weapon
    {
    
        public:
            Cannon( sf::Texture * );
            ~Cannon();
            
            bool isAssignedToSlot();
            void setIfAssignedToSlot( bool );
            
            ShipActionObject * getActionObject();
            void setActionObject( ShipActionObject * );
            
        private:
            bool reloaded;
            bool armed;
            bool assignedToSlot;
            
            ShipActionObject * actionObject;
            
            int ammoMax;
            int ammoCurrent;
            int attackRange;
            float reloadSpeed;
            
            
    };
}

#endif  //_CANNON_H