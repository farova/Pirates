#include "CrewMember.h"

CrewMember::CrewMember(sf::Texture *texture ,string name, int strength, int intelligence, int speed, int healthMax)
	: MovableObject(texture, speed, healthMax, healthMax),
	name(name), strength(strength), intelligence(intelligence)
{

}

CrewMember::~CrewMember()
{

}

int CrewMember::getStrength()
{
	return strength;
}

int CrewMember::getIntelligence()
{
	return intelligence;
}

void CrewMember::setStrength(int amount)
{
	strength = amount;
}

void CrewMember::setIntelligence(int amount)
{
	intelligence = amount;
}
