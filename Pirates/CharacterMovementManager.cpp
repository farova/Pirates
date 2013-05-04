#include "CharacterMovementManager.h"

#include <iostream>

CharacterMovementManager::CharacterMovementManager()
{
	
}

CharacterMovementManager::~CharacterMovementManager()
{

}

int CharacterMovementManager::getBlockWidth()
{
	return blockWidth;
}

int CharacterMovementManager::getBlockHeight()
{
	return blockHeight;
}

void CharacterMovementManager::initialize(Ship * ship, int blockW, int blockH, int numX, int numY, ShipBlock ** shipBlocksPtr)
{
	blockWidth = blockW;
	blockHeight = blockH;
	numXBlocks = numX;
	numYBlocks = numY;
	shipBlocks = shipBlocksPtr;
	playerShip = ship;
}

void CharacterMovementManager::addNewMovement(CrewMember * crew, int x, int y)
{
	addNewMovement(crew, x, y, NoAction);
}

void CharacterMovementManager::addNewMovement(CrewMember * crew, int x, int y, CharacterAction action)
{
	// do nothign if new block is not accessible and deselect the character
	if(getCurrentBlock(x,y)->isBlocked() || getCurrentBlock(x,y)->isLadder())
	{
		crew->toggleSelect();
		return;
	}

	// check if character already had movement, if does cancel old and create new
	std::list<CharacterMovement *>::iterator movementIterator = currentCharacterMovements.begin(), next;
	while(movementIterator!=currentCharacterMovements.end()) 
	{
		next = movementIterator; next++;
		if((*movementIterator)->getCrewMember() == crew)
		{
			delete *movementIterator;
			currentCharacterMovements.erase(movementIterator);
			break;
		}
		movementIterator = next;
	}

	bool performingValidAction = action != NoAction;

	CharacterMovement *movement = new CharacterMovement(crew, x, y, performingValidAction);

	// if we cannot generate a path, cannot create new movement
	if(!generateShortestPath(movement))
	{
		delete movement;
		return;
	}

	// stop character from performing current action
	movement->getCrewMember()->stopPerformingAction();

	if(performingValidAction)
		movement->setTriggeredAction(action);

	currentCharacterMovements.push_back(movement);
}

bool CharacterMovementManager::DFSSearch( pair<sf::Vector2i, bool> ** matrix, sf::Vector2i node, sf::Vector2i goal)
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

bool CharacterMovementManager::generateShortestPath(CharacterMovement * movement)
{
	sf::Vector2i destination = getCurrentBlock(movement->getFinalDestination().x, movement->getFinalDestination().y)->getBlockMatrixPosition();
	sf::Vector2i start = getCurrentBlock(movement->getCrewMember())->getBlockMatrixPosition();
	
	typedef pair<sf::Vector2i, bool> BlockParentPair; // <block, parent block>

	BlockParentPair ** searchArray; //<parent, visited
	searchArray = new BlockParentPair*[numXBlocks];
	for(int i = 0; i < numXBlocks; i+=1)
	{
		searchArray[i] = new BlockParentPair[numYBlocks];
		
		for(int j = 0; j < numYBlocks; j++)
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
	
	for(int i = 0; i < numXBlocks; i+=1)
	{
		delete[] searchArray[i];
	}
	delete[] searchArray;

	return true;
}

ShipBlock * CharacterMovementManager::getCurrentBlock(CrewMember * crewMember)
{
	return getCurrentBlock(crewMember->getPosition().x, crewMember->getPosition().y);
}

ShipBlock * CharacterMovementManager::getCurrentBlock(float xPos, float yPos)
{
	return &shipBlocks[(int)(xPos/blockWidth)][(int)(yPos/blockHeight)];
}

sf::Vector2f CharacterMovementManager::getNewMovementVector(CharacterMovement * movement)
{
	sf::Vector2f spritePosition = movement->getCrewMember()->getPosition();
	sf::Vector2f finalPosition = movement->getFinalDestination();
	int finalPositionXCentered = finalPosition.x; // - blockWidth/2;

	sf::Vector2i finalBlock = getCurrentBlock(finalPosition.x, finalPosition.y)->getBlockMatrixPosition();

	// reach final destination - center sprite in middle of click
	if(spritePosition.x == finalPositionXCentered && spritePosition.y == finalBlock.y*blockHeight )
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
		yDistToCompare = finalBlock.y*blockHeight;		// always align to block y coordinate
	}
	else
	{
		sf::Vector2i nextBlock = movement->getShortestPath().front()->getBlockMatrixPosition();
		xDistToCompare = nextBlock.x*blockWidth;
		yDistToCompare = nextBlock.y*blockHeight;
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
			yDistToCompare = finalBlock.y*blockHeight;		// always align to block y coordinate
		}
		else
		{
			sf::Vector2i nextBlock = movement->getShortestPath().front()->getBlockMatrixPosition();
			xDistToCompare = nextBlock.x*blockWidth;
			yDistToCompare = nextBlock.y*blockHeight;
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

void CharacterMovementManager::move()
{
	std::list<CharacterMovement*>::iterator i = currentCharacterMovements.begin();
	while (i != currentCharacterMovements.end())
	{
		if ((*i)->getStatus() == Finished)
		{
			// trigger action
			if((*i)->isActionTriggered())
				(*i)->getCrewMember()->performAction((*i)->getTriggeredAction());

			// if movement finished, delete object
			delete *i;
			i = currentCharacterMovements.erase(i);
		}
		else
		{
			(*i)->setMovementVector(getNewMovementVector(*i));

			float xMovement = (*i)->getMovementVector().x * (*i)->getCrewMember()->getSpeed();
			float yMovement = (*i)->getMovementVector().y * (*i)->getCrewMember()->getSpeed();

			// determine which direction character is facing
			CharacterFacingDirection direction;
			if(xMovement >= 0)
				direction = Right;
			else if(xMovement < 0)
				direction = Left;

			// if going down ladder, face inside of ship
			if(yMovement != 0)
				direction = In;

			(*i)->getCrewMember()->setFacingDirection(direction);
			(*i)->getCrewMember()->move(xMovement, yMovement);

			++i;
		}
	}
}