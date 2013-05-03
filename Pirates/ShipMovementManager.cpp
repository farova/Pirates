#include "ShipMovementManager.h"

#include <iostream>

ShipMovementManager::ShipMovementManager()
	: BLOCK_HEIGHT(81), BLOCK_WIDTH(50)
{
	
}

ShipMovementManager::~ShipMovementManager()
{
	int xBlocks = 800/50;
	int yBlocks = 800/81;

	for(int i = 0; i < xBlocks; i+=1)
	{
		delete [] shipBlocks;
	}
	delete [] shipBlocks;
}

void ShipMovementManager::initialize(Ship * ship)
{
	playerShip = ship;

	int xBlocks = 800/50;
	int yBlocks = 800/81;
	
	shipBlocks = new ShipBlock*[xBlocks];
	for(int i = 0; i < xBlocks; i+=1)
	{
		shipBlocks[i] = new ShipBlock[yBlocks];
	}

	for(int i = 0; i < xBlocks; i+=1)
	{
		for(int j = 0; j < yBlocks; j+=1)
		{
			shipBlocks[i][j].initialize(1,false,!(i > 2 && i < 9 && j == 6));
			shipBlocks[i][j].setBlockMatrixPosition(i,j);
		}
	}
	
	shipBlocks[4][5].initialize(1,true,false);
	shipBlocks[4][4].initialize(1,true,false);
	shipBlocks[4][3].initialize(1,true,false);
	shipBlocks[3][3].initialize(1,false,false);
	shipBlocks[2][3].initialize(1,false,false);

	
	
	for(int j = 0; j < yBlocks; j+=1)
	{
		for(int i = 0; i < xBlocks; i+=1)
			{
			if(shipBlocks[i][j].isBlocked())
				cout << "X";
			else if(shipBlocks[i][j].isLadder())
				cout << "-";
			else
				cout << " ";
		}
		cout << endl;
	}

}

void ShipMovementManager::addNewMovement(CrewMember * crew, int x, int y)
{
	// do nothign if new block is not accessible and deselect the character
	if(getCurrentBlock(x,y)->isBlocked() || getCurrentBlock(x,y)->isLadder())
	{
		crew->toggleSelect();
		return;
	}

	// check if character already had movement, if does cancel old and create new
	std::list<ShipMovement *>::iterator movementIterator = currentShipMovements.begin(), next;
	while(movementIterator!=currentShipMovements.end()) 
	{
		next = movementIterator; next++;
		if((*movementIterator)->getCrewMember() == crew)
		{
			delete *movementIterator;
			currentShipMovements.erase(movementIterator);
			break;
		}
		movementIterator = next;
	}

	ShipMovement *movement = new ShipMovement(crew, x, y);

	// if we cannot generate a path, cannot create new movement
	if(!generateShortestPath(movement))
	{
		delete movement;
		return;
	}

	currentShipMovements.push_back(movement);
}

bool ShipMovementManager::DFSSearch( pair<sf::Vector2i, bool> ** matrix, sf::Vector2i node, sf::Vector2i goal)
{
	if(node.x == goal.x && node.y == goal.y)
		return true;

	// if not blocked and not visited
	if(!shipBlocks[node.x + 1][node.y].isBlocked() && matrix[node.x+1][node.y].second == false)
	{
		matrix[node.x+1][node.y].first = node;
		matrix[node.x+1][node.y].second = true;
		DFSSearch(matrix, sf::Vector2i(node.x+1, node.y), goal);
	}
		
	if(!shipBlocks[node.x - 1][node.y].isBlocked() && matrix[node.x-1][node.y].second == false)
	{
		matrix[node.x-1][node.y].first = node;
		matrix[node.x-1][node.y].second = true;
		DFSSearch(matrix, sf::Vector2i(node.x-1, node.y), goal);
	}
		
	if(!shipBlocks[node.x][node.y + 1].isBlocked() && matrix[node.x][node.y+1].second == false)
	{
		matrix[node.x][node.y+1].first = node;
		matrix[node.x][node.y+1].second = true;
		DFSSearch(matrix, sf::Vector2i(node.x, node.y+1), goal);
	}
		
	if(!shipBlocks[node.x][node.y - 1].isBlocked() && matrix[node.x][node.y-1].second == false)
	{
		matrix[node.x][node.y-1].first = node;
		matrix[node.x][node.y-1].second = true;
		DFSSearch(matrix, sf::Vector2i(node.x, node.y-1), goal);
	}
}

bool ShipMovementManager::generateShortestPath(ShipMovement * movement)
{
	const int xBlocks = 800/50;
	const int yBlocks = 800/81;

	sf::Vector2i destination = getCurrentBlock(movement->getFinalDestination().x, movement->getFinalDestination().y)->getBlockMatrixPosition();
	sf::Vector2i start = getCurrentBlock(movement->getCrewMember())->getBlockMatrixPosition();
	
	typedef pair<sf::Vector2i, bool> BlockParentPair; // <block, parent block>

	BlockParentPair ** searchArray; //<parent, visited
	searchArray = new BlockParentPair*[xBlocks];
	for(int i = 0; i < xBlocks; i+=1)
	{
		searchArray[i] = new BlockParentPair[yBlocks];
		
		for(int j = 0; j < yBlocks; j++)
		{
			searchArray[i]->second = false;
		}
	}
	
	DFSSearch(searchArray, start, destination);

	list<ShipBlock *> path;
	
	// go through matrix and put all nodes onto list
	sf::Vector2i pathNode = destination;
	while(!(pathNode.x == start.x && pathNode.y == start.y))
	{
		path.push_front(&shipBlocks[(int)pathNode.x][(int)pathNode.y]);
		pathNode = searchArray[(int)pathNode.x][(int)pathNode.y].first;
	}

	// only push current block if next direction is up/down
	if(!path.empty() && (start.y - path.front()->getBlockMatrixPosition().y) != 0 )
		path.push_front(&shipBlocks[(int)start.x][(int)start.y]);

	movement->setShortestPath(path);
	
	for(int i = 0; i < xBlocks; i+=1)
	{
		delete[] searchArray[i];
	}
	delete[] searchArray;

	return true;
}

ShipBlock * ShipMovementManager::getCurrentBlock(CrewMember * crewMember)
{
	return getCurrentBlock(crewMember->getPosition().x, crewMember->getPosition().y);
}

ShipBlock * ShipMovementManager::getCurrentBlock(float xPos, float yPos)
{
	return &shipBlocks[(int)(xPos/BLOCK_WIDTH)][(int)(yPos/BLOCK_HEIGHT)];
}

sf::Vector2f ShipMovementManager::getNewMovementVector(ShipMovement * movement)
{
	sf::Vector2f spritePosition = movement->getCrewMember()->getPosition();
	sf::Vector2f finalPosition = movement->getFinalDestination();
	int finalPositionXCentered = finalPosition.x - BLOCK_WIDTH/2;

	sf::Vector2i finalBlock = getCurrentBlock(finalPosition.x, finalPosition.y)->getBlockMatrixPosition();

	// reach final destination - center sprite in middle of click
	if(spritePosition.x == finalPositionXCentered && spritePosition.y == finalBlock.y*BLOCK_HEIGHT )
	{
		movement->setStatus(Finished);
		return sf::Vector2f(0,0);
	}

	int xDistToCompare, yDistToCompare;

	if(movement->getShortestPath().empty())
		movement->setStatus(Final);

	if(movement->getStatus() == Final)
	{
		xDistToCompare = finalPositionXCentered;
		yDistToCompare = finalBlock.y*BLOCK_HEIGHT;		// always align to block y coordinate
	}
	else
	{
		sf::Vector2i nextBlock = movement->getShortestPath().front()->getBlockMatrixPosition();
		xDistToCompare = nextBlock.x*BLOCK_WIDTH;
		yDistToCompare = nextBlock.y*BLOCK_HEIGHT;
	}

	// if completely in next path block, or inital movement or final movement determine direction of next movement, otherwise contine until hit next block on path
	if((spritePosition.x == xDistToCompare && spritePosition.y == yDistToCompare) || movement->getStatus() == Initial || movement->getStatus() == Final)
	{
		// pop off the block
		if(movement->getStatus() != Initial && movement->getStatus() != Final)
			movement->getShortestPath().pop_front();

		movement->setStatus(Moving);

		// update coordinates to check
		if(movement->getShortestPath().empty())
		movement->setStatus(Final);

		if(movement->getStatus() == Final)
		{
			xDistToCompare = finalPositionXCentered;
			yDistToCompare = finalBlock.y*BLOCK_HEIGHT;		// always align to block y coordinate
		}
		else
		{
			sf::Vector2i nextBlock = movement->getShortestPath().front()->getBlockMatrixPosition();
			xDistToCompare = nextBlock.x*BLOCK_WIDTH;
			yDistToCompare = nextBlock.y*BLOCK_HEIGHT;
		}

		//get coordinates for next movement
		int xDir, yDir;

		if((xDistToCompare - spritePosition.x) < 0)
			xDir = -1;
		else if((xDistToCompare - spritePosition.x) == 0)
			xDir = 0;
		else
			xDir = 1;
		
		if((yDistToCompare - spritePosition.y) < 0)
			yDir = -1;
		else if((yDistToCompare - spritePosition.y) == 0)
			yDir = 0;
		else
			yDir = 1;

		return sf::Vector2f(xDir, yDir);
	}
	else
	{
		return movement->getMovementVector();
	}
}

void ShipMovementManager::move()
{
	std::list<ShipMovement*>::iterator i = currentShipMovements.begin();
	while (i != currentShipMovements.end())
	{
		if ((*i)->getStatus() == Finished)
		{
			// if movement finished, delete object
			delete *i;
			i = currentShipMovements.erase(i);
		}
		else
		{
			(*i)->setMovementVector(getNewMovementVector(*i));

			float xMovement = (*i)->getMovementVector().x * (*i)->getCrewMember()->getSpeed();
			float yMovement = (*i)->getMovementVector().y * (*i)->getCrewMember()->getSpeed();

			cout << xMovement << " " << yMovement << endl;

			(*i)->getCrewMember()->move(xMovement, yMovement);

			++i;
		}
	}
}


