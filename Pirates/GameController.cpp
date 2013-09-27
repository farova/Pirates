#include "GameController.h"

GameController::GameController()
    : _gameState( SplashScreenState )
{
    // setup managers
    _shipViewManager = ShipViewManager();
    _splashViewManager = SplashViewManager();
}

GameController::~GameController()
{

}

GameState GameController::getGameState()
{
    return _gameState;
}

void GameController::setGameState( GameState state )
{
    this->_gameState = state;
}

void GameController::draw( sf::RenderWindow & window )
{
    switch( this->getGameState() )
    {
        case SplashScreenState:
            drawSplashScreen( window );
            break;
            
        case MapViewState:
            drawMapView( window );
            break;
            
        case ShipViewState:
            drawShipView( window );
            break;
            
        default:
            break;
    }
}

void GameController::drawSplashScreen( sf::RenderWindow & window )
{
    _splashViewManager.drawView( window );
}

void GameController::drawMapView( sf::RenderWindow & window )
{

}

void GameController::drawShipView( sf::RenderWindow & window )
{
    _shipViewManager.drawView( window );
}