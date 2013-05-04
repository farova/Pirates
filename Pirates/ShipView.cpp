#include "ShipView.h"

#include <iostream>


ShipView::ShipView()
	: initialized(false), enemyLoaded(false), fightFinished(false), cacheLoaded(false), characterHeight(0), characterWidth(0)
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

	//move all characters on screen
	movementManager.move();

	// draw enemy ship
	if(enemyLoaded)	
	{
		enemyShip->getLargeShipSprite().setPosition(movementManager.getBlockWidth()*15,movementManager.getBlockHeight()*6);
		window.draw(enemyShip->getLargeShipSprite());
	}

	// draw player characters
	playerShip->drawShip(window);

}

void ShipView::initialize()
{
	if(!cacheLoaded)
		return;
	
	thor::ResourceKey<sf::Texture> bgTextureResource = thor::Resources::fromFile<sf::Texture>("images/shipViewBg.png");
	std::shared_ptr<sf::Texture> bgTexturePtr = resourceCache->acquire(bgTextureResource);
	backgroundSprite.setTexture(*bgTexturePtr);
	backgroundSprite.setPosition(0,0);

	movementManager.initialize(playerShip, windowHeight, windowWidth, characterHeight, characterWidth);
	
	playerShip->getLargeShipSprite().setPosition(movementManager.getBlockWidth(),movementManager.getBlockHeight());
	playerShip->getLargeShipOverlaySprite().setPosition(movementManager.getBlockWidth(),movementManager.getBlockHeight());

	float offset = movementManager.getBlockWidth()*3;

	std::list<CrewMember*> playerCrew = playerShip->getCrew();
	std::list<CrewMember *>::iterator crewIterator;
	for ( crewIterator = playerCrew.begin(); crewIterator != playerCrew.end(); ++crewIterator)
	{
		(*crewIterator)->setPosition(offset = offset+movementManager.getBlockWidth()*2, movementManager.getBlockHeight()*7);
	}
	
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
		{
			movementManager.addNewMovement(*crewIterator, x, y);
		}
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
		
void ShipView::setCaracterSize(int w, int h)
{
	characterHeight = h;
	characterWidth = w;
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