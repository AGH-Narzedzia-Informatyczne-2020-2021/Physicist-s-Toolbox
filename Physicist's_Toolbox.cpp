#include <iostream>
#include "declarations.h"

void fieldChoice()
{
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
	default:
		std::cout << "The number you've chosen does not correspond to any of the existing fields. Please try again: ";
		fieldChoice();
	}
}

int main()
{
	std::cout << "Welcome to Physicist's Toolbox!\n\n"
		<< "Please remember to use International System of Units (SI)\n" 
		<< "---------------------------------------------------------------------------\n"
		<< "Which field of physics do you need help with today?\n\n"
		<< " - elctrostatics(1)\n"
		<< " - thermodynamics(2)\n"
		<< " - gravitation(3)\n"
		<< " - kinematics(4)\n\n"
		<< "Field: ";
	fieldChoice();

	std::cout << "\n---------------------------------------------------------------------------\n";
	std::cout << "Thank you for using Physicist's Toolbox! Have a nice day!\n";
	
	return 0;
}
