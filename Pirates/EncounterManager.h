#if !defined(_ENCOUNTERMANAGER_H)
#define _ENCOUNTERMANAGER_H

#include <Thor/Resources.hpp>

#include "MapBlock.h"
#include "Ship.h"
#include "EncounterType.h"
#include "ImagePaths.h"

class EncounterManager
{

    public:
    
        EncounterManager( thor::ResourceCache<sf::Texture> * );
        
        Constants::EncounterType getEncounterType( MapBlock * );
        
        bool tryGenerateShipEncounter( MapBlock *, Ship* );
        
    private:
    
        thor::ResourceCache<sf::Texture> * _textureCache;
        
        void generatePirateShip( Ship * );
        void generateNavyShip( Ship * );
        void generateNeutralShip( Ship * );
};

#endif