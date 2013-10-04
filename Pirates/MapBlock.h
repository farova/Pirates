#if !defined(_MAPBLOCK_H)
#define _MAPBLOCK_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "Difficulty.h"
#include "MapBlockType.h"

class MapBlock : IDrawable
{

    public:

		static const int MAX_SPAWN_CHANCE = 100;

        MapBlock(
			Constants::MapBlockType,
			std::shared_ptr<sf::Texture>,
			float, float, // Positions
			float, Constants::Difficulty, // Navy
            float, Constants::Difficulty, // Pirate
            float // Neutral
        );
        
		// --- IDrawable
        void draw( sf::RenderWindow & );
        
        Constants::MapBlockType getMapBlockType();
        
        Constants::Difficulty getPirateMaxDifficulty();
        Constants::Difficulty getNavyMaxDifficulty();
        
        float getPirateSpawnChance();
        float getNavySpawnChance();
        float getNeutralSpawnChance();
        
    private:
    
        Constants::MapBlockType _type;
        
        // Graphics
        sf::Sprite _blockSprite;
        
        // enemies spawn
        float _pirateSpawnChance;
        float _navySpawnChance;
        float _neutralSpawnChance;
        Constants::Difficulty _pirateMaxDifficulty;
        Constants::Difficulty _navyMaxDifficulty;
};

#endif
