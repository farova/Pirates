#if !defined(_BUYVIEW_H)
#define _BUYVIEW_H

namespace Pirates
{
    class BuyView : public IGameView
    {
    
        public:
            BuyView();
            ~BuyView();
            
            void drawAll( sf::RenderWindow & );
            void initialize();
            
            void handleMouseClick( int, int );
            void handleKeyPress();
            
            void setWindowSize( int, int );
            virtual void setPlayerShip( Ship * );
            
            bool isInitialized();
            
        private:
        
            bool initialized;
            
            int windowHeight;
            int windowWidth;
            
    };
}

#endif  //_BUYVIEW_H
