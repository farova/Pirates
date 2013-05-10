#if !defined(_CONSTANTS_H)
#define _CONSTANTS_H

// Game
enum GameState{
	SplashScreenState, 
	MainMenuState, 
	SettingsState, 
	MapViewState, 
	ShipViewState, 
	BuyViewState, 
	AboutState
};

// Mapblocks
enum SquareType{
	Water, 
	Shore, 
	Land, 
	Island, 
	Port
};

enum Difficulty{
	Easy, 
	Normal, 
	Hard, 
	Extreme
};

// Crew member
enum CharacterAction {
	NoAction, 
	ArmCannon, 
	RepairHull
};

enum CharacterFacingDirection {
	Left, 
	Right, 
	In, 
	Out
};

// Weapons
enum WeaponType{
};

// Ship 
enum ShipAlliance{
	Neutral, 
	Pirate, 
	Navy
};

enum ShipType{
	Fighter, 
	Shipwreck, 
	Stranded, 
	FishingShip, 
	TransportShip
};




#endif  //_CONSTANTS_H