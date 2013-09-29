#if !defined(_MAPVIEWMANAGER_H)
#define _MAPVIEWMANAGER_H

#include "IViewManager.h"

class MapViewManager : public IViewManager
{

    public:
    
        MapViewManager();
        
        void drawView( sf::RenderWindow & );
        
        void handleMouseClick( int, int, sf::Mouse::Button );
        
        void getNextEncounter();
        
};

#endif