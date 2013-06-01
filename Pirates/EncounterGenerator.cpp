#include "EncounterGenerator.h"

EncounterGenerator::EncounterGenerator( MapBlock &mapBlock, thor::ResourceCache<sf::Texture> * cache )
    : mapBlock( mapBlock ), resourceCache( cache )
{

}

EncounterGenerator::~EncounterGenerator()
{

}

EncounterType EncounterGenerator::getEncounterType()
{
    if( mapBlock.getSquareType() == Island || mapBlock.getSquareType() == Port )
    {
        return LandHit;
    }
    else
    {
        return ShipHit;
    }
}

LandEncounter& EncounterGenerator::generateLandEncounter()
{
    return mapBlock.getLandEncounter();
}

bool EncounterGenerator::hitShip()
{
    int totalHitChance = 0;
    totalHitChance += mapBlock.getPirateSpawnChance();
    totalHitChance += mapBlock.getNavySpawnChance();
    totalHitChance += mapBlock.getNeutralSpawnChance();
    
    hitNumber = ( rand() % ( 3 * mapBlock.MAX_SPAWN_CHANCE ) );
    
    return hitNumber < totalHitChance;
}

Ship* EncounterGenerator::generateShip()
{
    if( hitNumber < mapBlock.getPirateSpawnChance() )
    {
        return generatePirateShip();
    }
    else if( hitNumber < ( mapBlock.getNavySpawnChance() + mapBlock.getPirateSpawnChance() ) )
    {
        return generateNavyShip();
    }
    else
    {
        return generateNeutralShip();
    }
}

Ship * EncounterGenerator::generatePirateShip()
{
    thor::ResourceKey<sf::Texture> shipTextureResource = thor::Resources::fromFile<sf::Texture>( "ship_pirate.png" );
    std::shared_ptr<sf::Texture> shipTexturePtr = resourceCache->acquire( shipTextureResource );
    
    return new Ship( shipTexturePtr.get(), 20, 20, 10, Pirate, Fighter, shipTexturePtr.get(), shipTexturePtr.get() );
}

Ship * EncounterGenerator::generateNavyShip()
{
    thor::ResourceKey<sf::Texture> shipTextureResource = thor::Resources::fromFile<sf::Texture>( "ship_navy.png" );
    std::shared_ptr<sf::Texture> shipTexturePtr = resourceCache->acquire( shipTextureResource );
    
    return new Ship( shipTexturePtr.get(), 20, 20, 10, Navy, Fighter, shipTexturePtr.get(), shipTexturePtr.get() );
}

Ship * EncounterGenerator::generateNeutralShip()
{
    thor::ResourceKey<sf::Texture> shipTextureResource = thor::Resources::fromFile<sf::Texture>( "ship_neutral.png" );
    std::shared_ptr<sf::Texture> shipTexturePtr = resourceCache->acquire( shipTextureResource );
    
    return new Ship( shipTexturePtr.get(), 20, 20, 10, Neutral, TransportShip, shipTexturePtr.get(), shipTexturePtr.get() );
}