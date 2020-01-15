#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
class Sorting
{
private:
	//Variables
	// Functions
	void LoadHighData(std::string path, const char characterSort); // loads the highscore entry data from the cvs
	void LoadOrderScoresBubble(); // orders the scores in top scores from least to greatest
	void LoadOrderScoresInsert(); // orders the scores in top scores from least to greatest
	void MergeSort(); // basic merge sorting method
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
	void printStatus(std::vector<HighScoreEntry> &v,int start, int end);
	std::vector<HighScoreEntry> topScores(int scoreSize); // has the top scores listed from lowest to biggest
	// Constructer and Destructer
	Sorting(std::string path, const char characterSort);
	~Sorting();
};

template<typename type>
inline void Sorting::swap(std::vector<type> &arr, int a, int b)
{
	type tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

template<typename type>
inline void Sorting::copy(std::vector<type>& a, std::vector<type>& b)
{
	for(size_t i = 0; i < a.size(); ++i)
	{
		b.push_back(a[i]);
	}
}
inline void Sorting::printStatus(std::vector<HighScoreEntry>& v, int start, int end)
{
	for(size_t i = start; i < end; ++i)
	{
		if(i <= v.size()-1)
		{
			std::cout << "Score: " << v[i].score << "  ";
			std::cout << "Level: " << v[i].level << "  ";
			std::cout << "Name: " << v[i].name << "  " << std::endl;
		}
	}
}

inline std::vector<Sorting::HighScoreEntry> Sorting::topScores(int scoreSize)
{
	int end = scoreSize;
	std::vector<HighScoreEntry> tmp;
	if (scoreSize > scores.size())
		scoreSize = scores.size()-1;
	for (size_t i = scores.size(); i > scores.size()-scoreSize-1; --i)
	{
		if (i > scores.size() - 1)
			continue;
		else
		{
			tmp.push_back(scores[i]);
		}
	}
	printStatus(tmp, 0, end);
	return tmp;
}

