#include "ShipActionObject.h"


ShipActionObject::ShipActionObject(sf::Texture * texture)
	: Object(texture), 
	usageCoordinateX(0), 
	usageCoordinateY(0), 
	occupied(false), 
	escapeBonus(0), 
	hitBonus(0), 
	actionType(NoAction),
	actionDirection(Right)
{

}

ShipActionObject::~ShipActionObject()
{

}

void ShipActionObject::draw(sf::RenderWindow &window)
{
	window.draw(getSprite());
}

void ShipActionObject::setPosition(float x, float y)
{
	this->getSprite().setPosition(x,y);
}

bool ShipActionObject::isInBounds(float x, float y)
{
	return this->getSprite().getGlobalBounds().contains(x,y);
}

void ShipActionObject::setUsageCoordinates(int x, int y)
{
	usageCoordinateX = x;
	usageCoordinateY = y;
}

sf::Vector2i ShipActionObject::getUsageCoordinates()
{
	return sf::Vector2i(usageCoordinateX, usageCoordinateY);
}

bool ShipActionObject::isOccupied()
{
	return occupied;
}

void ShipActionObject::setIfOccupied(bool occ)
{
	occupied = occ;
}

void ShipActionObject::setBonuses(float escape, float hit)
{
	escapeBonus = escape;
	hitBonus = hit;
}

float ShipActionObject::getEscapeBonus()
{
	return escapeBonus;
}

float ShipActionObject::getHitBonus()
{
	return hitBonus;
}

ActionType ShipActionObject::getActionType()
{
	return actionType;
}

void ShipActionObject::setActionType(ActionType action)
{
	actionType = action;
}

CharacterFacingDirection ShipActionObject::getActionDirection()
{
	return actionDirection;
}

void ShipActionObject::setActionDirection(CharacterFacingDirection dir)
{
	actionDirection = dir;
}