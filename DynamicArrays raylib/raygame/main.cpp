#define PER_FRAME_VALUE 5
#include "raylib.h"
#include "tVector.h"
#include <string>
struct Holder
{
	Texture texture;
	Vector2 position;
};
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	std::string presetTextures[3]{ "resources/panda.png",
		"resources/Round/pig.png","resources/Round/snake.png"};
	tVector<Holder> holders;
	int clickCounter = 0;
	int frameCount = PER_FRAME_VALUE;
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		if(IsMouseButtonDown(MOUSE_RIGHT_BUTTON) | IsMouseButtonDown(MOUSE_LEFT_BUTTON) && frameCount >= PER_FRAME_VALUE)
		{
			clickCounter++;
			Holder tmp;
			tmp.position = GetMousePosition();
			tmp.texture = LoadTexture(presetTextures[0].c_str());
			holders.push_back(tmp);
			frameCount = 0;
		}
		frameCount++;
		std::cout << "Size Count: " << holders.size() << std::endl;
		if (holders.empty())
			std::cout << "empty holders" << std::endl;
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		for (size_t i = 0; i < clickCounter; ++i)
		{
			if(holders[i].position.x < GetScreenWidth() && holders[i].position.y < GetScreenHeight())
			{
				DrawTexture(holders[i].texture, holders[i].position.x, holders[i].position.y, WHITE);
				holders[i].position.x += 1;
				holders[i].position.y += 1;
			}
		}
		ClearBackground(RED);
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}