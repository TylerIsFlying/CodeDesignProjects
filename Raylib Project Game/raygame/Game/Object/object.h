#pragma once
#include "raylib.h"
#include <string>
class object
{
private:
	bool active;
public:
	std::string name; // name of the object
	std::string tag; // the tag of the object
	Texture2D spriteImage; // sprite image of the object
	Vector2 position; // position of the object
	bool isActive(); // checks if it is active
	void setActive(bool result); // sets the active to false or true;
	bool operator==(object rhs);
	object();
	object(std::string _name, std::string _tag, Texture2D _spriteImage, Vector2 _position);
	~object();
};

