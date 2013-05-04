#include "CharacterMovement.h"

CharacterMovement::CharacterMovement(CrewMember * crew, float finalX, float finalY, bool action)
	: crewMember(crew), movementStatus(Initial), actionTriggered(action)
{
	finalDestination.x = finalX;
	finalDestination.y = finalY;
}

CharacterMovement::~CharacterMovement()
{

}

bool CharacterMovement::isActionTriggered()
{
	return actionTriggered;
}

CharacterAction CharacterMovement::getTriggeredAction()
{
	return actionToPerform;
}

void CharacterMovement::setTriggeredAction(CharacterAction act)
{
	actionToPerform = act;
}

void CharacterMovement::setStatus(MovementStatus stat)
{
	movementStatus = stat;
}

MovementStatus CharacterMovement::getStatus()
{
	return movementStatus;
}


void CharacterMovement::setMovementVector(float x, float y)
{
	movementVector.x = x;
	movementVector.y = y;
}

void CharacterMovement::setMovementVector(sf::Vector2f vector)
{
	movementVector = vector;
}

CrewMember * CharacterMovement::getCrewMember()
{
	return crewMember;
}

sf::Vector2f CharacterMovement::getFinalDestination()
{
	return finalDestination;
}

sf::Vector2f CharacterMovement::getMovementVector()
{
	 return movementVector;
}

void CharacterMovement::setShortestPath(std::list<ShipBlock *> path)
{
	shortestPath = path;
}

std::list<ShipBlock *> & CharacterMovement::getShortestPath()
{
	return shortestPath;
}