#include <iostream>
#include "Runner.h"
#include <string>
int main()
{
	int id = 0;
	std::string data = "";
	Runner run;
	bool quit = true;
	while(quit)
	{
		system("CLS");
		std::cout << "Please put a number for what mode you want to enter. Type quit to quit" << std::endl;
		std::cout << ">> ";
		std::cin >> data;
		if (data == "quit" || data == "Quit")
			quit = false;
		if (data.length() == 1)
			id = std::stoi(data);
		switch (id)
		{
		case 1:
			system("CLS");
			run.WriteExercise();
			break;
		case 2:
			system("CLS");
			run.SaveGameExercise();
			break;
		case 3:
			system("CLS");
			run.DigitalPrinter();
			break;
		case 4:
			system("CLS");
			run.MyInformation();
			break;
		case 5:
			system("CLS");
			run.SaveData();
			break;
		case 6:
			system("CLS");
			run.CommaSeparatedValues();
			break;
		}
	}
	system("CLS");
	std::cout << "You have quited the program." << std::endl;

	// Run all code above
	while (true); // keeps it open
	return 0;
}