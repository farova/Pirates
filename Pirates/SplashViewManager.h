#if !defined(_SPLASHVIEWMANAGER_H)
#define _SPLASHVIEWMANAGER_H

#include "IViewManager.h"

class SplashViewManager : IViewManager
{

    public:
        SplashViewManager();
        ~SplashViewManager();
        
        void drawView( sf::RenderWindow & );
        
    private:
    
        bool isStateChangeRequested;
        GameState requestState;
        GameState baseState;
};

#endif