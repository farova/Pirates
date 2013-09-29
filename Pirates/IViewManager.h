#if !defined(_I_VIEWMANAGER)
#define _I_VIEWMANAGER

#include <SFML/Graphics.hpp>
#include "GameState.h"

class IViewManager
{
    public:
    
        virtual void drawView( sf::RenderWindow & ) = 0;
        
        void fulfillStateChange()
        {
            _isStateChangeRequested = false;
            _requestState = _baseState;
        };
        
        bool getRequestedStateChange( GameState & state )
        {
            state = _requestState;
            return _isStateChangeRequested;
        };
        
    protected:
    
        bool _isStateChangeRequested;
        GameState _requestState;
        GameState _baseState;
        
        IViewManager( GameState baseState )
        {
            _baseState = baseState;
            _requestState = baseState;
            _isStateChangeRequested = false;
        };
        
        void setRequestState( GameState state )
        {
            if( state != _baseState )
            {
                _isStateChangeRequested = true;
                _requestState = state;
            }
        };
};

#endif