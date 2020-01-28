#include "button.h"

bool button::onButton()
{
	if(CheckCollisionPointRec(GetMousePosition(),myRec))
	{
		return true;
	}
	return false;
}

bool button::onButtonClick()
{
	if (CheckCollisionPointRec(GetMousePosition(), myRec))
	{
		if(IsMouseButtonDown(MOUSE_LEFT_BUTTON) || IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
			return true;
	}
	return false;
}

void button::draw(int width, int height, Color color)
{
	DrawRectangle(position.x, position.y,width,height,color);
}

void button::draw()
{
	DrawTexture(texture, position.x, position.y, WHITE);
}

void button::update()
{
	myRec.height = texture.height;
	myRec.width = texture.width;
	myRec.x = position.x;
	myRec.y = position.y;
}

Rectangle button::getRec()
{
	return myRec;
}

button::button(Vector2 position, int width, int height)
{
	this->position = position;
	myRec.width = width;
	myRec.height = height;
	myRec.x = position.x;
	myRec.y = position.y;
}
button::button(Vector2 position, Texture2D texture)
{
	this->position = position;
	this->texture = texture;
	myRec.x = position.x;
	myRec.y = position.y;
	myRec.width = texture.width;
	myRec.height = texture.height;
}
button::button(Vector2 position)
{
	this->position = position;
}

button::button()
{
}



button::~button()
{
}
