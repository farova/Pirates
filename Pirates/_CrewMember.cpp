#include "CrewMember.h"

namespace Pirates
{
    CrewMember::CrewMember( sf::Texture *texture, sf::Texture *selected, string name, int strength, int intelligence, float speed, int healthMax )
        : MovableObject( texture, speed, healthMax, healthMax ),
          name( name ), strength( strength ), intelligence( intelligence ), selected( false ), action( NoAction ), facingDirection( Right )
    {
        selectedOverlay.setTexture( *selected );
        profilePicture.setTexture( *texture );
        profilePictureSelectedOverlay.setTexture( *selected );
    }
    
    CrewMember::~CrewMember()
    {
    
    }
    
    CharacterFacingDirection CrewMember::getFacingDirection()
    {
        return facingDirection;
    }
    
    void CrewMember::setFacingDirection( CharacterFacingDirection dir )
    {
        facingDirection = dir;
    }
    
    bool CrewMember::isPerformingAction()
    {
        return action != NoAction;
    }
    
    ActionType CrewMember::getAction()
    {
        return action;
    }
    
    void CrewMember::stopPerformingAction()
    {
        this->action = NoAction;
    }
    
    void CrewMember::performAction( ActionType action )
    {
        this->action = action;
    }
    
    void CrewMember::draw( sf::RenderWindow &window )
    {
        Object::draw( window );	//call parent implementation of function
        
        window.draw( profilePicture );
        
        if( isCharacterSelected() )
        {
            window.draw( selectedOverlay );
            window.draw( profilePictureSelectedOverlay );
        }
        
        if( isPerformingAction() )
        {
            // draw action!
        }
        
    }
    
    void CrewMember::move( float x, float y )
    {
        if( isDead() )
            return;
            
        MovableObject::move( x, y );
        selectedOverlay.move( x, y );
    }
    
    void CrewMember::setPosition( float x, float y )
    {
        Object::setPosition( x, y );
        selectedOverlay.setPosition( x, y );
    }
    
    void CrewMember::setProfilePicturePosition( float x, float y )
    {
        profilePicture.setPosition( x, y );
    }
    
    void CrewMember::setProfilePictureSelectedOverlayPosition( float x, float y )
    {
        profilePictureSelectedOverlay.setPosition( x, y );
    }
    
    int CrewMember::getStrength()
    {
        return strength;
    }
    
    sf::Sprite & CrewMember::getProfileSprite()
    {
        return profilePicture;
    }
    
    string CrewMember::getName()
    {
        return name;
    }
    
    int CrewMember::getIntelligence()
    {
        return intelligence;
    }
    
    void CrewMember::setStrength( int amount )
    {
        strength = amount;
    }
    
    void CrewMember::setIntelligence( int amount )
    {
        intelligence = amount;
    }
    
    
    bool CrewMember::isCharacterSelected()
    {
        return selected;
    }
    
    void CrewMember::toggleSelect()
    {
        selected = !selected;
    }
    
    void CrewMember::Select()
    {
        selected = true;
    }
    
    void CrewMember::Deselect()
    {
        selected = false;
    }
}