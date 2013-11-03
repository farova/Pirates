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
    
        MapViewManager( thor::ResourceCache<sf::Texture> * textureCache, Ship * playerShip );
        ~MapViewManager();
        
        void drawView( sf::RenderWindow & );
        void handleMouseClick( int, int, sf::Mouse::Button );
        
        void getNextEncounter();
        
    private:
    
		Ship * _playerShip;
        MapBlock ** _mapBlocks;
        
        int _numRows;
        int _numColumns;
        
        int _startingRow;
        int _startingColumn;
        
        int _squareSize;
        
        void leftMouseClick( int, int );
        void readMapFile();
        MapBlock * generateBlockProperties( int, int, Constants::MapBlockType );
};

#endif