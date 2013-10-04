#include "MapViewManager.h"


MapViewManager::MapViewManager( thor::ResourceCache<sf::Texture> * textureCache )
    : IViewManager( Constants::MapViewState, textureCache )
{
    readMapFile();
}

MapViewManager::~MapViewManager()
{
    for ( int i = 0; i < _numRows * _numColumns; i++ )
    {
        delete _mapBlocks[i];
    }
    
    delete _mapBlocks;
}

void MapViewManager::drawView( sf::RenderWindow & window )
{
    for ( int i = 0; i < _numRows * _numColumns; i++ )
    {
        _mapBlocks[i]->draw( window );
    }
}

void MapViewManager::readMapFile()
{
    std::ifstream levelFile ( "levels/test.lvl" );
    
    if ( levelFile.is_open() )
    {
        std::string fileLine;
        
        //#rows
        std::getline( levelFile, fileLine );
        _numRows = std::stoi( fileLine );
        
        //#columns
        std::getline( levelFile, fileLine );
        _numColumns = std::stoi( fileLine );
        
        //starting row
        std::getline( levelFile, fileLine );
        _startingRow = std::stoi( fileLine );
        
        //starting column
        std::getline( levelFile, fileLine );
        _startingColumn = std::stoi( fileLine );
        
        //square size
        std::getline( levelFile, fileLine );
        _squareSize = std::stoi( fileLine );
        
        _mapBlocks = new MapBlock* [_numRows * _numColumns];
        
        for ( int x = 0; x < _numRows; ++x )
        {
            std::getline( levelFile, fileLine );
            
            for ( int y = 0; y < _numColumns; ++y )
            {
            
                if( fileLine[x] == 'L' )
                {
                    _mapBlocks[x * _numColumns + y] = generateBlockProperties( x, y, Constants::Land );
                }
                else if( fileLine[x] == 'W' )
                {
                    _mapBlocks[x * _numColumns + y] = generateBlockProperties( x, y, Constants::Water );
                }
                else if( fileLine[x] == 'S' )
                {
                    _mapBlocks[x * _numColumns + y] = generateBlockProperties( x, y, Constants::Sand );
                }
            }
        }
        
        levelFile.close();
    }
}

MapBlock * MapViewManager::generateBlockProperties( int x, int y, Constants::MapBlockType type )
{
    sf::Texture texture;
    
    switch( type )
    {
        case Constants::Land:
            texture.loadFromFile( "images/land.jpg" );
            break;
            
        case Constants::Sand:
            texture.loadFromFile( "images/sand.jpg" );
            break;
            
        case Constants::Water:
            texture.loadFromFile( "images/water.jpg" );
            break;
    }
    
    return new MapBlock(
               type,
               texture,
               ( float ) x * _squareSize,
               ( float ) y * _squareSize,
               50, Constants::Medium, //Navy
               50, Constants::Medium, //Pirate
               50 //Neutral
           );
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