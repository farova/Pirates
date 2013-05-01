#if !defined(_SHIP_H)
#define _SHIP_H

#include "MovableObject.h"
#include "Cannon.h"
#include "CrewMember.h"
#include "MeleeWeapon.h"
#include <list>

// some enums
enum ShipAlliance{neutral, pirate, navy};
enum ShipType{Fighter, Shipwreck, Stranded, FishingShip, TransportShip};

class Ship : public MovableObject {

	public:
		Ship(sf::Texture *, int, int, int, ShipAlliance, ShipType, sf::Texture *);
		~Ship();

		ShipAlliance getShipAlliance();
		ShipType getShipType();

		void drawShip(sf::RenderWindow &);
		
		void addCrewMember(CrewMember *);
		void addCannon(Cannon *);
		void addMeleeWeapon(MeleeWeapon *);

		std::list<CrewMember*> & getCrew();
		std::list<Cannon*> & getCannons();
		std::list<MeleeWeapon*> & getArmory();

		sf::Sprite & getLargeShipSprite();

	private:
		//general ship properties
		ShipAlliance alliance;
		ShipType shipType;
		
		sf::Sprite largeSprite;

		// weapons and crew pointers
		std::list<Cannon*> cannons;
		std::list<MeleeWeapon*> armory;
		std::list<CrewMember*> crew;
		CrewMember* captain;

		// ship storage
		int gold;
		int repairMaterial;

};

#endif  //_SHIP_H
