#if !defined(_I_GAMEVIEW_H)
#define _I_GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>

class IGameView
{

    public:
    
        virtual void drawAll( sf::RenderWindow & ) = 0;
        
        virtual void loadCache( thor::ResourceCache<sf::Texture> * ) = 0;
        virtual void initialize() = 0;
        virtual bool isInitialized() = 0;
        
        virtual void handleMouseClick( int, int, sf::Mouse::Button ) = 0;
        virtual void handleKeyPress( sf::Keyboard::Key ) = 0;
        
        virtual void setPlayerShip( Ship * ) = 0;
        virtual void setWindowSize( int, int ) = 0;
        
    private:
    
        bool cacheLoaded;
        bool initialized;
        
        int windowHeight;
        int windowWidth;
        
        Ship *playerShip;
};

#endif  //_I_GAMEVIEW_H
