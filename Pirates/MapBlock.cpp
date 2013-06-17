#include "MapBlock.h"

namespace Pirates
{
    MapBlock::MapBlock()
        : initialized( false ), pirateSpawnChance( 0 ), navySpawnChance( 0 ), neutralSpawnChance( 0 ), pirateMaxDifficulty( Easy ), navyMaxDifficulty( Easy ), MAX_SPAWN_CHANCE( 100 )
    {
    
    }
    
    MapBlock::~MapBlock()
    {
    
    }
    
    void MapBlock::initialize( int x, int y, SquareType type, sf::Texture &texture )
    {
        this->type = type;
        this->blockSprite.setTexture( texture );
        this->blockSprite.setPosition( x, y );
        
        initialized = true;
    }
    
    void MapBlock::setLandEncounter( LandEncounter &land )
    {
        landEncouterObject = land;
        landEncounter = true;
    }
    
    LandEncounter & MapBlock::getLandEncounter()
    {
        return landEncouterObject;
    }
    
    bool MapBlock::isLandEncounter()
    {
        return landEncounter;
    }
    
    void MapBlock::setPirateParameters( float chance, Difficulty diff )
    {
        chance = chance > 0 ? chance : 0;
        pirateSpawnChance = chance > MAX_SPAWN_CHANCE ? MAX_SPAWN_CHANCE : chance;
        pirateMaxDifficulty = diff;
    }
    
    void MapBlock::setNavyParameters( float chance, Difficulty diff )
    {
        chance = chance > 0 ? chance : 0;
        navySpawnChance = chance > MAX_SPAWN_CHANCE ? MAX_SPAWN_CHANCE : chance;
        navyMaxDifficulty = diff;
    }
    
    void MapBlock::setNeutralParameters( float chance )
    {
        chance = chance > 0 ? chance : 0;
        neutralSpawnChance = chance > MAX_SPAWN_CHANCE ? MAX_SPAWN_CHANCE : chance;
    }
    
    void MapBlock::draw( sf::RenderWindow &window )
    {
        if( !isInitialized() )
            return;
            
        window.draw( blockSprite );
    }
    
    bool MapBlock::isInitialized()
    {
        return initialized;
    }
    
    SquareType MapBlock::getSquareType()
    {
        return type;
    }
    
    Difficulty MapBlock::getPirateMaxDifficulty()
    {
        return pirateMaxDifficulty;
    }
    
    Difficulty MapBlock::getNavyMaxDifficulty()
    {
        return navyMaxDifficulty;
    }
    
    float MapBlock::getPirateSpawnChance()
    {
        return pirateSpawnChance;
    }
    
    float MapBlock::getNavySpawnChance()
    {
        return navySpawnChance;
    }
    
    float MapBlock::getNeutralSpawnChance()
    {
        return neutralSpawnChance;
    }
}