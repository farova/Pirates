#include "GameController.h"

GameController::GameController( int windowWidth, int windowHeight )
    : _gameState( Constants::SplashScreenState ),
      _mapViewManager( &_textureCache, &_playerShip ),
      _shipViewManager( &_textureCache, &_playerShip ),
      _splashViewManager( &_textureCache ),
      _newGameViewManager( &_textureCache, &_playerShip )
{

}

GameController::~GameController()
{

}

Constants::GameState GameController::getGameState()
{
    return _gameState;
}

void GameController::setGameState( Constants::GameState state )
{
    this->_gameState = state;
}

void GameController::draw( sf::RenderWindow & window )
{
    bool switchState;
    Constants::GameState newState;
    
    switch( this->getGameState() )
    {
        case Constants::SplashScreenState:
            _splashViewManager.drawView( window );
            switchState = _splashViewManager.getRequestedStateChange( newState );
            break;
            
        case Constants::MapViewState:
            _mapViewManager.drawView( window );
            switchState = _mapViewManager.getRequestedStateChange( newState );
            break;
            
        case Constants::ShipViewState:
            _shipViewManager.drawView( window );
            switchState = _shipViewManager.getRequestedStateChange( newState );
            break;
            
        case Constants::NewGameViewState:
            _newGameViewManager.drawView( window );
            switchState = _newGameViewManager.getRequestedStateChange( newState );
            break;
            
        default:
            switchState = false;
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
        case Constants::SplashScreenState:
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
        case Constants::SplashScreenState:
            _splashViewManager.handleMouseClick();
            break;
            
        case Constants::NewGameViewState:
            _newGameViewManager.handleMouseClick();
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
