#include "Cannon.h"

Cannon::Cannon( sf::Texture * texture )
    : Weapon( texture )
{

}

Cannon::~Cannon()
{

}

ShipActionObject * Cannon::getActionObject()
{
    return actionObject;
}

void Cannon::setActionObject( ShipActionObject * actionObj )
{
    actionObject = actionObj;
}

bool Cannon::isAssignedToSlot()
{
    return assignedToSlot;
}

void Cannon::setIfAssignedToSlot( bool assigned )
{
    assignedToSlot = assigned;
}
