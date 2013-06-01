#if !defined(_LANDENCOUNTER_H)
#define _LANDENCOUNTER_H

#include "MeleeWeapon.h"
#include "Cannon.h"
#include "CrewMember.h"

class LandEncounter
{

    public:
        LandEncounter();
        ~LandEncounter();
        
    private:
    
        bool allowFullRepairs;
        
        float tax;
        
        int gold;
        int repairMaterials;
        
        MeleeWeapon *weapons;
        Cannon *cannons;
        CrewMember *crewMembers;
        
};

#endif  //_LANDENCOUNTER_H