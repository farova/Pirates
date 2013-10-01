#if !defined(_GAME_H)
#define _GAME_H

#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>

#include "IGameView.h"
#include "MapBlock.h"
#include "MouseDragManager.h"
#include "MapView.h"
#include "ShipView.h"
#include "BuyView.h"
#include "EncounterGenerator.h"

// TAKEOUT
#include <iostream>
using namespace std;
// TAKEOUT

namespace Pirates
{
    class Game : public IGameView
    {
    
        public:
            Game();
            ~Game();
            
            void drawAll( sf::RenderWindow & );
            void initialize();
            void loadCache( thor::ResourceCache<sf::Texture> * );
            
            void handleKeyPress( sf::Keyboard::Key );
            void handleMouseClick( int, int, sf::Mouse::Button );
            void handleMouseRelease( int, int, sf::Mouse::Button );
            void handleMouseDrag( int, int );
            
            void determineEncounter( MapBlock * );
            void generateShipView( MapBlock * );
            
            bool isGamePlaying();
            bool isInitialized();
            
            GameState getGameState();
            
            void setGameState( GameState );
            void setPlayerShip( Ship * );
            void setWindowSize( int, int );
            
        private:
        
            void drawSplashScreen( sf::RenderWindow & );
            void drawShipView( sf::RenderWindow & );
            void drawBuyView( sf::RenderWindow & );
            void drawMainMenu( sf::RenderWindow & );
            void drawSettingsMenu( sf::RenderWindow & );
            void drawMapView( sf::RenderWindow & );
            
            void passSelectionBoxToView( sf::FloatRect & );
            
            bool cacheLoaded;
            bool playing;
            bool initialized;
            
            int windowHeight;
            int windowWidth;
            
            GameState gameState;
            
            MouseDragManager mouseDragManager;
            
            MapView *mapView;
            ShipView *shipView;
            BuyView *buyView;
            
            Ship * playerShip;
            
            thor::ResourceCache<sf::Texture> * resourceCache;
            
            // Graphics
            sf::Sprite splashScreenSprite;
            
    };
}

#endif  //_GAME_H
