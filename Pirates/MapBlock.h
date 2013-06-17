#if !defined(_MAPBLOCK_H)
#define _MAPBLOCK_H

#include <SFML/Graphics.hpp>
#include "LandEncounter.h"
#include "Constants.h"

namespace Pirates
{
    class MapBlock
    {
    
        public:
            MapBlock();
            ~MapBlock();
            
            void draw( sf::RenderWindow & );
            
            void initialize( int, int, SquareType, sf::Texture & );
            bool isInitialized();
            
            void setLandEncounter( LandEncounter & );
            LandEncounter & getLandEncounter();
            bool isLandEncounter();
            
            void setPirateParameters( float, Difficulty );
            void setNavyParameters( float, Difficulty );
            void setNeutralParameters( float );
            
            SquareType getSquareType();
            
            Difficulty getPirateMaxDifficulty();
            Difficulty getNavyMaxDifficulty();
            
            float getPirateSpawnChance();
            float getNavySpawnChance();
            float getNeutralSpawnChance();
            
            const int MAX_SPAWN_CHANCE;
            
        private:
        
            bool cacheLoaded;
            bool initialized;
            
            SquareType type;
            
            bool landEncounter;
            LandEncounter landEncouterObject;
            
            // enemies spawn
            float pirateSpawnChance;
            float navySpawnChance;
            float neutralSpawnChance;
            Difficulty pirateMaxDifficulty;
            Difficulty navyMaxDifficulty;
            
            // Graphics
            sf::Sprite blockSprite;
            
    };
}

#endif  //_MAPBLOCK_H
