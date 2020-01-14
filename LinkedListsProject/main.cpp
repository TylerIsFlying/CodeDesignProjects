#include <iostream>
#include "tForwardList.h"
#include <string>
int main()
{
	tForwardList<int> listOne;
	listOne.push_front(110);
	listOne.push_front(25);
	listOne.push_front(150);
	listOne.push_front(440);
	listOne.push_front(25);
	listOne.push_front(10);
	listOne.push_front(30);
	listOne.push_front(10);
	listOne.pop_front();
	listOne.remove(25);
	tForwardList<int> listTwo;
	listTwo.push_front(1);
	listTwo.push_front(2);
	listTwo.push_front(2);
	listTwo.push_front(2);
	listTwo.push_front(2);
	listTwo.push_front(3);
	listTwo.push_front(2);
	listTwo.push_front(2);
	listTwo.push_front(2);
	listTwo.resize(20);
	for(auto it = listOne.begin(); it != listOne.end(); ++it)
	{
		std::cout << "VALUE: " << *it << std::endl;
	}
	//std::cout << "COOL: " << *listOne.node << std::endl;
	listTwo = listOne;
	//listTwo.pop_front();
	listOne.clear();
	//std::cout << listOne.front() << std::endl;
	//std::cout << listTwo.front() << std::endl;
	while (true);
	return 0;
}