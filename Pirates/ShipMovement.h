#if !defined(_SHIPMOVEMENT_H)
#define _SHIPMOVEMENT_H

#include "CrewMember.h"
#include "ShipBlock.h"

class ShipMovement {

	public:
		ShipMovement(CrewMember*, float, float);
		~ShipMovement();
		
		void setMovementVector(float, float);
		void setMovementVector(sf::Vector2f);
		void setShortestPath(std::list<ShipBlock *>);
		void setFinished(bool);

		bool isFinished();

		CrewMember * getCrewMember();
		sf::Vector2f getFinalDestination();
		sf::Vector2f getMovementVector();
		std::list<ShipBlock *> & getShortestPath();

	private:

		bool finished;

		CrewMember * crewMember;

		std::list<ShipBlock *> shortestPath;

		sf::Vector2f movementVector;
		sf::Vector2f finalDestination;

};

#endif  //_SHIPMOVEMENT_H
