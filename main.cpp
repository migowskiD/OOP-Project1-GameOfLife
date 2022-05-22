#include <cstdlib>
#include <ctime>
#include <iostream>
#include "World.h"

int main()
{
	int height, width;
	char command;
	std::srand(std::time(nullptr));
	std::cout << "Author: Dawid Migowski s184819\n";
	std::cout << "Enter the height and width of the board: \n";
	std::cin >> height >> width;
	World w(height, width);
	w.DrawWorld();
	std::cout << "Enter any char to continue or X to end: \n";
	while (std::cin >> command)
	{
		if (command == 'x' || command == 'X')
		{
			break;
		}
		system("cls");
		w.TakeATurn();
		w.DrawWorld();
		std::cout << "Enter any char to continue or X to end: \n";
	}
	w.DeleteAll();
	return 0;
}