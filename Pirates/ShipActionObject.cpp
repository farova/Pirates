#include "ShipActionObject.h"


ShipActionObject::ShipActionObject(sf::Texture * texture)
	: Object(texture), 
	usageCoordinateX(0), 
	usageCoordinateY(0), 
	occupied(false), 
	escapeBonus(0), 
	hitBonus(0), 
	actionType(NoAction)
{

}

ShipActionObject::~ShipActionObject()
{

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

CharacterAction ShipActionObject::getActionType()
{
	return actionType;
}

void ShipActionObject::setActionType(CharacterAction action)
{
	actionType = action;
}
