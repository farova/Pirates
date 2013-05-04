#if !defined(_CharacterMovement_H)
#define _CharacterMovement_H

#include "CrewMember.h"
#include "ShipBlock.h"

enum MovementStatus {Initial, Moving, Final, Finished};

class CharacterMovement {

	public:
		CharacterMovement(CrewMember*, float, float, bool);
		~CharacterMovement();
		
		void setMovementVector(float, float);
		void setMovementVector(sf::Vector2f);
		void setShortestPath(std::list<ShipBlock *>);
		void setStatus(MovementStatus);
		
		bool isActionTriggered();
		CharacterAction getTriggeredAction();
		void setTriggeredAction(CharacterAction);

		MovementStatus getStatus();
		CrewMember * getCrewMember();
		sf::Vector2f getFinalDestination();
		sf::Vector2f getMovementVector();
		std::list<ShipBlock *> & getShortestPath();

	private:

		bool actionTriggered;
		CharacterAction actionToPerform;

		MovementStatus movementStatus;

		CrewMember * crewMember;

		std::list<ShipBlock *> shortestPath;

		sf::Vector2f movementVector;
		sf::Vector2f finalDestination;

};

#endif  //_CharacterMovement_H
