#pragma once
#include "../levelManager.h"
#include "../../Object/object.h"
#include "../../../Utils/tList.h"
#include "../../Object/Objects/objectInteract.h"
#include "../../Object/button.h"
class mainLevel : public level
{
private:
	// Variables
	objectInteract * currObject; // current object ready to be placed
	Texture2D currTexture; // current texture of the button
	Vector2 currPosition; // current position for the button
	tList<objectInteract*> objectSpawned; // linked list of objects
	button oButton; // a button
	bool placed; // checks if the object was placed at it's location
	bool moveButton; // bool to move the button that spawns in stuff
	int countNames; // counts names
public:
	// Functions
	void update(float deltaTime) override;
	void draw() override;
	void init() override;
	// Constructers and Destructers
	mainLevel();
	~mainLevel();
};

