#if !defined(_WEAPON_H)
#define _WEAPON_H

#include <SFML/Graphics.hpp>
#include "Object.h"

namespace Pirates
{
    class Weapon : public Object
    {
    
        public:
            Weapon( sf::Texture * );
            ~Weapon();
            
            
        private:
        
            int price;
            
            float criticalChance;
            float attackSpeed;
            float baseDamage;
            
            
    };
}

#endif  //_WEAPON_H
