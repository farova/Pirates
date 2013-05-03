#include "ShipMovement.h"

ShipMovement::ShipMovement(CrewMember * crew, float finalX, float finalY)
	: crewMember(crew), movementStatus(Initial)
{
	finalDestination.x = finalX;
	finalDestination.y = finalY;
}

ShipMovement::~ShipMovement()
{

}

void ShipMovement::setStatus(MovementStatus stat)
{
	movementStatus = stat;
}

MovementStatus ShipMovement::getStatus()
{
	return movementStatus;
}


void ShipMovement::setMovementVector(float x, float y)
{
	movementVector.x = x;
	movementVector.y = y;
}

void ShipMovement::setMovementVector(sf::Vector2f vector)
{
	movementVector = vector;
}

CrewMember * ShipMovement::getCrewMember()
{
	return crewMember;
}

sf::Vector2f ShipMovement::getFinalDestination()
{
	return finalDestination;
}

sf::Vector2f ShipMovement::getMovementVector()
{
	 return movementVector;
}

void ShipMovement::setShortestPath(std::list<ShipBlock *> path)
{
	shortestPath = path;
}

std::list<ShipBlock *> & ShipMovement::getShortestPath()
{
	return shortestPath;
}