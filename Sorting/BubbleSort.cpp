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
		j = i - 1;
		while (j >= 0 && scores[j].score > scores[keyValue].score)
		{
			swap(scores, j, keyValue);
			keyValue = j--;
		}
	}
}

void Sorting::MergeSort(std::vector<HighScoreEntry> &arr)
{
	// try this video for merge sorting https://www.youtube.com/watch?v=KF2j-9iSf4Q&feature=youtu.be
	MergeSort(arr,0, arr.size()-1); // calling merge sort override function for leftStart and rightEnd
}

void Sorting::MergeSort(std::vector<HighScoreEntry> &arr, size_t leftStart, size_t end)
{
	if (leftStart < end)
	{
		size_t middle = (leftStart + end) / 2;
		MergeSort(arr, leftStart, middle);
		MergeSort(arr, middle + 1, end);
		MergeHalf(arr, leftStart, middle, end);
	}
}

void Sorting::MergeHalf(std::vector<HighScoreEntry> &arr, size_t leftStart, size_t middle, size_t end)
{
	size_t leftEnd = middle - leftStart + 1;
	size_t rightEnd = end - middle;
	HighScoreEntry *lArr = new HighScoreEntry[leftEnd];
	HighScoreEntry *rArr = new HighScoreEntry[rightEnd];
	for(size_t i = 0; i < leftEnd; i++)
	{
		lArr[i] = arr[leftStart + i];
	}
	for (size_t i = 0; i < rightEnd; i++)
	{
		rArr[i] = arr[middle + i + 1];
	}
	size_t j = 0;
	size_t i = 0;
	for(size_t k = leftStart; k <= end; k++)
	{
		if(j >= rightEnd || (i < leftEnd && lArr[i].score <= rArr[j].score))
		{
			arr[k] = lArr[i++];
		}else
		{
			arr[k] = rArr[j++];
		}
	}
	delete[] lArr;
	delete[] rArr;
}

Sorting::Sorting(std::string path, const char characterSort)
{
	LoadHighData(path, characterSort);
	//LoadOrderScoresBubble();
	//LoadOrderScoresInsert();

	MergeSort(scores); // some merge sorting :)
}


Sorting::~Sorting()
{
}
