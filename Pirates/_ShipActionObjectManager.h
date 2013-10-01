#if !defined(_ACTIONOBJECTMANAGER_H)
#define _ACTIONOBJECTMANAGER_H

#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>
#include <list>
#include "ShipActionObject.h"
#include "Cannon.h"
#include "Ship.h"

namespace Pirates
{
    class ShipActionObjectManager
    {
    
        public:
            ShipActionObjectManager();
            ~ShipActionObjectManager();
            
            void loadCache( thor::ResourceCache<sf::Texture> * );
            void setPlayerShip( Ship * );
            void setBlockSize( int, int );
            void initialize();
            void draw( sf::RenderWindow & window );
            
            std::list<ShipActionObject *> & getActionObjects();
            
			void resetAll();
			ShipActionObject * handleObjectClick( int, int );
			ShipActionObject * handleButtonClick( int, int );

			int getHitModifier();
			int getEvadeModifier();
            
        private:
        
            std::list<ShipActionObject *> shipActionObjects;
            
            thor::ResourceCache<sf::Texture> * resourceCache;
            
            Ship * playerShip;
            
            int blockWidth;
            int blockHeight;
            
    };
}

#endif  //_ACTIONOBJECTMANAGER_H
