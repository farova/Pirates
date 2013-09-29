#if !defined(_SHIPVIEWMANAGER_H)
#define _SHIPVIEWMANAGER_H

#include "IViewManager.h"

class ShipViewManager : IViewManager
{

    public:
        ShipViewManager();
        
        void drawView( sf::RenderWindow & );
        
};

#endif