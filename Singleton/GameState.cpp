#include "GameState.h"



GameState::GameState()
{
}

void GameState::operator=(GameState const &)
{
}


GameState & GameState::getInstance()
{
	static GameState* instance = new GameState();
	return *instance;
}

GameState::GStates GameState::getState()
{
	return state;
}

GameState::GStates GameState::setState(GameState::GStates newState)
{
	return state = newState;
}

GameState::~GameState()
{
}
