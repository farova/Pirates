#include "SplashViewManager.h"

SplashViewManager::SplashViewManager()
    : IViewManager( SplashScreenState )
{
    // no need for cache since only showing once
    _splashScreenTexture.loadFromFile( "images/splash.jpg" );
    _splashScreenSprite.setTexture( _splashScreenTexture );
}

void SplashViewManager::drawView( sf::RenderWindow & window )
{
    window.draw( _splashScreenSprite );
}

void SplashViewManager::handleMouseClick()
{
    setRequestState( MapViewState );
}

void SplashViewManager::handleKeyPress()
{
	setRequestState( MapViewState );
}