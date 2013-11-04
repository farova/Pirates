#include "MapViewManager.h"


MapViewManager::MapViewManager(
    thor::ResourceCache<sf::Texture> * textureCache,
    Ship * playerShip,
    int windowWidth,
    int windowHeight
)
    : IViewManager( Constants::MapViewState, textureCache )
{
    _windowWidth = windowWidth;
    _windowHeight = windowHeight;
    _playerShip = playerShip;
    
    readMapFile();
    _playerShip->setMapPosition( _startingRow, _startingColumn, _squareSize );
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
    
    _playerShip->drawSmallShip( window );
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
        
        for ( int y = 0; y < _numRows; ++y )
        {
            std::getline( levelFile, fileLine );
            
            for ( int x = 0; x < _numColumns; ++x )
            {
                if( fileLine[x] == 'L' )
                {
                    _mapBlocks[y * _numColumns + x] = generateBlockProperties( x, y, Constants::LandBlock );
                }
                else if( fileLine[x] == 'W' )
                {
                    _mapBlocks[y * _numColumns + x] = generateBlockProperties( x, y, Constants::WaterBlock );
                }
                else if( fileLine[x] == 'S' )
                {
                    _mapBlocks[y * _numColumns + x] = generateBlockProperties( x, y, Constants::SandBlock );
                }
            }
        }
        
        levelFile.close();
    }
}

MapBlock * MapViewManager::getMapBlock( int x, int y )
{
    return _mapBlocks[y * _numColumns + x];
}

MapBlock * MapViewManager::generateBlockProperties( int x, int y, Constants::MapBlockType type )
{
    std::string filePath;
    
    switch( type )
    {
        case Constants::LandBlock:
            filePath = Constants::imageLandPath;
            break;
            
        case Constants::SandBlock:
            filePath = Constants::imageSandPath;
            break;
            
        case Constants::WaterBlock:
            filePath = Constants::imageWaterPath;
            break;
    }
    
    thor::ResourceKey<sf::Texture> blockTexture = thor::Resources::fromFile<sf::Texture>( filePath );
    std::shared_ptr<sf::Texture> blockTexturePtr = _textureCache->acquire( blockTexture );
    
    return new MapBlock(
               type,
               blockTexturePtr,
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
    _validMovement = false;
    
    // ignore coordinates off screen
    if( x < 0 || y < 0 || x > _windowWidth || y > _windowHeight )
        return;
        
    int newXBlock = floor( x / _squareSize );
    int newYBlock = floor( y / _squareSize );
    
    // ignore land
    if( getMapBlock( newXBlock, newYBlock )->getMapBlockType() != Constants::WaterBlock )
        return;
        
    sf::Vector2i position = _playerShip->getMapPosition();
    
    // only travel to adjacent blocks (no diagonals)
    if( ( abs( position.x - newXBlock ) == 1 && abs( position.y - newYBlock ) == 0 ) ||
            ( abs( position.x - newXBlock ) == 0 && abs( position.y - newYBlock ) == 1 ) )
    {
        _playerShip->setMapPosition( newXBlock, newYBlock, _squareSize );
        _validMovement = true;
    }
}

bool MapViewManager::validMovement()
{
    return _validMovement;
}

MapBlock * MapViewManager::getCurrentShipBlock()
{
    sf::Vector2i position = _playerShip->getMapPosition();
    return getMapBlock(position.x, position.y);
}