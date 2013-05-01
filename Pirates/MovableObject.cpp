#include "MovableObject.h"

MovableObject::MovableObject(sf::Texture *texture, float speed, int healthMax, int healthCurrent)
	: Object(texture), healthCurrent(healthCurrent), healthMax(healthMax), speed(speed)
{
	// nothing
}

bool MovableObject::isDead()
{
	return healthCurrent <= 0;
}

void MovableObject::move(float x, float y)
{
	if(isDead())
		return; 

	getSprite().move(x,y);
}

void MovableObject::takeDamage(int amount)
{
	healthCurrent -= amount;
}

void MovableObject::restoreHealth(int amount)
{
	healthCurrent += amount;
}

void MovableObject::restoreFullHealth()
{
	healthCurrent = healthMax;
}
		