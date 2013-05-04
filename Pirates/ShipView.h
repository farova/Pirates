#if !defined(_SHIPVIEW_H)
#define _SHIPVIEW_H

#include "Ship.h"
#include "CharacterMovementManager.h"
#include "IGameView.h"

class ShipView : public IGameView {

	public:
		ShipView();
		~ShipView();
		
		void drawAll(sf::RenderWindow &);
		void initialize();
		void loadCache(thor::ResourceCache<sf::Texture> *);
		void cleanUp();

		void handleMouseClick(int, int);
		void handleKeyPress();
		
		void setWindowSize(int, int);
		void setCaracterSize(int, int);
		void setPlayerShip(Ship *);
		void setEnemyShip(Ship *);

		bool isInitialized();
		bool isEnemyLoaded();
		bool isFightFinished();

	private:
		
		void initializeBlocks();

		bool handleCrewClick(int,int);
		void handleShipBlockClick(int,int);

		bool isSpriteClicked(sf::Sprite &, float, float);

		void pollActions();

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

};

#endif  //_SHIPVIEW_H
