#if !defined(_SHIPVIEW_H)
#define _SHIPVIEW_H

// TAKEOUT
#include <iostream>
#include "IGameView.h"
#include "ShipBlock.h"
#include "CharacterMovementManager.h"
#include "ShipActionObjectManager.h"
// TAKEOUT

namespace Pirates
{
    class ShipView : public IGameView
    {
    
        public:
            ShipView();
            ~ShipView();
            
            void drawAll( sf::RenderWindow & );
            void initialize();
            void initializeNewEncounter();
            void loadCache( thor::ResourceCache<sf::Texture> * );
            void cleanUp();
            
            void handleMouseClick( int, int, sf::Mouse::Button );
            void handleKeyPress( sf::Keyboard::Key );
            
            void handleSelectionBox( sf::FloatRect & );
            
            void setWindowSize( int, int );
            void setCaracterSize( int, int );
            void setPlayerShip( Ship * );
            void setEnemyShip( Ship * );
            
            bool isInitialized();
            bool isEnemyLoaded();
            bool isFightFinished();
            
        private:
        
            void initializeBlocks();
            
            bool handleCrewClick( int, int );
            void handleShipBlockClick( int, int );
            void handleActionButtonClick( int, int );
            
            void handleCannonButtonClick( ShipActionObject * );
            void handleSteeringWheelButtonClick();
            
            bool isSpriteClicked( sf::Sprite &, float, float );
            
            void deselectAllCrew();
            
            bool initialized;
            bool enemyLoaded;
            bool fightFinished;
            bool cacheLoaded;
            
            Ship *playerShip;
            Ship *enemyShip;
            
            // block properties
            ShipBlock ** shipBlocks;
            int windowHeight;
            int windowWidth;
            int blockHeight;
            int blockWidth;
            int characterHeight;
            int characterWidth;
            int numXBlocks;
            int numYBlocks;
            
            thor::ResourceCache<sf::Texture> * resourceCache;
            
            // graphics
            sf::Sprite backgroundSprite;
            
			// Ship movement management
			CharacterMovementManager movementManager;

			ShipActionObjectManager actionObjectManager;
    };
}

#endif  //_SHIPVIEW_H
