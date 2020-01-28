#include "objectInteract.h"



Texture2D objectInteract::getTexture()
{
	return texture;
}

objectInteract::objectInteract()
{
	place = false;
}

objectInteract::objectInteract(Vector2 position, Texture2D texture, bool place, std::string name)
{
	this->position = position;
	this->texture = texture;
	this->place = place;
	myRec = Rectangle();
	myRec.height = texture.height;
	myRec.width = texture.width;
	myRec.x = position.x;
	myRec.y = position.y;
	this->name = name;
}


objectInteract::~objectInteract()
{
}
