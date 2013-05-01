#if !defined(_CREWMEMBER_H)
#define _CREWMEMBER_H

#include "MovableObject.h"
#include "MeleeWeapon.h"

using namespace std;

class CrewMember : public MovableObject {

	public:
		
		CrewMember(sf::Texture *, string, int, int, int, int);
		~CrewMember();

		int getStrength();
		int getIntelligence();

		void setStrength(int);
		void setIntelligence(int);

	private:
		string name;
		MeleeWeapon * weapon;

		// stats
		int strength;
		int intelligence;

}; 

#endif  //_CREWMEMBER_H