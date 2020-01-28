#include "game.h"

void game::run()
{
	float deltaTime = 0;
	while (!WindowShouldClose())
	{
		// Update
		levelManager::get().getLevel()->update(deltaTime);
		// Draw
		BeginDrawing();
		ClearBackground(RAYWHITE);
		levelManager::get().getLevel()->draw();
		EndDrawing();
	}
}

game::game()
{
}

game::~game()
{
}
