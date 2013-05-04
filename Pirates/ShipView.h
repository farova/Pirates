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
		
		bool handleCrewClick(int,int);
		void handleShipBlockClick(int,int);

		bool isSpriteClicked(sf::Sprite &, float, float);

		bool initialized;
		bool enemyLoaded;
		bool fightFinished;
		bool cacheLoaded;
		
		int windowHeight;
		int windowWidth;

		int characterHeight;
		int characterWidth;
		
		Ship *playerShip;
		Ship *enemyShip;

		thor::ResourceCache<sf::Texture> * resourceCache;
		
		// graphics 
		sf::Sprite backgroundSprite;
		
		// Ship movement management
		CharacterMovementManager movementManager;

};

#endif  //_SHIPVIEW_H
