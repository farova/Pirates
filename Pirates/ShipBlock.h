#if !defined(_SHIPBLOCK_H)
#define _SHIPBLOCK_H

#include "ShipBlockPath.h"
#include <SFML/Graphics.hpp>
#include <list>

class ShipBlock {

	public:
		ShipBlock();
		~ShipBlock();

		bool isPointInBounds(float, float);
		int getLevel();

		// virtual void performBlockAction();


	private:

		int level;

		sf::FloatRect bounds;

		std::list<ShipBlockPath *> lowerPaths;
		std::list<ShipBlockPath *> higherPaths;

};

#endif  //_SHIPBLOCK_H
