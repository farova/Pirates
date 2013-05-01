#if !defined(_SHIPVIEW_H)
#define _SHIPVIEW_H

#include "Ship.h"
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
		void setPlayerShip(Ship *);
		void setEnemyShip(Ship *);

		bool isInitialized();
		bool isEnemyLoaded();
		bool isFightFinished();
		bool isSpriteClicked(sf::Sprite &, float, float);

	private:
		
		bool initialized;
		bool enemyLoaded;
		bool fightFinished;
		bool cacheLoaded;
		
		int windowHeight;
		int windowWidth;
		
		Ship *playerShip;
		Ship *enemyShip;

		thor::ResourceCache<sf::Texture> * resourceCache;
		
		// graphics 
		sf::Sprite backgroundSprite;

};

#endif  //_SHIPVIEW_H
