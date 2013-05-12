#if !defined(_CANNON_H)
#define _CANNON_H

#include "Weapon.h"
#include "ShipActionObject.h"

class Cannon : public Weapon {

	public:


		ShipActionObject getActionObject();
		void setActionObject(ShipActionObject);

	private:
		bool reloaded;
		bool armed;

		ShipActionObject * actionObject;

		int ammoMax;
		int ammoCurrent;
		int attackRange;
		float reloadSpeed;


};

#endif  //_CANNON_H