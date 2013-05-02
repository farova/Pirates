#include "Game.h"

// TAKEOUT
#include <iostream>
using namespace std;
// TAKEOUT

Game::Game()
	: gameState(splashScreenState), initialized(false), cacheLoaded(false)
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
	case splashScreenState:	drawSplashScreen(window);	break;
	case mapViewState:		drawMapView(window);		break;
	case buyViewState:		drawBuyView(window);		break;
	case shipViewState:		drawShipView(window);		break;
	case mainMenuState:		drawMainMenu(window);		break;
	case settingsState:		drawSettingsMenu(window);	break;
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

void Game::handleMouseClick(int x, int y)
{

	switch(this->getGameState())
	{
	case splashScreenState:
		this->setGameState(mapViewState);
		break;

	case mapViewState:
		mapView->handleMouseClick(x,y);
		if(mapView->isValidMove())
			this->determineEncounter(mapView->getMapBlockMovedTo());
		break;

	case shipViewState:
		shipView->handleMouseClick(x,y);
		if(shipView->isFightFinished())
		{
			this->setGameState(mapViewState);
			shipView->cleanUp();
		}
		break;

	case buyViewState:
		break;

	case mainMenuState:
		break;

	case settingsState:
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

			cout << endl;
			cout << "ShipHit" << endl;

			if(encounterGenerator.hitShip())
			{
				Ship *enemy = encounterGenerator.generateShip();
				this->setGameState(shipViewState);

				shipView->setEnemyShip(enemy);
			}

			break;
		case LandHit:
			// this->setGameState(buyViewState);
			
			cout << "LandHit"<< endl;

			// encounterGenerator.generateLandEncounter();

			break;
	}
}

void Game::handleKeyPress()
{
	switch(this->getGameState())
	{
	case splashScreenState:
		this->setGameState(mapViewState);
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
	thor::ResourceKey<sf::Texture> shipLargeTexture = thor::Resources::fromFile<sf::Texture>("ship_large.png");
	
	thor::ResourceKey<sf::Texture> shipPirateTexture = thor::Resources::fromFile<sf::Texture>("ship_pirate.png");
	thor::ResourceKey<sf::Texture> shipNeutralTexture = thor::Resources::fromFile<sf::Texture>("ship_neutral.png");
	thor::ResourceKey<sf::Texture> shipNavyTexture = thor::Resources::fromFile<sf::Texture>("ship_navy.png");

	thor::ResourceKey<sf::Texture> crewTextureB = thor::Resources::fromFile<sf::Texture>("crew_b.png");
	thor::ResourceKey<sf::Texture> crewTextureG = thor::Resources::fromFile<sf::Texture>("crew_g.png");
	thor::ResourceKey<sf::Texture> crewTextureY = thor::Resources::fromFile<sf::Texture>("crew_y.png");

	// load into cache
	std::shared_ptr<sf::Texture> crewTextureBPtr = resourceCache->acquire(crewTextureB);
	std::shared_ptr<sf::Texture> crewTextureYPtr = resourceCache->acquire(crewTextureY);
	std::shared_ptr<sf::Texture> crewTextureGPtr = resourceCache->acquire(crewTextureG);
	resourceCache->acquire(shipPirateTexture);
	resourceCache->acquire(shipNeutralTexture);
	resourceCache->acquire(shipNavyTexture);
	std::shared_ptr<sf::Texture> splashScreenPtr = resourceCache->acquire(splashScreenTexture);
	std::shared_ptr<sf::Texture> playerSmallTexturePtr = resourceCache->acquire(shipSmallTexture);
	std::shared_ptr<sf::Texture> playerLargeTexturePtr = resourceCache->acquire(shipLargeTexture);
	

	//initialize splashscreen
	splashScreenSprite.setTexture(*splashScreenPtr);


	// initialize playerShip
	playerShip = new Ship(playerSmallTexturePtr.get(), 20, 20, 10, neutral, Fighter, playerLargeTexturePtr.get());
	playerShip->setPosition(0,0);

	CrewMember *crewA = new CrewMember(crewTextureYPtr.get(), crewTextureGPtr.get(), "Michaela", 10, 10, 1, 15);
	CrewMember *crewB = new CrewMember(crewTextureBPtr.get(), crewTextureGPtr.get(), "Victor", 10, 10, 1, 15);
	
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