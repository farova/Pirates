#if !defined(_CREWMEMBER_H)
#define _CREWMEMBER_H

#include "MovableObject.h"
#include "MeleeWeapon.h"

using namespace std;

class CrewMember : public MovableObject {

	public:
		
		CrewMember(sf::Texture *, sf::Texture *, string, int, int, float, int);
		~CrewMember();
		
		// overwritten functions 
		void draw(sf::RenderWindow &);
		void move(float, float);

		int getStrength();
		int getIntelligence();

		bool isCharacterSelected();
		void toggleSelectCharacter();

		void setStrength(int);
		void setIntelligence(int);

	private:
		string name;
		MeleeWeapon * weapon;

		sf::Sprite selectedOverlay;

		bool selected;

		// stats
		int strength;
		int intelligence;

}; 

#endif  //_CREWMEMBER_H