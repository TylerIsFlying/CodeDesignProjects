#pragma once
#include "raylib.h"
class button
{
protected:
	Rectangle myRec;
	Vector2 size;
	Texture2D texture;
public:
	// Variables
	Vector2 position;
	// Functions
	bool onButton(); // returns true if it's over the button
	bool onButtonClick(); // returns true if the button was clicked
	void draw(int width, int height,Color color); // draws the button on the screen
	void draw(); // draws the button on the screen
	void update(); // updates the rec
	Rectangle getRec(); // gets the rectangle
	// Constructer and Destructer
	button(Vector2 position, int width, int height);
	button(Vector2 position, Texture2D texture);
	button(Vector2 position);
	button();
	~button();
};

