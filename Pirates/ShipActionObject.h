#if !defined(_SHIPACTIONOBJECT_H)
#define _SHIPACTIONOBJECT_H

#include "CrewMember.h"
#include <SFML/Graphics.hpp>

class ShipActionObject {

	public:

		ShipActionObject();
		~ShipActionObject();
		
		void setSpriteCoordinates(float, float);
		sf::Vector2f getSpriteCoordinates();

		void setUsageCoordinates(int, int);
		sf::Vector2i getUsageCoordinates();

		bool isOccupied();
		void setIfOccupied(bool);

		CharacterAction getActionType();
		void setActionType(CharacterAction);

		void setBonuses(float, float);
		void setTexture(sf::Texture *);
		
		float getEscapeBonus();
		float getHitBonus();

	private:

		CharacterAction actionType;

		int usageCoordinateX;
		int usageCoordinateY;

		bool occupied;

		sf::Sprite objectSprite;

		float escapeBonus;
		float hitBonus;

};

#endif  //_SHIPACTIONOBJECT_H