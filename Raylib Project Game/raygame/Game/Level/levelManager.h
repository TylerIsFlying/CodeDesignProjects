#pragma once
#include "level.h"
#include "Levels/mainLevel.h"
#include <iostream>
#include <string>
#include <vector>
class levelManager
{
private:
	level * currLevel;
	std::vector<level*> levels;
	void setup(); // sets up the levels for the list
public:
	// Variables
	// Functions
	void load(std::string name); // will be used to load the level
	void reload(); // reloads this current level
	level* getLevel(); // gets the current level
	static levelManager& get(); // gets a instance of the class
	// Constructer and Destructer
	levelManager();
	~levelManager();
};

