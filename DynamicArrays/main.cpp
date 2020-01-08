#include <iostream>
#include <string>
#include <vector>
#include "tVector.h"
int main()
{
	tVector<int> tArr;
	for(size_t i = 1; i <= 3; ++i)
	{
		tArr.push_back(i);
	}
	tArr.pop_back();
	tArr.pop_back();
	tVector<int> tArr2 = tArr;
	tArr2.push_back(6);
	tArr2.push_back(7);
	tArr2.push_back(8);
	//tArr.resize(6);
	for (size_t i = 0; i < tArr.size(); ++i)
	{
		std::cout << tArr.data()[i] << std::endl;
	}
	std::cout << tArr.at(0) << std::endl;
	std::cout << tArr.size_capacity() << std::endl;
	tArr2[0] = 5;
	//tArr2.resize(10);
	std::cout << tArr[0] << std::endl;
	std::cout << "\n\n";
	tArr2.reserve(50);
	std::cout << tArr2.size_capacity() << std::endl;
	tArr2.shrink_to_fit();
	std::cout << tArr2.size_capacity() << std::endl;
	tArr2.clear();
	std::cout << tArr2[1] << std::endl;
	for (size_t i = 0; i < tArr2.size_capacity(); ++i)
	{
		if(i < tArr2.size())
			std::cout << tArr2.data()[i] << std::endl;
		else
			std::cout << "-" << std::endl;
		
	}
	while (true);
	return 0;
}