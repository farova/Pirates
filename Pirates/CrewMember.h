#if !defined(_CREWMEMBER_H)
#define _CREWMEMBER_H

#include "MovableObject.h"
#include "Constants.h"
#include "MeleeWeapon.h"

using namespace std;

namespace Pirates
{
    class CrewMember : public MovableObject
    {
    
        public:
        
            CrewMember( sf::Texture *, sf::Texture *, string, int, int, float, int );
            ~CrewMember();
            
            // overwritten functions
            virtual void draw( sf::RenderWindow & );
            virtual void move( float, float );
            virtual void setPosition( float, float );
            
            void setProfilePicturePosition( float, float );
            void setProfilePictureSelectedOverlayPosition( float, float );
            sf::Sprite & getProfileSprite();
            
            int getStrength();
            int getIntelligence();
            string getName();
            
            bool isCharacterSelected();
            void toggleSelect();
            void Select();
            void Deselect();
            
            CharacterFacingDirection getFacingDirection();
            void setFacingDirection( CharacterFacingDirection );
            
            void setStrength( int );
            void setIntelligence( int );
            
            ActionType getAction();
            bool isPerformingAction();
            void stopPerformingAction();
            void performAction( ActionType );
            
        private:
        
            ActionType action;
            
            CharacterFacingDirection facingDirection;
            
            string name;
            MeleeWeapon * weapon;
            
            sf::Sprite selectedOverlay;
            sf::Sprite profilePicture;
            sf::Sprite profilePictureSelectedOverlay;
            
            bool selected;
            
            // stats
            int strength;
            int intelligence;
            
    };
}
#endif  //_CREWMEMBER_H