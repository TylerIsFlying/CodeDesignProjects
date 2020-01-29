#include <iostream>
#include <string>
#include <vector>
#include "tHashMap.h"
int main()
{
	tHashMap<std::string,int> hash1(10);
	hash1["BA"] = 200;
	hash1["AB"] = 550;
	std::cout << hash1["AB"] << std::endl;
	while (true);
	return 0;
}