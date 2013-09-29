#if !defined(_SPLASHVIEWMANAGER_H)
#define _SPLASHVIEWMANAGER_H

#include "IViewManager.h"

class SplashViewManager : public IViewManager
{

    public:
    
        SplashViewManager();
        
        void drawView( sf::RenderWindow & );
        
        // event handling
        void handleMouseClick();
        void handleKeyPress();
        
    private:
    
        sf::Sprite _splashScreenSprite;
        sf::Texture _splashScreenTexture;
        
};

#endif