#include "ShipViewManager.h"

ShipViewManager::ShipViewManager( thor::ResourceCache<sf::Texture> * textureCache, Ship * playerShip )
    : IViewManager( Constants::GameStateShipView, textureCache )
{
	_playerShip = playerShip;
}

void ShipViewManager::drawView( sf::RenderWindow & window )
{

}