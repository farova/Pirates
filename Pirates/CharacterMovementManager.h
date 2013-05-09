#if !defined(_SHIPMOVEMENTMANAGER_H)
#define _SHIPMOVEMENTMANAGER_H

#include "Constants.h"
#include "CrewMember.h"
#include "ShipBlock.h"
#include "Ship.h"
#include "CharacterMovement.h"

// TAKEOUT
#include <iostream>
// TAEKEOUT


class CharacterMovementManager {

	public:
		CharacterMovementManager();
		~CharacterMovementManager();
		
		void initialize(Ship *, int, int, int, int, ShipBlock **);
		
		void addNewMovement(CrewMember *, int, int);
		void addNewMovement(CrewMember *, int, int, CharacterAction);
		void move();
		
		int getBlockWidth();
		int getBlockHeight();
		

	private:
		
		bool DFSSearch(pair<sf::Vector2i, bool> **, sf::Vector2i, sf::Vector2i);
		bool generateShortestPath(CharacterMovement *);

		ShipBlock * getCurrentBlock(CrewMember *);
		ShipBlock * getCurrentBlock(float, float);

		sf::Vector2f getNewMovementVector(CharacterMovement *);

		Ship * playerShip;

		std::list<CharacterMovement *> currentCharacterMovements;
		ShipBlock** shipBlocks;

		int numXBlocks;
		int numYBlocks;

		int blockWidth;;
		int blockHeight;


};

#endif  //_SHIPMOVEMENTMANAGER_H
