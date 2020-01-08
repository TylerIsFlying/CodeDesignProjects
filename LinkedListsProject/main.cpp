#include <iostream>
#include "tForwardList.h"
#include <string>
int main()
{
	tForwardList<int> listOne;
	listOne.push_front(110);
	listOne.push_front(10);
	listOne.push_front(150);
	listOne.push_front(440);
	listOne.push_front(10);
	listOne.push_front(10);
	listOne.push_front(30);
	listOne.push_front(10);
	listOne.pop_front();
	listOne.remove(10);
	//std::cout << listOne.front() << std::endl;
	//std::cout << listOne.back() << std::endl;
	while (true);
	return 0;
}