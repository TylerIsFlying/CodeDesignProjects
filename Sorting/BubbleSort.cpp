#include "BubbleSort.h"



void Sorting::LoadHighData(std::string path, const char characterSort)
{
	std::fstream file;
	std::string buffer;
	int count = 0;
	file.open(path.c_str(),std::ios::in);
	if(!file.fail())
	{
		while(std::getline(file,buffer))
		{
			if (buffer[0] != '\0' && count > 0)
			{
				std::string adder = "";
				HighScoreEntry tmp;
				int counter = 0;
				for(size_t i = 0; i < buffer.length(); ++i)
				{
					if(buffer[i] != characterSort)
					{
						adder += buffer[i];
					}
					if(buffer[i] == characterSort || i == buffer.length()-1)
					{
						++counter;
						switch (counter)
						{
						case 1:
							tmp.name = adder;
							break;
						case 2:
							tmp.score = std::stoi(adder.c_str());
							break;
						case 3:
							tmp.level = std::stoi(adder.c_str());
							break;
						}
						adder = "";
					}
				}
				scores.push_back(tmp);
			}
			if(buffer[0] != '\0')
				count++;
		}
		file.clear();
	}
	file.close();
}

void Sorting::LoadOrderScoresBubble()
{
	// Bubble sorting
	bool isSorted = false; // used to see if it is sorted yet
	int lUnsorted = scores.size(); // last unsorted
	while (!isSorted)
	{
		isSorted = true;
		for(size_t i = 0; i < lUnsorted; ++i)
		{
			if(i+1 < lUnsorted && scores[i].score > scores[i + 1].score)
			{
				swap(scores,i,i+1);
				isSorted = false;
			}
		}
		lUnsorted--;
	}
}

void Sorting::LoadOrderScoresInsert()
{
	// insert swap
	int j = 0;
	int keyValue = 0;
	for(int i = 0; i < scores.size(); ++i)
	{
		keyValue = i;
		if (i - 1 > 0)
			j = i - 1;
		while (j >= 0 && scores[j].score > scores[keyValue].score)
		{
			swap(scores, j, keyValue);
			keyValue = j--;
		}
	}
}

void Sorting::MergeSort()
{
	// try this video for merge sorting https://www.youtube.com/watch?v=KF2j-9iSf4Q&feature=youtu.be
	int startLeft = 0;
	int endRight = scores.size()-1;
	int middle = (startLeft+endRight)/2;
	int startRight = middle+1;
	int endLeft = middle;
	// above is the basic idea will make more functions for merge sorting so it is a bit better
}

Sorting::Sorting(std::string path, const char characterSort)
{
	LoadHighData(path, characterSort);
	//LoadOrderScoresBubble();
	LoadOrderScoresInsert();
}


Sorting::~Sorting()
{
}
