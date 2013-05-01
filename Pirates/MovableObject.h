#if !defined(_MOVEABLEOBJECT_H)
#define _MOVEABLEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Object.h"

class MovableObject : public Object {

	public:
		MovableObject(sf::Texture *, int, int, int);
		
		bool isDead();

		void move(float, float);
		void takeDamage(int);
		void restoreHealth(int);
		void restoreFullHealth();

	private:
		int speed;
		int healthMax;
		int healthCurrent;


};

#endif  //_MOVEABLEOBJECT_H
