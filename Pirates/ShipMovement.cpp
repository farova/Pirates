#include "ShipMovement.h"

ShipMovement::ShipMovement(CrewMember * crew, float finalX, float finalY)
	: crewMember(crew)
{
	finalDestination.x = finalX;
	finalDestination.y = finalY;
}

ShipMovement::~ShipMovement()
{

}

void ShipMovement::setMovementVector(float x, float y)
{
	movementVector.x = x;
	movementVector.y = y;
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
