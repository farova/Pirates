#if !defined(_OBJECT_H)
#define _OBJECT_H

#include <SFML/Graphics.hpp>

class Object {

	public:
		Object(sf::Texture *);
		~Object();

		virtual void draw(sf::RenderWindow &);
		virtual void setPosition(float, float);
		
		sf::Sprite & getSprite();
		sf::Vector2f getPosition();
		void setSprite(sf::Sprite);

	private:
		sf::Sprite objectSprite;
};

#endif  //_OBJECT_H
