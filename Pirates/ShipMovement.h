#if !defined(_SHIPMOVEMENT_H)
#define _SHIPMOVEMENT_H

#include "CrewMember.h"
#include "ShipBlock.h"

class ShipMovement {

	public:
		ShipMovement(CrewMember*, ShipBlock*, ShipBlock*);
		~ShipMovement();
		
		bool reachedNextDestination();
		bool reachedFinalDestination();

		void setNextDestination(ShipBlock *);

		sf::Vector2f getnextDestinationDirection();

	private:

		bool onPath; // determine if following the path, or still finding the start of the path

		CrewMember * crewMember;

		ShipBlock * nextDestination;
		ShipBlock * finalDestination;

};

#endif  //_SHIPMOVEMENT_H
