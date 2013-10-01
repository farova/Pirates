#include "ShipBlock.h"


namespace Pirates
{
    ShipBlock::ShipBlock()
    {
    
    }
    
    ShipBlock::~ShipBlock()
    {
    
    }
    
    void ShipBlock::initialize( int level, bool ladder, bool blocked )
    {
        this->level = level;
        this->ladder = ladder;
        this->blocked = blocked;
    }
    
    void ShipBlock::setBlockMatrixPosition( int x, int y )
    {
        matrixPosition.x = x;
        matrixPosition.y = y;
    }
    
    sf::Vector2i ShipBlock::getBlockMatrixPosition()
    {
        return matrixPosition;
    }
    
    bool ShipBlock::isLadder()
    {
        return ladder;
    }
    
    bool ShipBlock::isBlocked()
    {
        return blocked;
    }
    
    int ShipBlock::getLevel()
    {
        return level;
    }
}