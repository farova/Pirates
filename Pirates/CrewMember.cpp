#include "CrewMember.h"

CrewMember::CrewMember(sf::Texture *texture, sf::Texture *selected,string name, int strength, int intelligence, float speed, int healthMax)
	: MovableObject(texture, speed, healthMax, healthMax),
	name(name), strength(strength), intelligence(intelligence), selected(false), performingAction(false) ,action(NoAction), facingDirection(Right)
{
	selectedOverlay.setTexture(*selected);
}

CrewMember::~CrewMember()
{

}

CharacterFacingDirection CrewMember::getFacingDirection()
{
	return facingDirection;
}

void CrewMember::setFacingDirection(CharacterFacingDirection dir)
{
	facingDirection = dir;
}

bool CrewMember::isPerformingAction()
{
	return performingAction;
}

void CrewMember::stopPerformingAction()
{
	performingAction = false;
	this->action = NoAction;
}

void CrewMember::performAction(CharacterAction action)
{
	performingAction = true;
	this->action = action;
}

void CrewMember::draw(sf::RenderWindow &window)
{
	Object::draw(window);	//call parent implementation of function
	
	if(isCharacterSelected())
		window.draw(selectedOverlay);


	if(isPerformingAction())
	{
		// draw action!
	}

}

void CrewMember::move(float x, float y)
{
	if(isDead())
		return;
	
	MovableObject::move(x,y);
	selectedOverlay.move(x,y);
}

void CrewMember::setPosition(float x, float y)
{
	Object::setPosition(x,y);
	selectedOverlay.setPosition(x,y);
}

int CrewMember::getStrength()
{
	return strength;
}

string CrewMember::getName()
{
	return name;
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


bool CrewMember::isCharacterSelected()
{
	return selected;
}

void CrewMember::toggleSelect()
{
	selected = !selected;
}
