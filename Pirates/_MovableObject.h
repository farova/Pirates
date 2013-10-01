#if !defined(_MOVEABLEOBJECT_H)
#define _MOVEABLEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Object.h"

namespace Pirates
{
    class MovableObject : public Object
    {
    
        public:
            MovableObject( sf::Texture *, float, int, int );
            
            bool isDead();
            
            virtual void move( float, float );
            
            float getSpeed();
            int getCurrentHealth();
            int getMaxHealth();
            
            void takeDamage( int );
            void restoreHealth( int );
            void restoreFullHealth();
            
        private:
            float speed;
            int healthMax;
            int healthCurrent;
            
            
    };
}

#endif  //_MOVEABLEOBJECT_H
