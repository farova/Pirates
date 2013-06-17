#if !defined(_CharacterMovement_H)
#define _CharacterMovement_H

#include <list>
#include "CrewMember.h"
#include "ShipActionObject.h"
#include "ShipBlock.h"

namespace Pirates
{
    class CharacterMovement
    {
    
        public:
            CharacterMovement( CrewMember*, float, float );
            ~CharacterMovement();
            
            void setMovementVector( float, float );
            void setMovementVector( sf::Vector2f );
            void setShortestPath( std::list<ShipBlock *> );
            void setStatus( MovementStatus );
            
            bool hasAction();
            ShipActionObject * getActionObject();
            void setActionObject( ShipActionObject * );
            
            MovementStatus getStatus();
            CrewMember * getCrewMember();
            sf::Vector2f getFinalDestination();
            sf::Vector2f getMovementVector();
            std::list<ShipBlock *> & getShortestPath();
            
        private:
        
            ShipActionObject * actionObject;
            
            MovementStatus movementStatus;
            
            CrewMember * crewMember;
            
            std::list<ShipBlock *> shortestPath;
            
            sf::Vector2f movementVector;
            sf::Vector2f finalDestination;
            
    };
}

#endif  //_CharacterMovement_H
