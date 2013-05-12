#if !defined(_SHIPACTIONOBJECT_H)
#define _SHIPACTIONOBJECT_H

#include "Constants.h"
#include "Object.h"
#include <SFML/Graphics.hpp>

class ShipActionObject : Object {

	public:

		ShipActionObject(sf::Texture *);
		~ShipActionObject();

		void draw(sf::RenderWindow &);
		void setPosition(float, float);

		void setUsageCoordinates(int, int);
		sf::Vector2i getUsageCoordinates();

		bool isInBounds(float, float);
		bool isOccupied();
		void setIfOccupied(bool);

		ActionType getActionType();
		void setActionType(ActionType);

		CharacterFacingDirection getActionDirection();
		void setActionDirection(CharacterFacingDirection);

		void setBonuses(float, float);
		
		float getEscapeBonus();
		float getHitBonus();

	private:

		ActionType actionType;
		CharacterFacingDirection actionDirection;

		sf::Time cooldown;
		sf::Clock timeSinceLastUsage;

		int usageCoordinateX;
		int usageCoordinateY;

		bool occupied;

		float escapeBonus;
		float hitBonus;

};

#endif  //_SHIPACTIONOBJECT_H