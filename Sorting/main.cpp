
#include <iostream>
#include <string>
#include "BubbleSort.h"
int main()
{
	BubbleSort sort("highscores.cvs",',');
	sort.printStatus(sort.scores);
	while (true);
	return 0;
}