#include "BubbleSort.h"



void BubbleSort::LoadHighData(std::string path, const char characterSort)
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

void BubbleSort::LoadOrderScores()
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

BubbleSort::BubbleSort(std::string path, const char characterSort)
{
	LoadHighData(path, characterSort);
	LoadOrderScores();
}


BubbleSort::~BubbleSort()
{
}
