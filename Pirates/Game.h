#if !defined(_GAME_H)
#define _GAME_H

#include "MapView.h"
#include "ShipView.h"
#include "BuyView.h"
#include "IGameView.h"
#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>

enum GameState{splashScreenState, mainMenuState, settingsState, mapViewState, shipViewState, buyViewState, aboutState};

class Game : public IGameView {

	public:
		Game();
		~Game();
		
		void drawAll(sf::RenderWindow &);
		void initialize();
		void loadTextureCache(thor::ResourceCache<sf::Texture> *);

		void handleMouseClick(int, int);
		void handleKeyPress();

		void determineEncounter(MapBlock *);
		void generateShipView(MapBlock *);

		bool isGamePlaying();
		bool isInitialized();

		GameState getGameState();

		void setGameState(GameState);
		void setPlayerShip(Ship *);
		void setWindowSize(int, int);

	private:

		void drawSplashScreen(sf::RenderWindow &);
		void drawShipView(sf::RenderWindow &);
		void drawBuyView(sf::RenderWindow &);
		void drawMainMenu(sf::RenderWindow &);
		void drawSettingsMenu(sf::RenderWindow &);
		void drawMapView(sf::RenderWindow &);
		
		bool cacheLoaded;
		bool playing;
		bool initialized;

		int windowHeight;
		int windowWidth;

		GameState gameState;

		MapView *mapView;
		ShipView *shipView;
		BuyView *buyView;

		Ship * playerShip;
		
		thor::ResourceCache<sf::Texture> * textureCache;

		// Graphics
		sf::Sprite splashScreenSprite;

};

#endif  //_GAME_H
