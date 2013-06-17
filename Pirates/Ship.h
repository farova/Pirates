#if !defined(_SHIP_H)
#define _SHIP_H

#include <list>
#include "MovableObject.h"
#include "Constants.h"
#include "CrewMember.h"
#include "Cannon.h"
#include "ShipCannonSlot.h"

namespace Pirates
{
    class Ship : public MovableObject
    {
    
        public:
            Ship( sf::Texture *, int, int, int, ShipAlliance, ShipType, sf::Texture *, sf::Texture *, int );
            ~Ship();
            
            ShipAlliance getShipAlliance();
            ShipType getShipType();
            
            void drawShip( sf::RenderWindow & );
            
            void addCrewMember( CrewMember * );
            void addCannon( Cannon * );
            void addMeleeWeapon( MeleeWeapon * );
            
            void addCannonToSlot( Cannon * );
            void removeCannonFromSlot( Cannon * );
            int getNumEmptySlots();
            
            std::list<CrewMember*> & getCrew();
            std::list<Cannon*> & getCannons();
            std::list<MeleeWeapon*> & getArmory();
            
            sf::Sprite & getLargeShipSprite();
            sf::Sprite & getLargeShipOverlaySprite();
            
        private:
            //general ship properties
            ShipAlliance alliance;
            ShipType shipType;
            
            sf::Sprite largeSprite;
            sf::Sprite largeOverlaySprite;
            
            // weapons and crew pointers
            std::list<Cannon*> cannons;
            std::list<MeleeWeapon*> armory;
            std::list<CrewMember*> crew;
            CrewMember* captain;
            std::vector<ShipCannonSlot*> cannonSlots;
            
            // ship storage
            int gold;
            int repairMaterial;
            int numCannonSlots;
            
            
    };
}

#endif  //_SHIP_H
