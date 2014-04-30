#include "EncounterManager.h"

EncounterManager::EncounterManager( thor::ResourceCache<sf::Texture> * resourceCache )
{
    _textureCache = resourceCache;
}

Constants::EncounterType EncounterManager::getEncounterType( MapBlock * mapBlock )
{
    if( mapBlock->getMapBlockType() == Constants::MapBlockTypeIsland ||
            mapBlock->getMapBlockType() == Constants::MapBlockTypePort )
    {
        return Constants::EncounterTypeIsland;
    }
    else
    {
        return Constants::EncounterTypeShip;
    }
}

bool EncounterManager::tryGenerateShipEncounter( MapBlock * mapBlock, Ship* enemyShip )
{
    int totalHitChance = 0;
    totalHitChance += mapBlock->getPirateSpawnChance();
    totalHitChance += mapBlock->getNavySpawnChance();
    totalHitChance += mapBlock->getNeutralSpawnChance();
    
    int hitNumber = ( rand() % ( 3 * mapBlock->MAX_SPAWN_CHANCE ) );
    bool hitShip = hitNumber < totalHitChance;
    
    if( hitShip )
    {
        if( hitNumber < mapBlock->getPirateSpawnChance() )
        {
            generatePirateShip( enemyShip );
        }
        else if( hitNumber < ( mapBlock->getNavySpawnChance() + mapBlock->getPirateSpawnChance() ) )
        {
            generateNavyShip( enemyShip );
        }
        else
        {
            generateNeutralShip( enemyShip );
        }
    }
    
    return hitShip;
}

void EncounterManager::generatePirateShip( Ship * enemyShip )
{
    thor::ResourceKey<sf::Texture> shipTextureResource = thor::Resources::fromFile<sf::Texture>( Constants::imagePirateShip );
    std::shared_ptr<sf::Texture> shipTexturePtr = _textureCache->acquire( shipTextureResource );
    
    enemyShip->initializeNewShip(
        shipTexturePtr,
        shipTexturePtr,
        shipTexturePtr
    );
}

void EncounterManager::generateNavyShip( Ship * enemyShip )
{
    thor::ResourceKey<sf::Texture> shipTextureResource = thor::Resources::fromFile<sf::Texture>( Constants::imageNavyShip );
    std::shared_ptr<sf::Texture> shipTexturePtr = _textureCache->acquire( shipTextureResource );
    
    enemyShip->initializeNewShip(
        shipTexturePtr,
        shipTexturePtr,
        shipTexturePtr
    );
}

void EncounterManager::generateNeutralShip( Ship * enemyShip )
{
    thor::ResourceKey<sf::Texture> shipTextureResource = thor::Resources::fromFile<sf::Texture>( Constants::imageNeutralShip );
    std::shared_ptr<sf::Texture> shipTexturePtr = _textureCache->acquire( shipTextureResource );
    
    enemyShip->initializeNewShip(
        shipTexturePtr,
        shipTexturePtr,
        shipTexturePtr
    );
}