#if !defined(_GAME_CONTROLLER)
#define _GAME_CONTROLLER

#include <SFML/Graphics.hpp>

class GameController : IDrawable
{

    public:
    
        enum GameState
        {
            ShipViewState,
            SplashScreenState,
            MapViewState
        };
        
        GameController();
        ~GameController();
        
		// --- IDrawable
		void draw( sf::RenderWindow & );
		// --- IDrawable
        
        GameState getGameState();
        void setGameState( GameState state );
        
        
    private:
    
        GameState _gameState;
        
        void drawShipView( sf::RenderWindow & );
        void drawSplashScreen( sf::RenderWindow & );
        void drawMapView( sf::RenderWindow & );
        
}

#endif