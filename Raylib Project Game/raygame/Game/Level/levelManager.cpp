#include "levelManager.h"

void levelManager::setup()
{
	levels.push_back(new mainLevel());
}

void levelManager::load(std::string name)
{
	for(auto l : levels)
	{
		if (l->name == name)
		{
			currLevel = l;
			currLevel->init();
		}
	}
}

void levelManager::reload()
{
	currLevel->init();
}

level* levelManager::getLevel()
{
	return currLevel;
}

levelManager & levelManager::get()
{
	static levelManager* instance = new levelManager();
	return *instance;
}


levelManager::levelManager()
{
	setup();
	currLevel = levels[0];
	currLevel->init();
}


levelManager::~levelManager()
{
	for (auto i : levels)
		delete i;
	currLevel = nullptr;
}
