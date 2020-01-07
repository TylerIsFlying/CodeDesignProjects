#pragma once
#include "File.h"
class SaveGame : public File
{
private:
	float f;
	bool b;
	char* ch;
public:
	// Variables
	std::string filePath;
	// Functions
	void Read();
	template<typename val>
	void Save(val value); // you put the type you want to store so a float,bool,char
	// Constructers and DeStructers
	SaveGame(std::string filePath);
	SaveGame();
	~SaveGame();
};

template<typename val>
inline void SaveGame::Save(val value)
{
	file << value << "\n";
}
