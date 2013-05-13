#include "ShipView.h"


ShipView::ShipView()
	: initialized(false), enemyLoaded(false), fightFinished(false), cacheLoaded(false), characterHeight(0), characterWidth(0)
{

}

ShipView::~ShipView()
{
	for(int i = 0; i < numXBlocks; i+=1)
	{
		delete [] shipBlocks;
	}
	delete [] shipBlocks;
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

	// deaw all action objects 
	std::list<ShipActionObject *>::iterator shipObjIterator;
	for ( shipObjIterator = shipActionObjects.begin(); shipObjIterator != shipActionObjects.end(); ++shipObjIterator)
	{
		(*shipObjIterator)->draw(window);
	}

	pollActions();
}

void ShipView::pollActions()
{
	std::list<ShipActionObject *>::iterator shipObjIterator;
	for ( shipObjIterator = shipActionObjects.begin(); shipObjIterator != shipActionObjects.end(); ++shipObjIterator)
	{
		if ((*shipObjIterator)->isOccupied())
		{
			
			// apply bonuses is using specific actionItems
			
		}
	}
}

void ShipView::initialize()
{
	if(!cacheLoaded)
		return;
	
	thor::ResourceKey<sf::Texture> bgTextureResource = thor::Resources::fromFile<sf::Texture>("images/shipViewBg.png");
	std::shared_ptr<sf::Texture> bgTexturePtr = resourceCache->acquire(bgTextureResource);
	backgroundSprite.setTexture(*bgTexturePtr);
	backgroundSprite.setPosition(0,0);
	
	initializeBlocks();
	initializeActionObjects();

	movementManager.initialize(playerShip, blockWidth, blockHeight, numXBlocks, numYBlocks, shipBlocks, shipActionObjects);

	playerShip->getLargeShipSprite().setPosition(blockWidth,blockHeight);
	playerShip->getLargeShipOverlaySprite().setPosition(blockWidth,blockHeight);

	float offset = blockWidth*3;
	float profileOffset = - blockWidth*2;

	// place crew onto ship
	std::list<CrewMember*> playerCrew = playerShip->getCrew();
	std::list<CrewMember *>::iterator crewIterator;
	for ( crewIterator = playerCrew.begin(); crewIterator != playerCrew.end(); ++crewIterator)
	{
		(*crewIterator)->setPosition(offset = offset + blockWidth*2, blockHeight*7);
		(*crewIterator)->setProfilePicturePosition(profileOffset = profileOffset + blockWidth*3, blockHeight*14);
		(*crewIterator)->setProfilePictureSelectedOverlayPosition(profileOffset, blockHeight*14);
	}

	initialized = true;
}

void ShipView::initializeNewEncounter()
{
	initializeActionObjects();

	// reset all timers
	std::list<ShipActionObject *>::iterator shipObjIterator;
	for ( shipObjIterator = shipActionObjects.begin(); shipObjIterator != shipActionObjects.end(); ++shipObjIterator)
		(*shipObjIterator)->resetCooldownClock();


}

void ShipView::initializeActionObjects()
{
	thor::ResourceKey<sf::Texture> wheelTextureResource = thor::Resources::fromFile<sf::Texture>("shipWheel.png");
	std::shared_ptr<sf::Texture> wheelTexturePtr = resourceCache->acquire(wheelTextureResource);
	
	thor::ResourceKey<sf::Texture> escapeButtonTextureResource = thor::Resources::fromFile<sf::Texture>("images/button_escape.png");
	std::shared_ptr<sf::Texture> escapeButtonTextureResourcePtr = resourceCache->acquire(escapeButtonTextureResource);

	ShipActionObject * captainWheel = new ShipActionObject(wheelTexturePtr.get());
	captainWheel->setPosition( blockWidth*11 ,blockHeight*7);
	captainWheel->setUsageCoordinates( blockWidth*11 ,blockHeight*7);
	captainWheel->setActionType(SteerShip);
	captainWheel->setCooldown(5);
	captainWheel->setActionButton(escapeButtonTextureResourcePtr.get(), blockWidth*12, blockHeight*7);



	// remove previous cannon and add all cannons to ActionObjectList in case new cannons bought




	shipActionObjects.push_back(captainWheel);
}

void ShipView::initializeBlocks()
{
	blockHeight = blockWidth = characterHeight;
	numXBlocks = ceil(windowWidth/characterWidth);
	numYBlocks = ceil(windowHeight/characterHeight);

	shipBlocks = new ShipBlock*[numXBlocks];
	for(int i = 0; i < numXBlocks; i+=1)
	{
		shipBlocks[i] = new ShipBlock[numYBlocks];
	}

	for(int i = 0; i < numXBlocks; i+=1)
	{
		for(int j = 0; j < numYBlocks; j+=1)
		{
			shipBlocks[i][j].initialize(1,false,!(i >= 2 && i <= 11 && j == 7));
			shipBlocks[i][j].setBlockMatrixPosition(i,j);
		}
	}
	
	shipBlocks[4][6].initialize(1,true,false);
	shipBlocks[4][5].initialize(1,true,false);
	shipBlocks[3][5].initialize(1,false,false);
	shipBlocks[2][5].initialize(1,false,false);
	shipBlocks[1][5].initialize(1,false,false);

	
	shipBlocks[7][6].initialize(1,true,false);
	shipBlocks[7][5].initialize(1,true,false);
	shipBlocks[7][4].initialize(1,true,false);
	shipBlocks[7][3].initialize(1,true,false);
	shipBlocks[7][2].initialize(1,true,false);
	shipBlocks[7][1].initialize(1,false,false);


	
	shipBlocks[2][8].initialize(1,true,false);
	shipBlocks[2][9].initialize(1,false,false);
	shipBlocks[3][9].initialize(1,false,false);
	shipBlocks[4][9].initialize(1,false,false);
	shipBlocks[5][9].initialize(1,false,false);
	shipBlocks[6][9].initialize(1,false,false);
	shipBlocks[7][9].initialize(1,false,false);
	shipBlocks[8][9].initialize(1,false,false);
	shipBlocks[9][9].initialize(1,false,false);
	shipBlocks[10][9].initialize(1,false,false);
	shipBlocks[11][9].initialize(1,false,false);

	
	shipBlocks[7][10].initialize(1,true,false);
	shipBlocks[2][11].initialize(1,false,false);
	shipBlocks[3][11].initialize(1,false,false);
	shipBlocks[4][11].initialize(1,false,false);
	shipBlocks[5][11].initialize(1,false,false);
	shipBlocks[6][11].initialize(1,false,false);
	shipBlocks[7][11].initialize(1,false,false);
	shipBlocks[8][11].initialize(1,false,false);
	shipBlocks[9][11].initialize(1,false,false);
	shipBlocks[10][11].initialize(1,false,false);

	
	
	for(int j = 0; j < numYBlocks; j+=1)
	{
		for(int i = 0; i < numXBlocks; i+=1)
			{
			if(shipBlocks[i][j].isBlocked())
				cout << "X";
			else if(shipBlocks[i][j].isLadder())
				cout << "-";
			else
				cout << " ";
		}
		cout << endl;
	}
}

bool ShipView::handleCrewClick(int x, int y)
{
	bool spriteClicked = false;

	// determine if clicked on sprite - toggle selected if did
	std::list<CrewMember*> playerCrew = playerShip->getCrew();
	std::list<CrewMember *>::iterator crewIterator;
	for ( crewIterator = playerCrew.begin(); crewIterator != playerCrew.end(); ++crewIterator)
	{
		if( isSpriteClicked((*crewIterator)->getSprite(), x,y) || 
			isSpriteClicked((*crewIterator)->getProfileSprite(), x,y))
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

			std::list<ShipActionObject *>::iterator shipObjIterator;
			for ( shipObjIterator = shipActionObjects.begin(); shipObjIterator != shipActionObjects.end(); ++shipObjIterator)
			{
				if((*shipObjIterator)->isInBounds(x, y))
				{
					if(!(*shipObjIterator)->isOccupied())
					{
						sf::Vector2i actionCoords = (*shipObjIterator)->getUsageCoordinates();

						movementManager.addNewMovement(*crewIterator, actionCoords.x, actionCoords.y, (*shipObjIterator));

						return;
					}
					break;
				}
			}

			movementManager.addNewMovement(*crewIterator, x, y);
		}
	}
}

void ShipView::handleMouseClick(int x, int y, sf::Mouse::Button button)
{
	if (!isInitialized())
		return;

	switch (button)
	{
	case sf::Mouse::Left:
		// if click on crew member, no other action preformed
		if(handleCrewClick(x,y))
			return;

		handleActionButtonClick(x,y);
		deselectAllCrew();

		break;

	case sf::Mouse::Right:
		handleShipBlockClick(x,y);
		break;
	}

	// fightFinished = true;
}

void ShipView::handleActionButtonClick(int x,int y)
{
	// determmine if action is ready, and button was clicked for it
	std::list<ShipActionObject *>::iterator shipObjIterator;
	for ( shipObjIterator = shipActionObjects.begin(); shipObjIterator != shipActionObjects.end(); ++shipObjIterator)
	{

		if ((*shipObjIterator)->isOccupied() && 
			(*shipObjIterator)->isActionReady() && 
			(*shipObjIterator)->getActionButton().getGlobalBounds().contains(x,y))
		{
			switch((*shipObjIterator)->getActionType())
			{
				case ArmCannon:
					handleCannonButtonClick(*shipObjIterator);
					break;
				case SteerShip:
					handleSteeringWheelButtonClick();
					break;
			}
		}
	}
}

void ShipView::handleCannonButtonClick(ShipActionObject *actionObject)
{
	// go through cannon list, determine which cannon based on actionObj pointer
	std::list<Cannon *> cannons = playerShip->getCannons();
	std::list<Cannon *>::iterator cannonIterator;
	for ( cannonIterator = cannons.begin(); cannonIterator != cannons.end(); ++cannonIterator)
	{
		if((*cannonIterator)->getActionObject() == actionObject)
		{
			
			// shoot cannon, reduce anno, reset actionobj clock, etc.






			actionObject->resetCooldownClock();

			break;
		}
	}


}

void ShipView::handleSteeringWheelButtonClick()
{
	fightFinished = true;
}

void ShipView::deselectAllCrew()
{
	std::list<CrewMember*> playerCrew = playerShip->getCrew();
	std::list<CrewMember *>::iterator crewIterator;
	for ( crewIterator = playerCrew.begin(); crewIterator != playerCrew.end(); ++crewIterator)
	{
		if((*crewIterator)->isCharacterSelected())
		{
			(*crewIterator)->toggleSelect();
		}
	}
}

bool ShipView::isSpriteClicked(sf::Sprite &sprite, float x, float y)
{
	return sprite.getGlobalBounds().contains(x,y);
}

void ShipView::handleKeyPress(sf::Keyboard::Key key)
{

}

void ShipView::cleanUp()
{
	delete enemyShip;
	enemyLoaded = false;
	fightFinished = false;

	// stop all movements
	movementManager.stopAllMovements();



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