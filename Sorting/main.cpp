
#include <iostream>
#include <string>
#include "BubbleSort.h"
int main()
{
	Sorting sort("highscores.cvs",',');
	sort.topScores(50);
	while (true);
	return 0;
}