#if !defined(_SHIPVIEWMANAGER_H)
#define _SHIPVIEWMANAGER_H

#include "IViewManager.h"

class ShipViewManager : public IViewManager
{

    public:

        ShipViewManager(thor::ResourceCache<sf::Texture> * textureCache);
        
        void drawView( sf::RenderWindow & );
        
};

#endif