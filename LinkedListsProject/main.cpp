#include <iostream>
#include "tList.h"
#include <string>
int main()
{
	tList<int> listOne;
	listOne.push_front(110);
	listOne.push_front(110);
	listOne.push_front(110);
	listOne.push_back(5);
	listOne.push_back(6);
	listOne.push_front(25);
	listOne.push_front(26);
	listOne.push_back(12);
	listOne.push_front(28);
	listOne.push_front(29);
	listOne.push_back(13);
	
	listOne.pop_back();
	tList<int> listTwo = listOne;
	std::cout << "ADDRES ONE: " << &listOne.front() << std::endl;
	std::cout << "ADDRES TWO: " << &listTwo.front() << std::endl;
	listTwo.remove(29);
	int hello = listOne.front();

	for(auto it = listTwo.end(); it != nullptr; it--)
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