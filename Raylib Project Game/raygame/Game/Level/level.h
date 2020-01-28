#pragma once
#include <string>
#include "raylib.h"
#include <iostream>
class level
{
public:
	std::string name; // the name of the level
	virtual void update(float deltaTime); // updates the level
	virtual void draw(); // draws the level
	virtual void init(); // inits the level
	level();
	~level();
};

