#if !defined(_MAPVIEWMANAGER_H)
#define _MAPVIEWMANAGER_H

#include <fstream>
#include "IViewManager.h"

class MapViewManager : public IViewManager
{

    public:
    
        MapViewManager();
        
        void drawView( sf::RenderWindow & );
        void handleMouseClick( int, int, sf::Mouse::Button );
        
        void getNextEncounter();
        
    private:

		int _numRows;
		int _numColumns;

		int _startingRow;
		int _startingColumn;

		int _squareSize;

		void leftMouseClick( int, int );
		void readMapFile();
		void generateBlockProperties();
};

#endif