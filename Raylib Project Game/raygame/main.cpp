#include "Game/game.h"

int main()
{
	// Initialization
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Tylers Raylib Game");
	SetTargetFPS(60);
	game::run();
	// De-Initialization
	CloseWindow();        // Close window and OpenGL context

	return 0;
}