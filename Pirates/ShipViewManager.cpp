#include "ShipViewManager.h"

ShipViewManager::ShipViewManager( thor::ResourceCache<sf::Texture> * textureCache )
    : IViewManager( Constants::ShipViewState, textureCache )
{

}

void ShipViewManager::drawView( sf::RenderWindow & window )
{

}