#include "ShipMovementManager.h"

ShipMovementManager::ShipMovementManager()
{

}

ShipMovementManager::~ShipMovementManager()
{

}

void ShipMovementManager::initialize(Ship * ship)
{
	playerShip = ship;

	int numBlockPartitions = 20;

	blockWidth = ship->getLargeShipSprite().getGlobalBounds().width / numBlockPartitions;
	blockHeight = 2*blockHeight;



	shipBlocks = new ShipBlock*[numBlockPartitions];
	for(int i = 0; i < numBlockPartitions; i+=1)
	{
		shipBlocks[i] = new ShipBlock[numBlockPartitions];
	}










}

void ShipMovementManager::addNewMovement(CrewMember * crew, int x, int y)
{
	// check if character already had movement, if does cancel old and create new
	std::list<ShipMovement *>::iterator movementIterator = currentShipMovements.begin(), next;
	while(movementIterator!=currentShipMovements.end()) 
	{
		next = movementIterator; next++;
		if((*movementIterator)->getCrewMember() == crew)
		{
			currentShipMovements.erase(movementIterator);
			break;
		}
		movementIterator = next;
	}

	ShipMovement *movement = new ShipMovement(crew, x, y);
	currentShipMovements.push_back(movement);
}

ShipBlock * ShipMovementManager::getCurrentBlock(CrewMember * crewMember)
{
	



	throw "";
}

void ShipMovementManager::move(sf::RenderWindow &window)
{



	// if movement finished, delete movement object

}


