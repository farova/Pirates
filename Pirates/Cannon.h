#if !defined(_CANNON_H)
#define _CANNON_H

#include "Weapon.h"

class Cannon : public Weapon {

	public:




	private:
		bool reloaded;
		bool armed;

		int ammoMax;
		int ammoCurrent;
		int attackRange;
		float reloadSpeed;


};

#endif  //_CANNON_H