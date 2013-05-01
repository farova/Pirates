#if !defined(_SHIPBLOCKPATH_H)
#define _SHIPBLOCKPATH_H

#include "ShipBlock.h"
#include <SFML/Graphics.hpp>

class ShipBlockPath {

	public:
		ShipBlockPath(ShipBlock *, ShipBlock *);
		~ShipBlockPath();

		bool isLadder();


	private:

		bool ladder;

		ShipBlock * blockHigherLevel;
		ShipBlock * blockLowerLevel;
		
		sf::FloatRect blockHigherDestination;
		sf::FloatRect blockLowerDestination;



};

#endif  //_SHIPBLOCKPATH_H
