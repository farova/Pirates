#include "Ship.h"

namespace Pirates
{
    Ship::Ship(
        sf::Texture * textureSmall,
        int healthMax,
        int healthCurrent,
        int speed,
        ShipAlliance alliance,
        ShipType type,
        sf::Texture * textureLarge,
        sf::Texture * textureLargeOver,
        int numCannonSlots
    )
        : MovableObject( textureSmall, healthMax, healthCurrent, speed ),
          alliance( alliance ), shipType( type ), numCannonSlots( numCannonSlots )
    {
        largeSprite.setTexture( *textureLarge );
        largeOverlaySprite.setTexture( *textureLargeOver );
        
        
        for( int i = 1; i <= numCannonSlots; ++i )
        {
            cannonSlots.push_back( new ShipCannonSlot( 9 * 50 - 50 * i, 9 * 50 ) );
        }
        
    }
    
    Ship::~Ship()
    {
        for( int i = 1; i <= numCannonSlots; ++i )
        {
            delete cannonSlots.back();
            cannonSlots.pop_back();
        }
        
    }
    
    void Ship::addCannonToSlot( Cannon * cannon )
    {
        if( cannon->isAssignedToSlot() )
            return;
            
        cannon->setIfAssignedToSlot( true );
        
        std::vector<ShipCannonSlot*>::iterator slotIt;
        
        for( slotIt = cannonSlots.begin(); slotIt != cannonSlots.end(); ++ slotIt )
        {
            if( !( *slotIt )->isOccupied() )
            {
                ( *slotIt )->setCannon( cannon );
                break;
            }
        }
    }
    
    void Ship::removeCannonFromSlot( Cannon * cannon )
    {
        if( !cannon->isAssignedToSlot() )
            return;
            
        cannon->setIfAssignedToSlot( false );
        
        std::vector<ShipCannonSlot*>::iterator slotIt;
        
        for( slotIt = cannonSlots.begin(); slotIt != cannonSlots.end(); ++ slotIt )
        {
            if( !( *slotIt )->isOccupied() && ( *slotIt )->getCannon() == cannon )
            {
                ( *slotIt )->removeCannon();
                break;
            }
        }
    }
    
    int Ship::getNumEmptySlots()
    {
        int numSlots = 0;
        
        std::vector<ShipCannonSlot*>::iterator slotIt;
        
        for( slotIt = cannonSlots.begin(); slotIt != cannonSlots.end(); ++ slotIt )
        {
            if( !( *slotIt )->isOccupied() )
                numSlots++;
        }
        
        return numSlots;
    }
    
    void Ship::drawShip( sf::RenderWindow &window )
    {
        window.draw( getLargeShipSprite() );
        
        std::vector<ShipCannonSlot*>::iterator slotIt;
        
        for( slotIt = cannonSlots.begin(); slotIt != cannonSlots.end(); ++ slotIt )
        {
            if( ( *slotIt )->isOccupied() )
                ( *slotIt )->draw( window );
        }
        
        std::list<CrewMember *>::iterator crewIterator;
        
        for ( crewIterator = crew.begin(); crewIterator != crew.end(); ++crewIterator )
        {
            ( *crewIterator )->draw( window );
        }
        
        window.draw( getLargeShipOverlaySprite() );
    }
    
    ShipAlliance Ship::getShipAlliance()
    {
        return alliance;
    }
    
    ShipType Ship::getShipType()
    {
        return shipType;
    }
    
    sf::Sprite & Ship::getLargeShipSprite()
    {
        return largeSprite;
    }
    
    sf::Sprite & Ship::getLargeShipOverlaySprite()
    {
        return largeOverlaySprite;
    }
    
    void Ship::addCrewMember( CrewMember *crewMember )
    {
        crew.push_back( crewMember );
    }
    
    void Ship::addCannon( Cannon *cannon )
    {
        cannons.push_back( cannon );
    }
    
    void Ship::addMeleeWeapon( MeleeWeapon *weapon )
    {
        armory.push_back( weapon );
    }
    
    std::list<CrewMember*> & Ship::getCrew()
    {
        return crew;
    }
    
    std::list<Cannon*> & Ship::getCannons()
    {
        return cannons;
    }
    
    std::list<MeleeWeapon*> & Ship::getArmory()
    {
        return armory;
    }
}