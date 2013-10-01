#include "SplashViewManager.h"

SplashViewManager::SplashViewManager()
    : IViewManager( Constants::SplashScreenState )
{
    // no need for cache since only showing once
    if( _splashScreenTexture.loadFromFile( "images/splash.jpg" ) )
    {
        _splashScreenSprite.setTexture( _splashScreenTexture );
    }
}

void SplashViewManager::drawView( sf::RenderWindow & window )
{
    window.draw( _splashScreenSprite );
}

void SplashViewManager::handleMouseClick()
{
    setRequestState( Constants::MapViewState );
}

void SplashViewManager::handleKeyPress()
{
    setRequestState( Constants::MapViewState );
}