#if !defined(_I_VIEWMANAGER)
#define _I_VIEWMANAGER

#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>

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
        
        bool getRequestedStateChange( Constants::GameState & state )
        {
            state = _requestState;
            return _isStateChangeRequested;
        };
        
    protected:
    
        thor::ResourceCache<sf::Texture> * _textureCache;
        
        bool _isStateChangeRequested;
        Constants::GameState _requestState;
        Constants::GameState _baseState;
        
        IViewManager(
            Constants::GameState baseState,
            thor::ResourceCache<sf::Texture> * textureCache
        )
        {
            _textureCache = textureCache;
            _baseState = baseState;
            _requestState = baseState;
            _isStateChangeRequested = false;
        };
        
        void setRequestState( Constants::GameState state )
        {
            if( state != _baseState )
            {
                _isStateChangeRequested = true;
                _requestState = state;
            }
        };
};

#endif