#include "Ship.h"


Ship::Ship(sf::Texture * textureSmall, int healthMax, int healthCurrent, int speed, ShipAlliance alliance, ShipType type, sf::Texture * textureLarge, sf::Texture * textureLargeOver)
	: MovableObject(textureSmall, healthMax, healthCurrent, speed),
	alliance(alliance), shipType(type)
{
	largeSprite.setTexture(*textureLarge);
	largeOverlaySprite.setTexture(*textureLargeOver);
}

Ship::~Ship()
{






}

void Ship::drawShip(sf::RenderWindow &window)
{
	window.draw(getLargeShipSprite());

	std::list<CrewMember *>::iterator crewIterator;
	for ( crewIterator = crew.begin(); crewIterator != crew.end(); ++crewIterator)
	{
		(*crewIterator)->draw(window);
	}

	
	window.draw(getLargeShipOverlaySprite());
}

ShipAlliance Ship::getShipAlliance()
{
	return alliance;
}

ShipType Ship::getShipType()
{
	return shipType;
}

sf::Sprite & Ship::getLargeShipSprite()
{
	return largeSprite;
}

sf::Sprite & Ship::getLargeShipOverlaySprite()
{
	return largeOverlaySprite;
}

void Ship::addCrewMember(CrewMember *crewMember)
{
	crew.push_back(crewMember);
}

void Ship::addCannon(Cannon *cannon)
{
	cannons.push_back(cannon);
}

void Ship::addMeleeWeapon(MeleeWeapon *weapon)
{
	armory.push_back(weapon);
}

std::list<CrewMember*> & Ship::getCrew()
{
	return crew;
}

std::list<Cannon*> & Ship::getCannons()
{
	return cannons;
}

std::list<MeleeWeapon*> & Ship::getArmory()
{
	return armory;
}