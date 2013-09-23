#if !defined(_I_DRAWABLE)
#define _I_DRAWABLE

#include <SFML/Graphics.hpp>

class IDrawable
{

    public:
    
        virtual void draw( sf::RenderWindow & ) = 0;
        
};

#endif