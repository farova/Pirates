#include "ShipActionObject.h"

namespace Pirates
{
    ShipActionObject::ShipActionObject( sf::Texture * texture )
        : Object( texture ),
          usageCoordinateX( 0 ),
          usageCoordinateY( 0 ),
          occupied( false ),
          escapeBonus( 0 ),
          hitBonus( 0 ),
          actionType( NoAction ),
          actionDirection( Right ),
          actionButtonSet( false ),
          cooldown()
    {
    
    }
    
    ShipActionObject::~ShipActionObject()
    {
    
    }
    
    void ShipActionObject::draw( sf::RenderWindow &window )
    {
        window.draw( getSprite() );
        
        if( isOccupied() )
        {
            if( isActionReady() && actionButtonSet )
            {
                // draw button
                window.draw( actionButton );
            }
            else
            {
                // draw progress bar
            }
        }
        
    }
    
    bool ShipActionObject::isActionReady()
    {
        return getCooldownElapsedTime() > cooldown;
    }
    
    void ShipActionObject::setCooldown( float time )
    {
        cooldown = sf::seconds( time );
    }
    
    void ShipActionObject::resetCooldownClock()
    {
        cooldownClock.restart();
    }
    
    sf::Time ShipActionObject::getCooldownElapsedTime()
    {
        return cooldownClock.getElapsedTime();
    }
    
    void ShipActionObject::setPosition( float x, float y )
    {
        this->getSprite().setPosition( x, y );
    }
    
    bool ShipActionObject::isActionButtonSet()
    {
        return actionButtonSet;
    }
    
    sf::Sprite & ShipActionObject::getActionButton()
    {
        if( !actionButtonSet )
            throw "NoActionButtonConfigured";
            
        return actionButton;
    }
    
    void ShipActionObject::setActionButton( sf::Texture * buttonTexture, float x, float y )
    {
        actionButton.setTexture( *buttonTexture );
        actionButton.setPosition( x, y );
        actionButtonSet = true;
    }
    
    bool ShipActionObject::isInBounds( float x, float y )
    {
        return this->getSprite().getGlobalBounds().contains( x, y );
    }
    
    void ShipActionObject::setUsageCoordinates( int x, int y )
    {
        usageCoordinateX = x;
        usageCoordinateY = y;
    }
    
    sf::Vector2i ShipActionObject::getUsageCoordinates()
    {
        return sf::Vector2i( usageCoordinateX, usageCoordinateY );
    }
    
    bool ShipActionObject::isOccupied()
    {
        return occupied;
    }
    
    void ShipActionObject::setIfOccupied( bool occ )
    {
        occupied = occ;
    }
    
    void ShipActionObject::setBonuses( float escape, float hit )
    {
        escapeBonus = escape;
        hitBonus = hit;
    }
    
    float ShipActionObject::getEscapeBonus()
    {
        return escapeBonus;
    }
    
    float ShipActionObject::getHitBonus()
    {
        return hitBonus;
    }
    
    ActionType ShipActionObject::getActionType()
    {
        return actionType;
    }
    
    void ShipActionObject::setActionType( ActionType action )
    {
        actionType = action;
    }
    
    CharacterFacingDirection ShipActionObject::getActionDirection()
    {
        return actionDirection;
    }
    
    void ShipActionObject::setActionDirection( CharacterFacingDirection dir )
    {
        actionDirection = dir;
    }
}