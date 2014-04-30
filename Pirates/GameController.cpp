#include "GameController.h"

GameController::GameController( int windowWidth, int windowHeight )
    : _gameState( Constants::GameStateSplashScreen ),
      _mapViewManager( &_textureCache, &_playerShip, windowWidth, windowHeight ),
      _shipViewManager( &_textureCache, &_playerShip ),
      _splashViewManager( &_textureCache ),
      _newGameViewManager( &_textureCache, &_playerShip ),
      _encounterManager( &_textureCache )
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
        case Constants::GameStateSplashScreen:
            _splashViewManager.drawView( window );
            switchState = _splashViewManager.getRequestedStateChange( newState );
            break;
            
        case Constants::GameStateMapView:
            _mapViewManager.drawView( window );
            switchState = _mapViewManager.getRequestedStateChange( newState );
            break;
            
        case Constants::GameStateShipView:
            _shipViewManager.drawView( window );
            switchState = _shipViewManager.getRequestedStateChange( newState );
            break;
            
        case Constants::GameStateNewGameView:
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
        case Constants::GameStateSplashScreen:
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
        case Constants::GameStateSplashScreen:
            _splashViewManager.handleMouseClick();
            break;
            
        case Constants::GameStateNewGameView:
            _newGameViewManager.handleMouseClick();
            break;
            
            
        case Constants::GameStateMapView:
            _mapViewManager.handleMouseClick( x, y, button );
            
            if( _mapViewManager.validMovement() )
            {
                generateEncounter();
            }
            
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

void GameController::generateEncounter()
{
    bool shipEncounter;
    MapBlock* currentShipBlock = _mapViewManager.getCurrentShipBlock();
    
    switch( _encounterManager.getEncounterType( currentShipBlock ) )
    {
        case Constants::EncounterTypeShip:
            shipEncounter = _encounterManager.tryGenerateShipEncounter( currentShipBlock, &_enemyShip );
            break;
    }
    
    if( shipEncounter )
    {
        setGameState( Constants::GameStateShipView );
    }
}
