#if !defined(_MAPVIEW_H)
#define _MAPVIEW_H

#include "Ship.h"
#include "MapBlock.h"
#include "IGameView.h"
#include "EncounterGenerator.h"

class MapView : public IGameView {

	public:
		MapView();
		~MapView();
		
		void drawAll(sf::RenderWindow &);
		void initialize();
		void loadTextureCache(thor::ResourceCache<sf::Texture> *);

		void handleMouseClick(int, int);
		void handleKeyPress();
		
		MapBlock * getMapBlockMovedTo();
		
		void setWindowSize(int, int);
		void setPlayerShip(Ship *);

		bool isInitialized();
		bool isValidMove();

	private:
		
		bool cacheLoaded;
		bool validMove;
		bool initialized;
		
		int windowHeight;
		int windowWidth;

		int squareSize;
		MapBlock **mapBlocks;
		
		Ship *playerShip;
		
		thor::ResourceCache<sf::Texture> * textureCache;

};

#endif  //_MAPVIEW_H
