#include "ShipMovementManager.h"

ShipMovementManager::ShipMovementManager()
{

}

ShipMovementManager::~ShipMovementManager()
{

}


void ShipMovementManager::addNewMovement(CrewMember * crew, ShipBlock * block)
{




	ShipMovement *movement = new ShipMovement(crew, , block);



}

void ShipMovementManager::move(sf::RenderWindow &window)
{



	// if movement finished, delete movement object

}

void ShipMovementManager::addShipBlock(ShipBlock *block)
{
	shipBlocks.push_back(block);
}

void ShipMovementManager::addShipBlockPath(ShipBlockPath *path)
{
	shipPaths.push_back(path);
}


