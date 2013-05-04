#if !defined(_CREWMEMBER_H)
#define _CREWMEMBER_H

#include "MovableObject.h"
#include "MeleeWeapon.h"

using namespace std;

enum CharacterAction {NoAction, ArmCannon, RepairHull};
enum CharacterFacingDirection {Left, Right, In, Out};

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

		bool isPerformingAction();
		void stopPerformingAction();
		void performAction(CharacterAction);

	private:

		bool performingAction;
		CharacterAction action;

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