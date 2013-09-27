#include "SplashViewManager.h"

SplashViewManager::SplashViewManager()
	: isStateChangeRequested(false), 
	requestState(SplashScreenState), 
	baseState(SplashScreenState)
{

}

SplashViewManager::~SplashViewManager()
{

}

void SplashViewManager::drawView( sf::RenderWindow & window )
{

}