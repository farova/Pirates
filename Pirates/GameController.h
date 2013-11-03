#if !defined(_GAME_CONTROLLER)
#define _GAME_CONTROLLER

#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>

#include "IDrawable.h"
#include "ShipViewManager.h"
#include "SplashViewManager.h"
#include "MapViewManager.h"
#include "GameState.h"
#include "Ship.h"

class GameController : IDrawable
{

    public:
    
        GameController( int, int );
        ~GameController();
        
        // --- IDrawable
        void draw( sf::RenderWindow & );
        // --- IDrawable
        
        Constants::GameState getGameState();
        void setGameState( Constants::GameState state );
        
        // event handling
        void handleKeyPress( sf::Keyboard::Key );
        void handleMouseClick( int, int, sf::Mouse::Button );
        void handleMouseRelease( int, int, sf::Mouse::Button );
        void handleMouseDrag( int, int );
        
    private:
    
		Ship _playerShip;

        Constants::GameState _gameState;
    
		thor::ResourceCache<sf::Texture>  _textureCache;

        // view managers
        ShipViewManager _shipViewManager;
        SplashViewManager _splashViewManager;
        MapViewManager _mapViewManager;
        

};

#endif