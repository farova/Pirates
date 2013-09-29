#if !defined(_MAPVIEWMANAGER_H)
#define _MAPVIEWMANAGER_H

#include "IViewManager.h"

class MapViewManager : IViewManager
{

public:
	MapViewManager();

	void drawView( sf::RenderWindow & );

};

#endif