#include "mainLevel.h"



void mainLevel::update(float deltaTime)
{
	if(!placed)
	{
		// checking if it is the selected one and if it needs to be placed if it does will move towards mouse pos
		for (auto it = objectSpawned.begin(); it != nullptr; ++it)
		{
			if ((*it)->place)
			{
				Vector2 mPos = Vector2();
				mPos.x = GetMouseX() - ((*it)->getTexture().width/2);
				mPos.y = GetMouseY() - ((*it)->getTexture().height / 2);
				(*it)->position = mPos;
				currObject = *it;
				(*it)->update();
			}
		}
		// sets it to being placed if its click with left button
		if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			currObject->place = false;
			placed = true;
			currObject = nullptr;
		}
	}else
	{
		// checking if it wants to be moved and if it does now it needs to be placed
		for (auto it = objectSpawned.begin(); it != nullptr; ++it)
		{
			if((*it)->onButton() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				(*it)->place = true;
				placed = false;
				currObject = *it;
				break;
			}
		}
	}

	// moves the button around
	if (moveButton)
	{
		if (oButton.onButton() && IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))
		{
			moveButton = false;
		}
		Vector2 mPos = Vector2();
		mPos.x = GetMouseX() - (oButton.getRec().width/2);
		mPos.y = GetMouseY() - (oButton.getRec().height/2);
		oButton.position = mPos;
		oButton.update();
	}else
	{
		if (oButton.onButton() && IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON) && !moveButton)
		{
			moveButton = true;
		}
	}
	// just swaps the names number is less than the next one
	if(IsKeyPressed(KEY_R))
	{
		// insert swap
		bool isSorted = false; // used to see if it is sorted yet
		int lUnsorted = objectSpawned.size(); // last unsorted
		objectInteract * lastObject = nullptr;
		while (!isSorted)
		{
			isSorted = true;
			auto it = objectSpawned.begin();
			lastObject = objectSpawned.front();
			objectInteract tmp;
			for (size_t i = 0; i < lUnsorted; ++i)
			{
				if(it != nullptr && std::stoi((*it)->name) > std::stoi(lastObject->name))
				{
					tmp.name = lastObject->name;
					lastObject->name = (*it)->name;
					(*it)->name = tmp.name;
					isSorted = false;
					if (it != nullptr)
						lastObject = *it;
				}
				it++;
			}
			it = objectSpawned.begin();
			lUnsorted--;
		}
	}
	// will reset counter to zero if e is pressed
	if (IsKeyPressed(KEY_E))
		countNames = 0;
}

void mainLevel::draw()
{
	// Drawing the button
	oButton.draw();
	if(oButton.onButton())
	{
		DrawRectangleLinesEx(oButton.getRec(), 3, PINK);
	}
	if (oButton.onButtonClick())
	{
		DrawRectangleLinesEx(oButton.getRec(), 3, GREEN);
	}
	if(!moveButton)
	{
		if (oButton.onButtonClick() && placed)
		{
			objectSpawned.push_back(new objectInteract(GetMousePosition(), currTexture, true,std::to_string(countNames++)));
			placed = false;
		}
	}
	// Drawing lines if you are over the object
	for (auto it = objectSpawned.begin(); it != nullptr; ++it)
	{
		if((*it)->onButton())
		{
			DrawRectangleLinesEx((*it)->getRec(), 3, BLUE);
			DrawText((*it)->name.c_str(), (*it)->position.x+35, (*it)->position.y - 30, 16 ,RED);
		}
		if ((*it)->onButtonClick())
		{
			DrawRectangleLinesEx((*it)->getRec(), 3, GOLD);
		}
		DrawTexture((*it)->getTexture(), (*it)->position.x, (*it)->position.y, WHITE);
	}
	// Drawing a rec and removing the object you want to remove
	if (placed)
	{
		for (auto it = objectSpawned.begin(); it != nullptr; ++it)
		{
			if ((*it)->onButton() && IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
			{
				if ((*it)->onButtonClick())
				{
					DrawRectangleLinesEx((*it)->getRec(), 3, RED);
				}
				currObject = *it++;
				objectSpawned.remove(currObject);
				break;
			}

		}
	}
}

void mainLevel::init()
{
	currTexture = LoadTexture("resources/elephant.png");
	currPosition.x = 100;
	currPosition.y = 100;
	currTexture.width = currTexture.width / 4;
	currTexture.height = currTexture.height / 4;
	oButton = button(currPosition,currTexture);
}

mainLevel::mainLevel()
{
	name = "main";
	placed = true;
	moveButton = false;
}


mainLevel::~mainLevel()
{
}
