#if !defined(_MAPVIEWMANAGER_H)
#define _MAPVIEWMANAGER_H

#include <fstream>
#include "IViewManager.h"
#include "MapBlockType.h"
#include "MapBlock.h"
#include "ImagePaths.h"
#include "Ship.h"

class MapViewManager : public IViewManager
{

    public:
    
        MapViewManager(
            thor::ResourceCache<sf::Texture> * textureCache,
            Ship * playerShip,
            int windowWidth,
            int windowHeight
        );
        ~MapViewManager();
        
        void drawView( sf::RenderWindow & );
        void handleMouseClick( int, int, sf::Mouse::Button );
        
        bool validMovement();
		MapBlock* getCurrentShipBlock();
        
    private:
    
        bool _validMovement;
        
        Ship * _playerShip;
        MapBlock ** _mapBlocks;
        
        int _windowWidth;
        int _windowHeight;
        
        int _numRows;
        int _numColumns;
        
        int _startingRow;
        int _startingColumn;
        
        int _squareSize;
        
        MapBlock* getMapBlock( int, int );
        void leftMouseClick( int, int );
        void readMapFile();
        MapBlock * generateBlockProperties( int, int, Constants::MapBlockType );
};

#endif