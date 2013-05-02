#if !defined(_SHIPBLOCK_H)
#define _SHIPBLOCK_H

#include <SFML/Graphics.hpp>
#include <list>

enum ShipBlockType{};

class ShipBlock {

	public:
		ShipBlock();
		~ShipBlock();

		void initialize(int, ShipBlockType, bool, bool);

		int getLevel();
		ShipBlockType getBlockType();

		bool isLadder();
		bool isBlocked();

	private:

		bool blocked;
		bool ladder;

		int level;

		ShipBlockType type;

};

#endif  //_SHIPBLOCK_H
