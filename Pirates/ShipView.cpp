#include "ShipView.h"

#include <iostream>


ShipView::ShipView()
	: initialized(false), enemyLoaded(false), fightFinished(false), cacheLoaded(false)
{

}

ShipView::~ShipView()
{

}

void ShipView::drawAll(sf::RenderWindow &window)
{
	if (!isInitialized())
		return;

	window.draw(backgroundSprite);

	playerShip->drawShip(window);

	if(enemyLoaded)	// draw enemy ship
	{
		enemyShip->getLargeShipSprite().setPosition(580,300);
		window.draw(enemyShip->getLargeShipSprite());
	}

	movementManager.move(window);
}

void ShipView::initialize()
{
	if(!cacheLoaded)
		return;
	
	thor::ResourceKey<sf::Texture> bgTextureResource = thor::Resources::fromFile<sf::Texture>("shipViewBackground.jpg");
	std::shared_ptr<sf::Texture> bgTexturePtr = resourceCache->acquire(bgTextureResource);
	backgroundSprite.setTexture(*bgTexturePtr);
	backgroundSprite.setPosition(0,0);

	playerShip->getLargeShipSprite().setPosition(50,200);

	float offset = 180;

	std::list<CrewMember*> playerCrew = playerShip->getCrew();
	std::list<CrewMember *>::iterator crewIterator;
	for ( crewIterator = playerCrew.begin(); crewIterator != playerCrew.end(); ++crewIterator)
	{
		(*crewIterator)->setPosition(offset = offset+40, 430);
	}

	movementManager.initialize(playerShip);

	initialized = true;
}

bool ShipView::handleCrewClick(int x, int y)
{
	bool spriteClicked = false;

	// determine if clicked on sprite - toggle selected if did
	std::list<CrewMember*> playerCrew = playerShip->getCrew();
	std::list<CrewMember *>::iterator crewIterator;
	for ( crewIterator = playerCrew.begin(); crewIterator != playerCrew.end(); ++crewIterator)
	{
		if(isSpriteClicked((*crewIterator)->getSprite(), x,y))
		{
			(*crewIterator)->toggleSelect();
			spriteClicked = true;
		}
	}

	return spriteClicked;
}

void ShipView::handleShipBlockClick(int x, int y)
{
	std::list<CrewMember*> playerCrew = playerShip->getCrew();
	std::list<CrewMember *>::iterator crewIterator;
	for ( crewIterator = playerCrew.begin(); crewIterator != playerCrew.end(); ++crewIterator)
	{
		if((*crewIterator)->isCharacterSelected())
			movementManager.addNewMovement(*crewIterator, x, y);
	}
}

void ShipView::handleMouseClick(int x, int y)
{
	if (!isInitialized())
		return;

	// if click on crew member, no other action preformed
	if(handleCrewClick(x,y))
		return;

	handleShipBlockClick(x,y);

	// fightFinished = true;
}

bool ShipView::isSpriteClicked(sf::Sprite &sprite, float x, float y)
{
	return sprite.getGlobalBounds().contains(x,y);
}

void ShipView::handleKeyPress()
{

}

void ShipView::cleanUp()
{
	delete enemyShip;
	enemyLoaded = false;
	fightFinished = false;




	// cleanup Dead after fight





}
		
void ShipView::setWindowSize(int w, int h)
{
	windowHeight = h;
	windowWidth = w;
}

bool ShipView::isInitialized()
{
	return initialized;
}

bool ShipView::isEnemyLoaded()
{
	return enemyLoaded;
}

bool ShipView::isFightFinished()
{
	return fightFinished;
}

void ShipView::setPlayerShip(Ship *ship)
{
	playerShip = ship;
}

void ShipView::setEnemyShip(Ship *ship)
{
	enemyShip = ship;
	enemyShip->getLargeShipSprite().setPosition(500,300);
	enemyLoaded = true;
	fightFinished = false;
}

void ShipView::loadCache(thor::ResourceCache<sf::Texture> * cache)
{
	resourceCache = cache;
	cacheLoaded = true;
}