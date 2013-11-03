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
    // init ship based on users choices

	thor::ResourceKey<sf::Texture> smallShipTexture = thor::Resources::fromFile<sf::Texture>( Constants::imageSmallShip );
	thor::ResourceKey<sf::Texture> largeShipTexture = thor::Resources::fromFile<sf::Texture>( Constants::imageLargeShip);
	thor::ResourceKey<sf::Texture> largeShipOverlayTexture = thor::Resources::fromFile<sf::Texture>( Constants::imageLargeShipOverlay );

	std::shared_ptr<sf::Texture> smallShipTexturePtr = _textureCache->acquire( smallShipTexture );
	std::shared_ptr<sf::Texture> largeShipTexturePtr = _textureCache->acquire( largeShipTexture );
	std::shared_ptr<sf::Texture> largeShipOverlayTexturePtr = _textureCache->acquire( largeShipOverlayTexture );

    _playerShip->initializeNewShip(
        smallShipTexturePtr,
        largeShipTexturePtr,
        largeShipOverlayTexturePtr
    );
}
