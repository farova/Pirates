#if !defined(_SHIPMOVEMENTMANAGER_H)
#define _SHIPMOVEMENTMANAGER_H

#include "CrewMember.h"
#include "ShipBlock.h"
#include "ShipMovement.h"

class ShipMovementManager {

	public:
		ShipMovementManager();
		~ShipMovementManager();
		
		void addShipBlock(ShipBlock *);
		void addShipBlockPath(ShipBlockPath *);

		void addNewMovement(CrewMember *, ShipBlock *);
		void move(sf::RenderWindow &);

	private:
		std::list<ShipMovement *> currentShipMovements;

		std::list<ShipBlock*> shipBlocks;
		std::list<ShipBlockPath*> shipPaths;

};

#endif  //_SHIPMOVEMENTMANAGER_H
