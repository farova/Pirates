#if !defined(_SHIPMOVEMENTMANAGER_H)
#define _SHIPMOVEMENTMANAGER_H

// TAKEOUT
#include <iostream>
#include "CrewMember.h"
#include "Ship.h"
#include "ShipBlock.h"
#include "CharacterMovement.h"
// TAEKEOUT

namespace Pirates
{
    class CharacterMovementManager
    {
    
        public:
            CharacterMovementManager();
            ~CharacterMovementManager();
            
            void initialize( Ship *, int, int, int, int, ShipBlock **, list<ShipActionObject *> & );
            
            void addNewMovement( CrewMember *, int, int );
            void addNewMovement( CrewMember *, int, int, ShipActionObject * );
            void move();
            
            int getBlockWidth();
            int getBlockHeight();
            
            void stopAllMovements();
            
        private:
        
            bool DFSSearch( pair<sf::Vector2i, bool> **, sf::Vector2i, sf::Vector2i );
            bool generateShortestPath( CharacterMovement * );
            
            ShipBlock * getCurrentBlock( CrewMember * );
            ShipBlock * getCurrentBlock( float, float );
            
            ShipActionObject * getCurrentShipActionObject( float, float );
            
            sf::Vector2f getNewMovementVector( CharacterMovement * );
            
            Ship * playerShip;
            
            std::list<CharacterMovement *> currentCharacterMovements;
            
            ShipBlock** shipBlocks;
            list<ShipActionObject *> actionObjects;
            
            int numXBlocks;
            int numYBlocks;
            
            int blockWidth;;
            int blockHeight;
            
            
    };
}

#endif  //_SHIPMOVEMENTMANAGER_H
