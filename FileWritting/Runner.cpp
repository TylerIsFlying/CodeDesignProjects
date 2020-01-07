#include "Runner.h"

void Runner::SaveGameExercise()
{

	File myFile;
	SaveGame save("SaveGame.txt");
	bool quit = true;
	std::string data;
	while(quit)
	{
		system("CLS");
		save.Open(save.filePath);
		save.Save("hello");
		save.Save(10.05f);
		save.Save(false);
		save.Close();
		save.Read();
		std::cout << "Type quit to quit >> ";
		std::cin >> data;
		if (data == "quit" || data == "Quit")
			quit = false;
	}
}

void Runner::WriteExercise()
{
	File myFile;
	std::string data = "";
	std::string myPath = "MyLog.txt";
	bool quit = false;
	while (!quit)
	{
		system("CLS");
		std::cout << "Type quit to quit" << std::endl;
		std::cout << "What do you want to do? (Write,Clear,Display) >> ";
		std::cin >> data;
		if (data == "Write" || data == "write")
		{
			bool exit = false;
			std::cout << std::endl;
			myFile.Open(myPath);
			while (!exit)
			{
				system("CLS");
				std::cout << "Type exit to exit" << std::endl;
				std::cout << "Last Words - " << data << std::endl;
				std::cout << "Write something here >> ";
				std::getline(std::cin, data);
				if (data == "exit" || data == "Exit")
				{
					exit = true;
				}
				else
				{
					std::cout << data;
					myFile.Write(myPath, data);
				}
			}
			myFile.Close();
		}
		if (data == "clear" || data == "Clear")
		{
			myFile.Open(myPath);
			myFile.Close();
		}
		if (data == "Display" || data == "display")
		{
			system("CLS");
			bool exit = false;
			while (!exit)
			{

				while (!myFile.EndLine(myPath))
					std::cout << myFile.Line() << std::endl;
				std::cout << "\nWhen you want to exit type exit >> ";
				std::cin >> data;
				if (data == "exit" || data == "Exit")
				{
					exit = true;
				}
			}
		}
		if (data == "quit" || data == "Quit")
		{
			quit = true;
		}
	}
}

void Runner::DigitalPrinter()
{
	std::string data;
	File myFile;
	std::string myPath = "";
	bool quit = true;
	while (quit)
	{
		std::cout << "What file path do you want to put?" << std::endl;
		std::cout << ">> ";
		std::cin >> data;
		if (data == "quit" || data == "Quit")
			quit = false;
		else
			myPath = data;
		system("CLS");
		if (myFile.Exists(data))
		{
			bool quit2 = true;
			while (quit2)
			{
				std::cout << "Location: " << myPath << std::endl;
				while (!myFile.EndLine(myPath))
					std::cout << myFile.Line() << std::endl;
				std::cout << "Type exit to exit >> ";
				std::cin >> data;
				if (data == "exit" || data == "Exit")
					quit2 = false;
				system("CLS");
			}
		}
		else
		{
			
			std::cout << "Sorry that file path for " << myPath << " does not exist." << std::endl;
		}
	}
}

void Runner::MyInformation()
{
	std::fstream file;
	std::string data;
	File myFile;
	userDetails user;

	std::string myPath = "";
		std::cout << "What file do you want to save your data in?" << std::endl;
		std::cout << "> ";
		std::cin >> data;
		myPath = data;
		if(myFile.Exists(myPath))
		{
			std::cout << "Want to skip? yes or no" << std::endl;
			std::cout << "> ";
			std::cin >> data;
			if(data != "yes")
			{
				std::cout << "Okay! Here we go!" << std::endl;
				std::cout << "Who are you?" << std::endl;
				std::cout << "> ";
				std::cin >> data;
				user.name = data;
				std::cout << "How old are you?" << std::endl;
				std::cout << "> ";
				std::cin >> data;
				user.age = std::stoi(data);
				std::cout << "What is your favorite color?" << std::endl;
				std::cout << "> ";
				std::cin >> data;
				user.color = data;
				file.open(myPath.c_str(), std::ios::out | std::ios::binary);
				file.write((char*)&user, sizeof(userDetails));
				file.close();
			}
			bool quit = true;
			while(quit)
			{
				system("CLS");
				std::cout << myPath << std::endl;
				std::cout << "Status" << std::endl;
				int count = 0;
				file.open(myPath.c_str(), std::ios::in | std::ios::binary);
				file.read((char*)&user, sizeof(userDetails));
				file.close();
				std::cout << "Name: " << user.name << std::endl;
				std::cout << "Age: " << user.age << std::endl;
				std::cout << "Favorite Color: " << user.color << std::endl;
				std::cout << "Type quit to quit \n>";
				std::cin >> data;
				if (data == "quit" || data == "Quit")
					quit = false;
				count = 0;
			}
		}
}

void Runner::SaveData()
{
	std::string datas;
	bool quit = true;
	std::string myPath = "dataStuff.txt";
	saveData data;
	saveData dataf;
	dataf.playerName = "bob";
	data.deathCount = 1;
	data.deepestFloor = 4;
	data.hasBeenBeatenGame = 5;
	data.playerName = "nice";
	data.timePlayed = 6;
	SaveBinaray(myPath,data);
	while(quit)
	{
		system("CLS");
		LoadBinaray(myPath, dataf);
		std::cout << "Player Name:" << dataf.playerName << std::endl;
		std::cout << "type exit to exit> ";
		std::cin >> datas;
		if (datas == "quit" || datas == "Quit")
			quit = false;
	}
}

void Runner::EntityData()
{
	std::fstream file;
}

void Runner::LoadBinaray(std::string myPath, saveData &value)
{
	std::fstream file;
	file.open(myPath.c_str(), std::ios::in | std::ios::binary);
	file.read((char*)&value, sizeof(saveData));
	file.close();
}

void Runner::CommaSeparatedValues()
{
	std::fstream file;
	std::string myPath = "comma.txt";
	std::string buffer;
	int size = 0;
	file.open(myPath, std::ios::in | std::ios::_Nocreate);
	int* arr = nullptr;
	int count = 0;
	std::string tem = "";
	int commaCount = 0;
	while(std::getline(file,buffer))
	{
		if (arr != nullptr)
			delete[] arr;
		arr = new int[buffer.length() + 1];
		for(int i = 0; i < buffer.length() + 1; ++i)
		{
			if(buffer[i] != ',')
			{
				tem += buffer[i];
			}else
			{
				arr[count] = std::stoi(tem);
				tem = "";
				count++;
			}
			if(i == buffer.length()-1)
			{
				arr[count] = std::stoi(tem);
				tem = "";
				count++;
			}
		}
		size = buffer.length() + 1;
	}
	file.clear();
	file.close();
	std::string data;
	bool quit = true;
	while(quit)
	{
		system("CLS");
		for(int i = 0; i < size; ++i)
		{
			std::cout << arr[i] << std::endl;
		}
		std::cout << "type quit if you want to quit. >";
		std::cin >> data;
		if (data == "quit" || data == "Quit")
			quit = false;
	}
}

Runner::Runner()
{
}


Runner::~Runner()
{
}
