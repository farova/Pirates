#if !defined(_CREWMEMBER_H)
#define _CREWMEMBER_H

#include "Constants.h"
#include "MovableObject.h"
#include "MeleeWeapon.h"

using namespace std;

class CrewMember : public MovableObject {

	public:
		
		CrewMember(sf::Texture *, sf::Texture *, string, int, int, float, int);
		~CrewMember();
		
		// overwritten functions 
		virtual void draw(sf::RenderWindow &);
		virtual void move(float, float);
		virtual void setPosition(float, float);

		int getStrength();
		int getIntelligence();
		string getName();

		bool isCharacterSelected();
		void toggleSelect();
		
		CharacterFacingDirection getFacingDirection();
		void setFacingDirection(CharacterFacingDirection);

		void setStrength(int);
		void setIntelligence(int);

		ActionType getAction();
		bool isPerformingAction();
		void stopPerformingAction();
		void performAction(ActionType);

	private:
		
		ActionType action;

		CharacterFacingDirection facingDirection;

		string name;
		MeleeWeapon * weapon;

		sf::Sprite selectedOverlay;

		bool selected;

		// stats
		int strength;
		int intelligence;

}; 

#endif  //_CREWMEMBER_H