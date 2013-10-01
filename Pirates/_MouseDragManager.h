#if !defined(_MOUSEDRAGMANAGER_H)
#define _MOUSEDRAGMANAGER_H

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

namespace Pirates
{
    class MouseDragManager
    {
    
        public:
            MouseDragManager();
            ~MouseDragManager();
            
            void setStart( int, int );
            void setCurrent( int, int );
            
            void finishSelection();
            bool isValidSelection( int, int );
            
            void setMousePressed( bool );
            bool isMousePressed();
            
            sf::RectangleShape & getRectangle();
            
        private:
        
            void reset();
            
            bool mousePressed;
            
            sf::RectangleShape selection;
    };
}

#endif  //_MOUSEDRAGMANAGER_H
