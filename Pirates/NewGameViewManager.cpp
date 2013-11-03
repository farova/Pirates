#include "NewGameViewManager.h"


NewGameViewManager::NewGameViewManager( thor::ResourceCache<sf::Texture> * textureCache, Ship * playerShip )
    : IViewManager( Constants::NewGameViewState, textureCache )
{
    _playerShip = playerShip;
}

void NewGameViewManager::drawView( sf::RenderWindow & )
{

}

void NewGameViewManager::handleMouseClick()
{
    setRequestState( Constants::MapViewState );
    generateShip();
}

void NewGameViewManager::generateShip()
{
    // init ship
    
    
    
    
    
    
    
}
