#include "MapViewManager.h"


MapViewManager::MapViewManager()
    : IViewManager( Constants::MapViewState )
{

}

void MapViewManager::drawView( sf::RenderWindow & window )
{

}

void MapViewManager::readMapFile()
{
    std::ifstream levelFile ( "levels/test.lvl" );
    
    if ( levelFile.is_open() )
    {
		std::string fileLine;

		//#rows
		std::getline(levelFile, fileLine);
        _numRows = std::stoi(fileLine);

		//#columns
		std::getline(levelFile, fileLine);
		_numColumns = std::stoi(fileLine);
        
		//starting row
		std::getline(levelFile, fileLine);
		_startingRow = std::stoi(fileLine);
        
		//starting column
		std::getline(levelFile, fileLine);
		_startingColumn = std::stoi(fileLine);
        
		//square size
		std::getline(levelFile, fileLine);
		_squareSize = std::stoi(fileLine);
        
        for ( int y = 0; y < _numRows; y++ )
        {
            for ( int x = 0; x < _numColumns; x++ )
            {
				std::getline(levelFile, fileLine);
            }
        }
        
        levelFile.close();
    }
}

void generateBlockProperties()
{

}

void MapViewManager::handleMouseClick( int x, int y, sf::Mouse::Button button )
{
    switch ( button )
    {
        case sf::Mouse::Left:
            leftMouseClick( x, y );
            break;
    }
}

void MapViewManager::leftMouseClick( int x, int y )
{

}