#if !defined(_NEWGAMEVIEWMANAGER_H)
#define _NEWGAMEVIEWMANAGER_H

#include <Thor/Resources.hpp>
#include <memory>

#include "IViewManager.h"
#include "Ship.h"
#include "ImagePaths.h"

class NewGameViewManager : public IViewManager
{

    public:
    
        NewGameViewManager( thor::ResourceCache<sf::Texture> * textureCache, Ship * playerShip );
        
        void drawView( sf::RenderWindow & );
        
        void handleMouseClick();
        
        void generateShip();
        
    private:
    
        Ship* _playerShip;
};

#endif