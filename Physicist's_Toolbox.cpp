#include <iostream>
#include "declarations.h"
#include "MergedElectrostatics.cpp"
#include "thermodynamics.cpp"
#include "gravitation.cpp"
#include "kinematics.cpp"
#include "dynamics.cpp"
#include "Optics.cpp"

double inputValidator()
{
	double input{};
	while (true)
	{
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nInvalid input. Please try again: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			break;
		}
	}
	return input;
}

void fieldChoice()
{
	std::cout << "Which field of physics do you need help with today?\n\n"
		<< " - electrostatics (1)\n"
		<< " - thermodynamics (2)\n"
		<< " - gravitation (3)\n"
		<< " - kinematics (4)\n"
		<< " - dynamics (5)\n"
		<< " - optics (6)\n\n"
		<< "Field: ";
	int choice{ static_cast<int>(inputValidator()) };
	std::cout << '\n';

	switch (choice)
	{
	case 1:
		std::cout << "---------------------------------------------------------------------------\n";
		electrostatics();
		break;
	case 2:
		std::cout << "---------------------------------------------------------------------------\n";
		thermodynamics();
		break;
	case 3:
		std::cout << "---------------------------------------------------------------------------\n";
		gravitation();
		break;
	case 4:
		std::cout << "---------------------------------------------------------------------------\n";
		kinematics();
		break;
	case 5:
		std::cout << "---------------------------------------------------------------------------\n";
		dynamics();
		break;
	case 6:
		std::cout << "---------------------------------------------------------------------------\n";
		optics();
		break;
	default:
		std::cout << "The number you've chosen does not correspond to any of the existing fields. Please try again: ";
		fieldChoice();
	}
}

int main()
{
	std::cout << "Welcome to Physicist's Toolbox!\n\n"
		<< "Please remember to use International System of Units (SI)\n"
		<< "---------------------------------------------------------------------------\n";
	fieldChoice();

	while (true)
	{
		std::cout << "\n---------------------------------------------------------------------------\n";
		std::cout << "\nDo you wish to calculate anything else? (Y/N): ";
		char endOrNot;
		std::cin >> endOrNot;
		std::cin.ignore(32767, '\n');

		if (endOrNot == 'y' || endOrNot == 'Y')
		{
			std::cout << "\n---------------------------------------------------------------------------\n";
			fieldChoice();
		}
		else
			break;
	}

	std::cout << "\n---------------------------------------------------------------------------\n";
	std::cout << "Thank you for using Physicist's Toolbox! Have a nice day!";
	std::cout << "\n---------------------------------------------------------------------------\n";

	return 0;
}
