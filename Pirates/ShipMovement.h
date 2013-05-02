#if !defined(_SHIPMOVEMENT_H)
#define _SHIPMOVEMENT_H

#include "CrewMember.h"
#include "ShipBlock.h"

class ShipMovement {

	public:
		ShipMovement(CrewMember*, float, float);
		~ShipMovement();
		
		void setMovementVector(float, float);

		CrewMember * getCrewMember();
		sf::Vector2f getFinalDestination();
		sf::Vector2f getMovementVector();

	private:

		CrewMember * crewMember;

		sf::Vector2f movementVector;
		sf::Vector2f finalDestination;

};

#endif  //_SHIPMOVEMENT_H
