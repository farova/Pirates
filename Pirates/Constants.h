#if !defined(_CONSTANTS_H)
#define _CONSTANTS_H

namespace Pirates
{

    // Game
    enum GameState
    {
        SplashScreenState,
        MainMenuState,
        SettingsState,
        MapViewState,
        ShipViewState,
        BuyViewState,
        AboutState
    };
    
    // Mapblocks
    enum SquareType
    {
        Water,
        Shore,
        Land,
        Island,
        Port
    };
    
    enum Difficulty
    {
        Easy,
        Normal,
        Hard,
        Extreme
    };
    
    enum EncounterType
    {
        LandHit,
        ShipHit
    };
    
    
    // Crew member
    enum ActionType
    {
        NoAction,
        ArmCannon,
        RepairHull,
        SteerShip,
        MopDeck,
        RowOres,
        Sleep,
        Lookout
    };
    
    enum CharacterFacingDirection
    {
        Left,
        Right,
        In,
        Out
    };
    
    // Weapons
    enum WeaponType
    {
    };
    
    // Ship
    enum ShipAlliance
    {
        Neutral,
        Pirate,
        Navy
    };
    
    enum ShipType
    {
        Fighter,
        Shipwreck,
        Stranded,
        FishingShip,
        TransportShip
    };
    
    
    //
    enum MovementStatus
    {
        Initial,
        Moving,
        Final,
        Finished
    };
    
}

#endif  //_CONSTANTS_H
