#include "ShipActionObjectManager.h"

namespace Pirates
{
    ShipActionObjectManager::ShipActionObjectManager()
    {
    
    }
    
    ShipActionObjectManager::~ShipActionObjectManager()
    {
    
    }
    
    std::list<ShipActionObject *> & ShipActionObjectManager::getActionObjects()
    {
        return shipActionObjects;
    }
    
    ShipActionObject * ShipActionObjectManager::handleObjectClick( int x, int y )
    {
    
        std::list<ShipActionObject *>::iterator shipObjIterator;
        
        for ( shipObjIterator = shipActionObjects.begin(); shipObjIterator != shipActionObjects.end(); ++shipObjIterator )
        {
            if( ( *shipObjIterator )->isInBounds( x, y ) )
            {
                if( !( *shipObjIterator )->isOccupied() )
                {
                    return ( *shipObjIterator );
                }
            }
        }
        
        return NULL;
    }
    
    ShipActionObject *  ShipActionObjectManager::handleButtonClick( int x, int y )
    {
        // determine if action is ready, and button was clicked for it
        std::list<ShipActionObject *>::iterator shipObjIterator;
        
        for ( shipObjIterator = shipActionObjects.begin(); shipObjIterator != shipActionObjects.end(); ++shipObjIterator )
        {
            if ( ( *shipObjIterator )->isOccupied() &&
                    ( *shipObjIterator )->isActionReady() &&
                    ( *shipObjIterator )->getActionButton().getGlobalBounds().contains( x, y ) )
            {
				return ( *shipObjIterator );
			}
        }

		return NULL;
    }
    
    void ShipActionObjectManager::resetAll()
    {
        std::list<ShipActionObject *>::iterator shipObjIterator;
        
        for ( shipObjIterator = shipActionObjects.begin(); shipObjIterator != shipActionObjects.end(); ++shipObjIterator )
            ( *shipObjIterator )->resetCooldownClock();
    }
    
    void ShipActionObjectManager::draw( sf::RenderWindow & window )
    {
        std::list<ShipActionObject *>::iterator shipObjIterator;
        
        for ( shipObjIterator = shipActionObjects.begin(); shipObjIterator != shipActionObjects.end(); ++shipObjIterator )
            ( *shipObjIterator )->draw( window );
    }
    
    void ShipActionObjectManager::loadCache( thor::ResourceCache<sf::Texture> * cache )
    {
        resourceCache = cache;
    }
    
    void ShipActionObjectManager::setPlayerShip( Ship * ship )
    {
        playerShip = ship;
    }
    
    void ShipActionObjectManager::setBlockSize( int width, int height )
    {
        blockWidth = width;
        blockHeight = height;
    }
    
    void ShipActionObjectManager::initialize()
    {
        shipActionObjects.clear();
        
        thor::ResourceKey<sf::Texture> wheelTextureResource = thor::Resources::fromFile<sf::Texture>( "shipWheel.png" );
        std::shared_ptr<sf::Texture> wheelTexturePtr = resourceCache->acquire( wheelTextureResource );
        
        thor::ResourceKey<sf::Texture> escapeButtonTextureResource = thor::Resources::fromFile<sf::Texture>( "images/button_escape.png" );
        std::shared_ptr<sf::Texture> escapeButtonTextureResourcePtr = resourceCache->acquire( escapeButtonTextureResource );
        
        ShipActionObject * captainWheel = new ShipActionObject( wheelTexturePtr.get() );
        captainWheel->setPosition( blockWidth * 11 , blockHeight * 7 );
        captainWheel->setUsageCoordinates( blockWidth * 11 , blockHeight * 7 );
        captainWheel->setActionType( SteerShip );
        captainWheel->setCooldown( 5 );
        captainWheel->setActionButton( escapeButtonTextureResourcePtr.get(), blockWidth * 12, blockHeight * 7 );
        
        
        
        
        thor::ResourceKey<sf::Texture> fireButtonTextureResource = thor::Resources::fromFile<sf::Texture>( "images/button_fire.png" );
        std::shared_ptr<sf::Texture> fireButtonTextureResourcePtr = resourceCache->acquire( fireButtonTextureResource );
        
        thor::ResourceKey<sf::Texture> cannonTexture = thor::Resources::fromFile<sf::Texture>( "images/shipCannon.png" );
        std::shared_ptr<sf::Texture> cannonTextureSPtr = resourceCache->acquire( cannonTexture );
        
        Cannon * cannon = new Cannon( cannonTextureSPtr.get() );
        ShipActionObject * cannonActionObj = new ShipActionObject( cannonTextureSPtr.get() );
        cannonActionObj->setActionType( ArmCannon );
        cannonActionObj->setCooldown( 5 );
        cannonActionObj->setActionButton( fireButtonTextureResourcePtr.get(), blockWidth * 11, blockHeight * 9 );
        
        cannon->setActionObject( cannonActionObj );
        
        playerShip->addCannonToSlot( cannon );
        
        
        
        
        // remove previous cannon and add all cannons to ActionObjectList in case new cannons bought
        
        
        
        shipActionObjects.push_back( cannonActionObj );
        
        
        shipActionObjects.push_back( captainWheel );
    }
}