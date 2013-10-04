#include "MapBlock.h"

MapBlock::MapBlock(
    Constants::MapBlockType blockType,
    std::shared_ptr<sf::Texture> blockTexture,
    float x, float y,
    float navySpawn, Constants::Difficulty navyDifficulty, // Navy
    float pirateSpawn, Constants::Difficulty pirateDifficulty, // Pirate
    float neutralSpawn // Neutral
)
    : _type( blockType ),
      _pirateSpawnChance( pirateSpawn ),
      _navySpawnChance( navySpawn ),
      _neutralSpawnChance( neutralSpawn ),
      _pirateMaxDifficulty( pirateDifficulty ),
      _navyMaxDifficulty( navyDifficulty )
{

    _blockSprite.setTexture( *blockTexture );
    _blockSprite.setPosition( x, y );
}

void MapBlock::draw( sf::RenderWindow &window )
{
    window.draw( _blockSprite );
}

Constants::MapBlockType MapBlock::getMapBlockType()
{
    return _type;
}

Constants::Difficulty MapBlock::getPirateMaxDifficulty()
{
    return _pirateMaxDifficulty;
}

Constants::Difficulty MapBlock::getNavyMaxDifficulty()
{
    return _navyMaxDifficulty;
}

float MapBlock::getPirateSpawnChance()
{
    return _pirateSpawnChance;
}

float MapBlock::getNavySpawnChance()
{
    return _navySpawnChance;
}

float MapBlock::getNeutralSpawnChance()
{
    return _neutralSpawnChance;
}