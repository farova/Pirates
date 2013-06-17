#include "Object.h"

namespace Pirates
{
    Object::Object( sf::Texture *texture )
    {
        objectSprite.setTexture( *texture );
    }
    
    Object::~Object()
    {
        // nothing
    }
    
    void Object::draw( sf::RenderWindow &renderWindow )
    {
        renderWindow.draw( objectSprite );
    }
    
    void Object::setPosition( float x, float y )
    {
        objectSprite.setPosition( x, y );
    }
    
    sf::Vector2f Object::getPosition()
    {
        return objectSprite.getPosition();
    }
    
    sf::Sprite & Object::getSprite()
    {
        return objectSprite;
    }
}