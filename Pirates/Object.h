#if !defined(_OBJECT_H)
#define _OBJECT_H

#include <SFML/Graphics.hpp>

class Object {

	public:
		Object(sf::Texture *);
		~Object();

		virtual void draw(sf::RenderWindow &);
		
		sf::Sprite & getSprite();
		void setSprite(sf::Sprite);
		void setPosition(float, float);
		sf::Vector2f getPosition();

	private:
		sf::Sprite objectSprite;
};

#endif  //_OBJECT_H
