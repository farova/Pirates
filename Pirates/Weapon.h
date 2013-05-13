#if !defined(_WEAPON_H)
#define _WEAPON_H

#include "Object.h"

class Weapon : public Object {

	public:
		Weapon(sf::Texture *);
		~Weapon();


	private:
		
		int price;

		float criticalChance;
		float attackSpeed;
		float baseDamage;


};

#endif  //_WEAPON_H
