#include "MouseDragManager.h"


namespace Pirates
{
    MouseDragManager::MouseDragManager()
    {
        selection.setOutlineThickness( 1 );
        selection.setOutlineColor( sf::Color::Black );
        selection.setFillColor( sf::Color::Transparent );
    }
    
    MouseDragManager::~MouseDragManager()
    {
    
    }
    
    void MouseDragManager::setStart( int x, int y )
    {
        reset();
        mousePressed = true;
        selection.setPosition( x, y );
    }
    
    void MouseDragManager::setCurrent( int x, int y )
    {
        selection.setSize(
            sf::Vector2f(
                x - selection.getPosition().x,
                y - selection.getPosition().y
            )
        );
    }
    
    void MouseDragManager::finishSelection()
    {
        mousePressed = false;
        reset();
    }
    
    bool MouseDragManager::isValidSelection( int x, int y )
    {
        return selection.getPosition().x != x && selection.getPosition().y != y;
    }
    
    void MouseDragManager::reset()
    {
        selection.setPosition( 0, 0 );
        selection.setSize( sf::Vector2f( 0, 0 ) );
    }
    
    void MouseDragManager::setMousePressed( bool pressed )
    {
        mousePressed = pressed;
    }
    
    bool MouseDragManager::isMousePressed()
    {
        return mousePressed;
    }
    
    sf::RectangleShape & MouseDragManager::getRectangle()
    {
        return selection;
    }
}