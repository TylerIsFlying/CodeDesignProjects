// singleton patter
#include <iostream>
#include <vector>
#include <string>
#include "GameState.h"
int main()
{
	// Do stuff
	GameState::getInstance().setState(GameState::GameOver);
	switch(GameState::getInstance().getState())
	{
	case GameState::MainMenu:
		std::cout << "Main Menu" << std::endl;
		break;
	case GameState::PlayerSelect:
		std::cout << "Player Choice" << std::endl;
		break;
	case GameState::InGame:
		std::cout << "Gameplay in progress" << std::endl;
		break;
	case GameState::GameOver:
		std::cout << "Game over" << std::endl;
		break;
	default:
		std::cout << "Error: Please put in a valid state 0-3" << std::endl;
		break;
	}
	while (true);
	return 0;
}