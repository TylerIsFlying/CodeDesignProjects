#pragma once
class GameState
{
public:
	enum GStates
	{
		MainMenu = 0,
		PlayerSelect,
		InGame,
		GameOver,
	};
	static GameState& getInstance();
	GStates getState();
	GStates setState(GameState::GStates newState); 
	~GameState();
private:
	GameState();
	GameState(GameState const&); // prevents external use
	void operator=(GameState const&); // prevents external use
	GStates state = MainMenu;
};

