#include "File.h"




bool File::Exists(std::string filePath)
{
	file.open(filePath,std::ios::out | std::ios::_Nocreate);
	if (file.fail())
	{
		file.close();
		return false;
	}
	file.close();
	return true;
}

void File::Open(std::string filePath)
{
	file.open(filePath.c_str(), std::ios::out);
}

void File::Close()
{
	file.flush();
	file.close();
	first = true;
}

bool File::EndLine(std::string filePath)
{
	if(!endCheck)
	{
		endCheck = true;
		file.open(filePath.c_str(), std::ios::out | std::ios::_Nocreate);
	}

	if (std::getline(file, buffer))
	{
		return false;
	}
	file.clear();
	Close();
	endCheck = false;
	return true;
}

std::string File::Line()
{
	return buffer;
}

File::File()
{
	endCheck = false;
	first = true;
}


File::~File()
{
}
