#include "ShipViewManager.h"

ShipViewManager::ShipViewManager()
	: isStateChangeRequested(false), 
	requestState(ShipViewState), 
	baseState(ShipViewState)
{

}

ShipViewManager::~ShipViewManager()
{

}

void ShipViewManager::drawView( sf::RenderWindow & window )
{

}