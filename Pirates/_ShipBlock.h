#if !defined(_SHIPBLOCK_H)
#define _SHIPBLOCK_H

#include <SFML/Graphics.hpp>

namespace Pirates
{
    class ShipBlock
    {
    
        public:
            ShipBlock();
            ~ShipBlock();
            
            void initialize ( int, bool, bool );
            void setBlockMatrixPosition ( int, int );
            
            int getLevel();
            sf::Vector2i getBlockMatrixPosition();
            
            bool isLadder();
            bool isBlocked();
            
        private:
        
            sf::Vector2i matrixPosition;
            
            bool blocked;
            bool ladder;
            
            int level;
            
    };
}

#endif  //_SHIPBLOCK_H
