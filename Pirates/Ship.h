#if !defined(_SHIP_H)
#define _SHIP_H

#include "MovableObject.h"
#include "Cannon.h"
#include "CrewMember.h"
#include "MeleeWeapon.h"
#include <list>


class Ship : public MovableObject {

	public:
		Ship(sf::Texture *, int, int, int, ShipAlliance, ShipType, sf::Texture *, sf::Texture *);
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
		sf::Sprite & getLargeShipOverlaySprite();

	private:
		//general ship properties
		ShipAlliance alliance;
		ShipType shipType;
		
		sf::Sprite largeSprite;
		sf::Sprite largeOverlaySprite;

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
