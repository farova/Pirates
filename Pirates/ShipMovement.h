#if !defined(_SHIPMOVEMENT_H)
#define _SHIPMOVEMENT_H

#include "CrewMember.h"
#include "ShipBlock.h"

enum MovementStatus {Initial, Moving, Final, Finished};

class ShipMovement {

	public:
		ShipMovement(CrewMember*, float, float);
		~ShipMovement();
		
		void setMovementVector(float, float);
		void setMovementVector(sf::Vector2f);
		void setShortestPath(std::list<ShipBlock *>);
		void setStatus(MovementStatus);

		MovementStatus getStatus();
		CrewMember * getCrewMember();
		sf::Vector2f getFinalDestination();
		sf::Vector2f getMovementVector();
		std::list<ShipBlock *> & getShortestPath();

	private:

		MovementStatus movementStatus;

		CrewMember * crewMember;

		std::list<ShipBlock *> shortestPath;

		sf::Vector2f movementVector;
		sf::Vector2f finalDestination;

};

#endif  //_SHIPMOVEMENT_H
