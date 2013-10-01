#if !defined(_ENCOUNTERGENERATOR_H)
#define _ENCOUNTERGENERATOR_H

#include <Thor/Resources.hpp>
#include "LandEncounter.h"
#include "Ship.h"
#include "MapBlock.h"

namespace Pirates
{
    class EncounterGenerator
    {
    
        public:
            EncounterGenerator( MapBlock &, thor::ResourceCache<sf::Texture> * );
            ~EncounterGenerator();
            
            EncounterType getEncounterType();
            
            bool hitShip();
            
            LandEncounter& generateLandEncounter();
            Ship* generateShip();
            
        private:
        
            Ship * generatePirateShip();
            Ship * generateNavyShip();
            Ship * generateNeutralShip();
            
            MapBlock mapBlock;
            int hitNumber;
            
            thor::ResourceCache<sf::Texture> * resourceCache;
            
            
    };
}

#endif  //_ENCOUNTERGENERATOR_H
