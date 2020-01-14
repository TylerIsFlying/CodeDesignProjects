#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
class BubbleSort
{
private:
	//Variables
	// Functions
	void LoadHighData(std::string path, const char characterSort); // loads the highscore entry data from the cvs
	void LoadOrderScores(); // orders the scores in top scores from least to greatest
	template <typename type>
	void swap(std::vector<type> &arr, int a, int b); // swaps a and b in the array
	template <typename type>
	void copy(std::vector<type> &a, std::vector<type> &b); // copys a vector
public:
	struct HighScoreEntry
	{
		std::string name;
		int score;
		int level;
	};
	// Variables
	std::vector<HighScoreEntry> scores; // has all the scores listed.
	// Functions
	void printStatus(std::vector<HighScoreEntry> &v);
	std::vector<HighScoreEntry> topScores(int scoreSize); // has the top scores listed from lowest to biggest
	// Constructer and Destructer
	BubbleSort(std::string path, const char characterSort);
	~BubbleSort();
};

template<typename type>
inline void BubbleSort::swap(std::vector<type> &arr, int a, int b)
{
	type tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

template<typename type>
inline void BubbleSort::copy(std::vector<type>& a, std::vector<type>& b)
{
	for(size_t i = 0; i < a.size(); ++i)
	{
		b.push_back(a[i]);
	}
}
inline void BubbleSort::printStatus(std::vector<HighScoreEntry>& v)
{
	for(size_t i = 0; i < v.size(); ++i)
	{
		std::cout << "Score: " << v[i].score << "  ";
		std::cout << "Level: " << v[i].level << "  ";
		std::cout << "Name: " << v[i].name << "  " << std::endl;
	}
}

std::vector<BubbleSort::HighScoreEntry> topScores(int scoreSize)
{
}
