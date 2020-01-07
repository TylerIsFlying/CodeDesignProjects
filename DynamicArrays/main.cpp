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
	tVector<int> tArr2(tArr);
	tArr2.push_back(6);
	for (size_t i = 0; i < tArr.size(); ++i)
	{
		std::cout << tArr.data()[i] << std::endl;
	}
	std::cout << tArr.at(0) << std::endl;
	std::cout << tArr.size_capacity() << std::endl;
	while (true);
	return 0;
}