#if !defined(_SHIPVIEWMANAGER_H)
#define _SHIPVIEWMANAGER_H

#include "IViewManager.h"

class ShipViewManager : IViewManager
{

    public:
        ShipViewManager();
        ~ShipViewManager();
        
        void drawView( sf::RenderWindow & );
        
    private:
    
        bool isStateChangeRequested;
        GameState requestState;
        GameState baseState;
};

#endif