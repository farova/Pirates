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
	
	shipBlocks[4][5].initialize(1,false,false);
	shipBlocks[4][4].initialize(1,false,false);
	shipBlocks[4][3].initialize(1,false,false);
	shipBlocks[3][3].initialize(1,false,false);
	shipBlocks[2][3].initialize(1,false,false);

	
	
	for(int j = 0; j < yBlocks; j+=1)
	{
		for(int i = 0; i < xBlocks; i+=1)
			{
			if(shipBlocks[i][j].isBlocked())
				cout << "X";
			else
				cout << " ";
		}
		cout << endl;
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

	// if the block we want to get to is blocked, cant move to it
	if(shipBlocks[destination.x][destination.y].isBlocked() || shipBlocks[destination.x][destination.y].isLadder() || shipBlocks[start.x][start.y].isBlocked())
		return false;
	
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

	// reach final destination
	if(spritePosition.x == finalPosition.x && (spritePosition.y >= finalPosition.y && spritePosition.y - BLOCK_HEIGHT < finalPosition.y) )
	{
		movement->setFinished(true);
		return sf::Vector2f(0,0);
	}

	sf::Vector2i nextBlock = movement->getShortestPath().front()->getBlockMatrixPosition();

	bool initialMove = (movement->getMovementVector().x == 0 && movement->getMovementVector().y == 0);

	// if completely in next path block, determine direction of next movement, otherwise contine until hit next block on path
	if((spritePosition.x == nextBlock.x*BLOCK_WIDTH && spritePosition.y == nextBlock.y*BLOCK_HEIGHT) || initialMove)
	{
		// pop off the block
		if(!initialMove)
			movement->getShortestPath().pop_front();

		//get coordinates for next movement
		int xDir, yDir;

		if((nextBlock.x*BLOCK_WIDTH - spritePosition.x) < 0)
			xDir = -1;
		else if((nextBlock.x*BLOCK_WIDTH - spritePosition.x) == 0)
			xDir = 0;
		else
			xDir = 1;
		
		if((nextBlock.y*BLOCK_HEIGHT - spritePosition.y) < 0)
			yDir = -1;
		else if((nextBlock.y*BLOCK_HEIGHT - spritePosition.y) == 0)
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
		if ((*i)->isFinished())
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


