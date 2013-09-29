#include "GameController.h"

GameController::GameController( int windowWidth, int windowHeight )
    : _gameState( SplashScreenState )
{

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
    bool switchState;
    GameState newState;
    
    switch( this->getGameState() )
    {
        case SplashScreenState:
            _splashViewManager.drawView( window );
            switchState = _splashViewManager.getRequestedStateChange( newState );
            break;
            
        case MapViewState:
            _mapViewManager.drawView( window );
            switchState = _mapViewManager.getRequestedStateChange( newState );
            break;
            
        case ShipViewState:
            _shipViewManager.drawView( window );
            switchState = _shipViewManager.getRequestedStateChange( newState );
            break;
            
        default:
            break;
    }
    
    if( switchState )
    {
        setGameState( newState );
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
