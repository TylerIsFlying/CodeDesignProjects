#include "object.h"



bool object::isActive()
{
	if (active)
		return true;
	else
		return false;
}

void object::setActive(bool result)
{
	active = result;
}

bool object::operator==(object rhs)
{
	if (rhs.name == this->name)
		return true;
	return false;
}

object::object()
{
	name = "";
	tag = "";
	position = Vector2();
	active = true;
}

object::object(std::string _name, std::string _tag, Texture2D _spriteImage, Vector2 _position)
{
	name = _name;
	tag = _tag;
	spriteImage = _spriteImage;
	position = _position;
	active = true;

}


object::~object()
{
}
