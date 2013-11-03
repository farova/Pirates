#include "MapView.h"

namespace Pirates
{
    MapView::MapView()
        : initialized( false ), cacheLoaded( false )
    {
    
    }
    
    MapView::~MapView()
    {
        delete playerShip;
        
        for( int i = 0; i < 10; i++ )
        {
            delete [] mapBlocks[i];
        }
        
        delete [] mapBlocks;
    }
    
    void MapView::setPlayerShip( Ship * ship )
    {
        playerShip = ship;
    }
    
    void MapView::initialize()
    {
        if( !cacheLoaded )
            return;
            
        thor::ResourceKey<sf::Texture> landBlockResource =  thor::Resources::fromFile<sf::Texture>( "land.jpg" );
        thor::ResourceKey<sf::Texture> sandBlockResource =  thor::Resources::fromFile<sf::Texture>( "sand.jpg" );
        thor::ResourceKey<sf::Texture> waterBlockResource =  thor::Resources::fromFile<sf::Texture>( "water.jpg" );
        
        std::shared_ptr<sf::Texture> landBLockPtr = resourceCache->acquire( landBlockResource );
        std::shared_ptr<sf::Texture> sandBLockPtr = resourceCache->acquire( sandBlockResource );
        std::shared_ptr<sf::Texture> waterBLockPtr = resourceCache->acquire( waterBlockResource );
        
        squareSize = 50;
        int size = 16;
        
        mapBlocks = new MapBlock*[size];
        
        for( int i = 0; i < size; i += 1 )
        {
            mapBlocks[i] = new MapBlock[size];
        }
        
        for( int i = 0; i <= 10; i += 1 )
        {
            for( int j = 0; j <= 10; j += 1 )
            {
                mapBlocks[i][j].initialize( i * squareSize, j * squareSize, Water, *waterBLockPtr.get() );
                mapBlocks[i][j].setPirateParameters( 50, Easy );
                mapBlocks[i][j].setNavyParameters( 50, Normal );
                mapBlocks[i][j].setNeutralParameters( 50 );
            }
        }
        
        for( int i = 11; i < 16; i += 1 )
        {
            for( int j = 0; j < 16; j += 1 )
                mapBlocks[i][j].initialize( i * squareSize, j * squareSize, Shore, *sandBLockPtr.get() );
        }
        
        
        for( int i = 0; i <= 10; i += 1 )
        {
            for( int j = 11; j < 16; j += 1 )
                mapBlocks[i][j].initialize( i * squareSize, j * squareSize, Land, *landBLockPtr.get() );
        }
        
        
        
        initialized = true;
    }
    
    void MapView::handleMouseClick( int x, int y, sf::Mouse::Button button )
    {
        switch ( button )
        {
            case sf::Mouse::Left:
                leftMouseClick( x, y );
                break;
        }
    }
    
    void MapView::leftMouseClick( int x, int y )
    {
        // reset validMove bool
        validMove = false;
        
        if( !isInitialized() )
            return;
            
        // ignore coordinates off screen
        if( x < 0 || y < 0 || x > windowWidth || y > windowHeight )
            return;
            
        int newXBlock = floor( x / squareSize );
        int newYBlock = floor( y / squareSize );
        
        // ignore land
        if( mapBlocks[newXBlock][newYBlock].getSquareType() != Water )
            return;
            
        sf::Vector2f position = playerShip->getPosition();
        
        int currentXBlock = floor( position.x / squareSize );
        int currentYBlock = floor( position.y / squareSize );
        
        // only travel to adjacent blocks (no diagonals)
        if( ( abs( currentXBlock - newXBlock ) == 1 && abs( currentYBlock - newYBlock ) == 0 ) ||
                ( abs( currentXBlock - newXBlock ) == 0 && abs( currentYBlock - newYBlock ) == 1 ) )
        {
            playerShip->setPosition( newXBlock * squareSize, newYBlock * squareSize );
            validMove = true;
        }
    }
    
    MapBlock * MapView::getMapBlockMovedTo()
    {
        sf::Vector2f position = playerShip->getPosition();
        int currentXBlock = floor( position.x / squareSize );
        int currentYBlock = floor( position.y / squareSize );
        
        return &mapBlocks[currentXBlock][currentYBlock];
    }
    
    void MapView::drawAll( sf::RenderWindow &window )
    {
        if( !isInitialized() )
            return;
            
            
        for( int i = 0; i < 16; i += 1 )
        {
            for( int j = 0; j < 16; j += 1 )
                mapBlocks[i][j].draw( window );
        }
        
        
        this->playerShip->draw( window );
        
    }
    
    void MapView::handleKeyPress( sf::Keyboard::Key key )
    {
        if( !isInitialized() )
            return;
    }
    
    bool MapView::isInitialized()
    {
        return initialized;
    }
    
    bool MapView::isValidMove()
    {
        return validMove;
    }
    
    void MapView::setWindowSize( int w, int h )
    {
        windowHeight = h;
        windowWidth = w;
    }
    
    void MapView::loadCache( thor::ResourceCache<sf::Texture> * cache )
    {
        resourceCache = cache;
        cacheLoaded = true;
    }
}