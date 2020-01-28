#pragma once
#include "../object.h"
#include "../button.h"
class objectInteract : public button
{
private:
public:
	// Variables
	bool place;
	std::string name;
	// Functions
	Texture2D getTexture(); // checks what the texture is

	// Constructer and Destrcuter
	objectInteract();
	objectInteract(Vector2 position, Texture2D texture, bool place, std::string name);
	~objectInteract();
};

