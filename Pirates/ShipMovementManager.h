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
		void move();
		
		const int BLOCK_HEIGHT;
		const int BLOCK_WIDTH;

	private:
		
		bool DFSSearch(pair<sf::Vector2i, bool> **, sf::Vector2i, sf::Vector2i);

		ShipBlock * getCurrentBlock(CrewMember *);
		ShipBlock * getCurrentBlock(float, float);
		sf::Vector2f getNewMovementVector(ShipMovement *);
		bool generateShortestPath(ShipMovement *);

		Ship * playerShip;

		std::list<ShipMovement *> currentShipMovements;
		ShipBlock** shipBlocks;

};

#endif  //_SHIPMOVEMENTMANAGER_H
