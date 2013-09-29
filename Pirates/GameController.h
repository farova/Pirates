#if !defined(_GAME_CONTROLLER)
#define _GAME_CONTROLLER

#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "ShipViewManager.h"
#include "SplashViewManager.h"
#include "GameState.h"

class GameController : IDrawable
{

    public:
    
    
        GameController();
        ~GameController();
        
        // --- IDrawable
        void draw( sf::RenderWindow & );
        // --- IDrawable
        
        GameState getGameState();
        void setGameState( GameState state );
        
        // event handling
        void handleKeyPress( sf::Keyboard::Key );
        void handleMouseClick( int, int, sf::Mouse::Button );
        void handleMouseRelease( int, int, sf::Mouse::Button );
        void handleMouseDrag( int, int );
        
    private:
    
        GameState _gameState;
        
        // view managers
        ShipViewManager _shipViewManager;
        SplashViewManager _splashViewManager;
        
};

#endif