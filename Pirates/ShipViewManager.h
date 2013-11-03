#if !defined(_SHIPVIEWMANAGER_H)
#define _SHIPVIEWMANAGER_H

#include "IViewManager.h"
#include "Ship.h"

class ShipViewManager : public IViewManager
{

    public:
    
        ShipViewManager( thor::ResourceCache<sf::Texture> * textureCache, Ship * playerShip );
        
        void drawView( sf::RenderWindow & );
        
    private:

        Ship * _playerShip;
};

#endif