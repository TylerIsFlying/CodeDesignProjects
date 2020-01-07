#include "SaveGame.h"



void SaveGame::Read()
{
	int counter = 0;
	while(!EndLine(filePath))
	{
		counter++;
		switch(counter)
		{
		case 1:
			if (ch != nullptr)
			{
				delete[] ch;
			}
			ch = new char[Line().length()];
			for (int i = 0; i < Line().length()+1; ++i)
			{
				ch[i] = Line()[i];
			}
			std::cout << "Char " << ch << std::endl;
			break;
		case 2:
			std::string::size_type size;
			f = std::stof(Line(), &size);
			std::cout << "Float: " << f << std::endl;
			break;
		case 3:
			int in = std::stoi(Line());
			b = in;
			if (b == 1)
				std::cout << "Boolean: True" << std::endl;
			if (b == 0)
				std::cout << "Boolean: False" << std::endl;
			break;
		}
	}
}
SaveGame::SaveGame()
{
}
SaveGame::SaveGame(std::string filePath)
{
	this->filePath = filePath;
	ch = new char[10];
}


SaveGame::~SaveGame()
{
}
