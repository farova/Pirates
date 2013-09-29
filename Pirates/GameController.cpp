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
            _splashViewManager.drawView( window );
            break;
            
        case MapViewState:
            break;
            
        case ShipViewState:
            _shipViewManager.drawView( window );
            break;
            
        default:
            break;
    }
}

void GameController::handleKeyPress( sf::Keyboard::Key key )
{
    switch( this->getGameState() )
    {
        case SplashScreenState:
            _splashViewManager.handleKeyPress();
            break;
            
        default:
            break;
    }
}

void GameController::handleMouseClick( int x, int y, sf::Mouse::Button button )
{
    switch( this->getGameState() )
    {
        case SplashScreenState:
            _splashViewManager.handleMouseClick();
            break;
            
        default:
            break;
    }
}

void GameController::handleMouseRelease( int x, int y, sf::Mouse::Button button )
{

}

void GameController::handleMouseDrag( int x, int y )
{

}
