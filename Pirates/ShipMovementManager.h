#if !defined(_SHIPMOVEMENTMANAGER_H)
#define _SHIPMOVEMENTMANAGER_H

#include "CrewMember.h"
#include "ShipBlock.h"
#include "Ship.h"
#include "ShipMovement.h"

class ShipMovementManager {

	public:
		ShipMovementManager();
		~ShipMovementManager();
		
		void initialize(Ship *);

		void addNewMovement(CrewMember *, int, int);
		void move(sf::RenderWindow &);

	private:
		
		Ship * playerShip;
		ShipBlock * getCurrentBlock(CrewMember *);

		std::list<ShipMovement *> currentShipMovements;
		ShipBlock** shipBlocks;

		int blockWidth;
		int blockHeight;

};

#endif  //_SHIPMOVEMENTMANAGER_H
