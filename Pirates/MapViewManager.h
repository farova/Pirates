#if !defined(_MAPVIEWMANAGER_H)
#define _MAPVIEWMANAGER_H

#include <fstream>
#include "IViewManager.h"
#include "MapBlockType.h"
#include "MapBlock.h"

class MapViewManager : public IViewManager
{

    public:
    
        MapViewManager( thor::ResourceCache<sf::Texture> * textureCache );
        ~MapViewManager();
        
        void drawView( sf::RenderWindow & );
        void handleMouseClick( int, int, sf::Mouse::Button );
        
        void getNextEncounter();
        
    private:
    
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