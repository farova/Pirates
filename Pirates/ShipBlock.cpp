#include "ShipBlock.h"


ShipBlock::ShipBlock()
{

}

ShipBlock::~ShipBlock()
{

}

void ShipBlock::initialize(int level, ShipBlockType type, bool ladder, bool blocked)
{
	this->level = level;
	this->type = type;
	this->ladder = ladder;
	this->blocked = blocked;
}

bool ShipBlock::isLadder()
{
	return ladder;
}

bool ShipBlock::isBlocked()
{
	return blocked;
}

int ShipBlock::getLevel()
{
	return level;
}

ShipBlockType ShipBlock::getBlockType()
{
	return type;
}
