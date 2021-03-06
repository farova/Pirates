#if !defined(_OBJECT_H)
#define _OBJECT_H

#include <SFML/Graphics.hpp>

namespace Pirates
{
    class Object
    {
    
        public:
            Object( sf::Texture * );
            ~Object();
            
            virtual void draw( sf::RenderWindow & );
            virtual void setPosition( float, float );
            
            sf::Sprite & getSprite();
            sf::Vector2f getPosition();
            
        private:
            sf::Sprite objectSprite;
    };
}

#endif  //_OBJECT_H
