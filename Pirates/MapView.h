#if !defined(_MAPVIEW_H)
#define _MAPVIEW_H

#include "Ship.h"
#include "MapBlock.h"
#include "IGameView.h"

class MapView : public IGameView {

	public:
		MapView();
		~MapView();
		
		void drawAll(sf::RenderWindow &);
		void initialize();
		void loadCache(thor::ResourceCache<sf::Texture> *);

		void handleMouseClick(int, int, sf::Mouse::Button);
		void handleKeyPress(sf::Keyboard::Key);
		
		MapBlock * getMapBlockMovedTo();
		
		void setWindowSize(int, int);
		void setPlayerShip(Ship *);

		bool isInitialized();
		bool isValidMove();

	private:
		
		void leftMouseClick(int, int);

		bool cacheLoaded;
		bool validMove;
		bool initialized;
		
		int windowHeight;
		int windowWidth;

		int squareSize;
		MapBlock **mapBlocks;
		
		Ship *playerShip;
		
		thor::ResourceCache<sf::Texture> * resourceCache;

};

#endif  //_MAPVIEW_H
