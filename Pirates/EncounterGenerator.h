#if !defined(_ENCOUNTERGENERATOR_H)
#define _ENCOUNTERGENERATOR_H

#include "MapBlock.h"
#include <Thor/Resources.hpp>

enum EncounterType{LandHit, ShipHit};

class EncounterGenerator {

	public:
		EncounterGenerator(MapBlock &, thor::ResourceCache<sf::Texture> *);
		~EncounterGenerator();

		EncounterType getEncounterType();

		bool hitShip();

		LandEncounter& generateLandEncounter();
		Ship* generateShip();

	private:

		Ship * generatePirateShip();
		Ship * generateNavyShip();
		Ship * generateNeutralShip();

		MapBlock mapBlock;
		int hitNumber;

		thor::ResourceCache<sf::Texture> * textureCache;


};

#endif  //_ENCOUNTERGENERATOR_H
