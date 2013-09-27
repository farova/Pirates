#if !defined(_I_VIEWMANAGER)
#define _I_VIEWMANAGER

#include <SFML/Graphics.hpp>
#include "GameState.h"

class IViewManager
{
    public:
    
        virtual void drawView( sf::RenderWindow & ) = 0;
        
        virtual void fulfillStateChange()
        {
            isStateChangeRequested = false;
            requestState = baseState;
        };
        
        virtual bool requestStateChange( GameState & state )
        {
            state = requestState;
            return isStateChangeRequested;
        };
        
    private:
    
        bool isStateChangeRequested;
        GameState requestState;
        GameState baseState;
        
        virtual void setRequestState( GameState state )
        {
            if( state != baseState )
            {
                isStateChangeRequested = true;
                requestState = state;
            }
        };
};

#endif