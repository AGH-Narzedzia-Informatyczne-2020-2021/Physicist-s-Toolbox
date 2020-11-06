#include <iostream>
#include "constants.h"
#include <cmath>

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
			std::cout << "Invalid input. Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			break;
		}
	}
	return input;
}

void gravitationalForce()
{
	std::cout << "Enter the mass of the first object: ";
	double mass1{ inputValidator() };
	std::cout << "Enter the mass of the second object: ";
	double mass2{ inputValidator() };
	std::cout << "Enter the distance between the two objects: ";
	double distance{ inputValidator() };

	auto gravityForce{ (gravityConst * mass1 * mass2) / (distance * distance) };
	std::cout << "The force of gravity is equal to: " << gravityForce << " N\n";
}