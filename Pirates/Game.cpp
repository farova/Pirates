#include "Game.h"


Game::Game()
	: gameState(SplashScreenState), initialized(false), cacheLoaded(false)
{

}

Game::~Game()
{
	delete mapView;
	delete playerShip;
	delete resourceCache;
}

void Game::drawAll(sf::RenderWindow &window)
{
	switch(this->getGameState())
	{
	case SplashScreenState:	drawSplashScreen(window);	break;
	case MapViewState:		drawMapView(window);		break;
	case BuyViewState:		drawBuyView(window);		break;
	case ShipViewState:		drawShipView(window);		break;
	case MainMenuState:		drawMainMenu(window);		break;
	case SettingsState:		drawSettingsMenu(window);	break;
	default:			break;
	}
}

void Game::drawSplashScreen(sf::RenderWindow &window)
{
	window.draw(splashScreenSprite);
}

void Game::drawShipView(sf::RenderWindow &window)
{
	shipView->drawAll(window);
	window.draw(mouseDragManager.getRectangle());
}

void Game::drawBuyView(sf::RenderWindow &window)
{

}

void Game::drawMainMenu(sf::RenderWindow &window)
{

}

void Game::drawSettingsMenu(sf::RenderWindow &window)
{

}

void Game::drawMapView(sf::RenderWindow &window)
{
	mapView->drawAll(window);
}

void Game::passSelectionBoxToView(sf::FloatRect &selectionRect)
{
	switch(this->getGameState())
	{
	case ShipViewState:
		shipView->handleSelectionBox(selectionRect);
		break;
	}
}

void Game::handleMouseDrag(int x, int y)
{
	if(mouseDragManager.isMousePressed())
		mouseDragManager.setCurrent(x, y);
}

void Game::handleMouseRelease(int x, int y, sf::Mouse::Button button)
{
	switch (button)
	{
	case sf::Mouse::Button::Left:
		if(mouseDragManager.isValidSelection(x, y))
			passSelectionBoxToView(mouseDragManager.getRectangle().getGlobalBounds());
		mouseDragManager.finishSelection();
		break;
	}
}

void Game::handleMouseClick(int x, int y, sf::Mouse::Button button)
{
	// handle mouse selection
	switch (button)
	{
	case sf::Mouse::Button::Left:
		mouseDragManager.setStart(x,y);
		break;
	}

	// handle game views
	switch(this->getGameState())
	{
	case SplashScreenState:
		this->setGameState(MapViewState);
		break;

	case MapViewState:
		mapView->handleMouseClick(x,y, button);
		if(mapView->isValidMove())
			this->determineEncounter(mapView->getMapBlockMovedTo());
		break;

	case ShipViewState:
		shipView->handleMouseClick(x,y, button);
		if(shipView->isFightFinished())
		{
			this->setGameState(MapViewState);
			shipView->cleanUp();
		}
		break;

	case BuyViewState:
		break;

	case MainMenuState:
		break;

	case SettingsState:
		break;
		
	default:
		break;
	}

}

void Game::determineEncounter(MapBlock * mapBlock)
{
	EncounterGenerator encounterGenerator(*mapBlock, resourceCache);

	switch(encounterGenerator.getEncounterType())
	{
		case ShipHit:

			if(encounterGenerator.hitShip())
			{
				Ship *enemy = encounterGenerator.generateShip();
				this->setGameState(ShipViewState);

				shipView->setEnemyShip(enemy);
				shipView->initializeNewEncounter();
			}

			break;
		case LandHit:
			// this->setGameState(buyViewState);

			// encounterGenerator.generateLandEncounter();

			break;
	}
}

void Game::handleKeyPress(sf::Keyboard::Key key)
{
	switch(this->getGameState())
	{
	case SplashScreenState:
		this->setGameState(MapViewState);
		break;
	default:
		break;
	}

}

bool Game::isGamePlaying()
{
	return playing;
}


bool Game::isInitialized()
{
	return initialized;
}

GameState Game::getGameState()
{
	return this->gameState;
}

void Game::setGameState(GameState state)
{
	this->gameState = state;
}

void Game::initialize()
{
	resourceCache = new thor::ResourceCache<sf::Texture>();
	cacheLoaded = true;

	// create keys to load resources
	thor::ResourceKey<sf::Texture> splashScreenTexture = thor::Resources::fromFile<sf::Texture>("splash.jpg");
	
	thor::ResourceKey<sf::Texture> shipSmallTexture = thor::Resources::fromFile<sf::Texture>("ship.png");
	thor::ResourceKey<sf::Texture> shipLargeTexture = thor::Resources::fromFile<sf::Texture>("images/ship_1.png");
	thor::ResourceKey<sf::Texture> shipLargeOverlayTexture = thor::Resources::fromFile<sf::Texture>("images/ship_1_overlay.png");
	
	thor::ResourceKey<sf::Texture> shipPirateTexture = thor::Resources::fromFile<sf::Texture>("ship_pirate.png");
	thor::ResourceKey<sf::Texture> shipNeutralTexture = thor::Resources::fromFile<sf::Texture>("ship_neutral.png");
	thor::ResourceKey<sf::Texture> shipNavyTexture = thor::Resources::fromFile<sf::Texture>("ship_navy.png");

	thor::ResourceKey<sf::Texture> crewTexture1 = thor::Resources::fromFile<sf::Texture>("images/pirate_1.png");
	thor::ResourceKey<sf::Texture> crewTexture2 = thor::Resources::fromFile<sf::Texture>("images/pirate_2.png");
	thor::ResourceKey<sf::Texture> crewTextureS = thor::Resources::fromFile<sf::Texture>("images/selected.png");

	// load into cache
	std::shared_ptr<sf::Texture> crewTexture1Ptr = resourceCache->acquire(crewTexture1);
	std::shared_ptr<sf::Texture> crewTexture2Ptr = resourceCache->acquire(crewTexture2);
	std::shared_ptr<sf::Texture> crewTextureSPtr = resourceCache->acquire(crewTextureS);
	resourceCache->acquire(shipPirateTexture);
	resourceCache->acquire(shipNeutralTexture);
	resourceCache->acquire(shipNavyTexture);
	std::shared_ptr<sf::Texture> splashScreenPtr = resourceCache->acquire(splashScreenTexture);
	std::shared_ptr<sf::Texture> playerSmallTexturePtr = resourceCache->acquire(shipSmallTexture);
	std::shared_ptr<sf::Texture> playerLargeTexturePtr = resourceCache->acquire(shipLargeTexture);
	std::shared_ptr<sf::Texture> playerLargeOverlayTexturePtr = resourceCache->acquire(shipLargeOverlayTexture);
	

	//initialize splashscreen
	splashScreenSprite.setTexture(*splashScreenPtr);


	// initialize playerShip
	playerShip = new Ship(playerSmallTexturePtr.get(), 20, 20, 10, Neutral, Fighter, playerLargeTexturePtr.get(), playerLargeOverlayTexturePtr.get());
	playerShip->setPosition(0,0);

	int characterH = 50;
	int characterW = 30;

	CrewMember *crewA = new CrewMember(crewTexture1Ptr.get(), crewTextureSPtr.get(), "Michaela", 10, 10, 1, 15);
	CrewMember *crewB = new CrewMember(crewTexture2Ptr.get(), crewTextureSPtr.get(), "Victor", 10, 10, 1, 15);
	
	playerShip->addCrewMember(crewA);
	playerShip->addCrewMember(crewB);

	// initialize different game views
	mapView = new MapView();
	mapView->setWindowSize(windowWidth, windowHeight);
	mapView->setPlayerShip(playerShip);
	mapView->loadCache(resourceCache);
	mapView->initialize();

	shipView = new ShipView();
	shipView->setWindowSize(windowWidth, windowHeight);
	shipView->setCaracterSize(characterW, characterH);
	shipView->setPlayerShip(playerShip);
	shipView->loadCache(resourceCache);
	shipView->initialize();



	this->initialized = true;
}

void Game::setWindowSize(int w, int h)
{
	windowHeight = h;
	windowWidth = w;
}

void Game::setPlayerShip(Ship *ship)
{
	playerShip = ship;
}

void Game::loadCache(thor::ResourceCache<sf::Texture> * cache)
{
	resourceCache = cache;
}