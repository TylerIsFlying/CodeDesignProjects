#pragma once
#include <iostream>
#include <fstream>
#include <string>
class File
{
protected:
	std::fstream file;
private:
	//Variables
	std::string buffer;
	bool endCheck;
	bool first;
	//Functions
public:
	//Variables
	//Functions
	bool Exists(std::string filePath);
	void Open(std::string filePath); // will open and will create the file if it doesn't exist
	template<typename T>
	void Write(std::string filePath, T data);
	void Close(); // closes the file
	bool EndLine(std::string filePath); // returns true or false if it's the end of the line
	std::string Line(); // will get the value from the line
	// Constructer and Destructer
	File();
	~File();
};

template<typename T>
inline void File::Write(std::string filePath, T data)
{
	if(first)
	{
		file << data;
		first = false;
	}
	else
		file << data << std::endl;
}
