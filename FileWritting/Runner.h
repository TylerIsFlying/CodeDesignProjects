#pragma once
#include "Runner.h"
#include <iostream>
#include <fstream>
#include <string>
#include "File.h"
#include "SaveGame.h"
#include <fstream>
struct userDetails
{
	int age;
	std::string name;
	std::string color;
};
struct saveData
{
	std::string playerName;
	int deathCount;
	int deepestFloor;

	bool hasBeenBeatenGame;

	double timePlayed;
};
struct Entity
{

	float hitpoints;
	float armor;

	int strength;
	int defense;
	int agility;
	int luck;
};
class Runner
{
public:
	void SaveGameExercise();
	void WriteExercise();
	void DigitalPrinter();
	void MyInformation();
	void SaveData();
	void EntityData();
	template<typename T>
	void SaveBinaray(std::string myPath,T valueType);
	void LoadBinaray(std::string myPath, saveData &value);
	void CommaSeparatedValues();
	Runner();
	~Runner();
};

template<typename T>
inline void Runner::SaveBinaray(std::string myPath, T valueType)
{
	std::fstream file;
	file.open(myPath.c_str(), std::ios::out | std::ios::binary);
	file.write((char*)&valueType, sizeof(T));
	file.close();
}