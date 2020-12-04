#include <iostream>
#include <cmath>
#include "constants.h"
#include "declarations.h"

double inputValidator()
{
	double input{};
	while (true)
	{
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767,'\n');
			std::cout << "\nInvalid input. Please try again.\n";
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
	std::cout << "Your function of choice: gravitational force!\n"
		<< "---------------------------------------------------------------------------\n\n";
	std::cout << "Enter the mass of the first object: ";
	double mass1{ inputValidator() };
	std::cout << "Enter the mass of the second object: ";
	double mass2{ inputValidator() };
	std::cout << "Enter the distance between the two objects: ";
	double distance{ inputValidator() };

	auto gravityForce{ (gravityConst * mass1 * mass2) / (distance * distance) };
	std::cout << "\nThe force of gravity is equal to: " << gravityForce << " N\n";
}

void potentialEnergy()
{
	std::cout << "Your function of choice: potential energy!\n"
		<< "---------------------------------------------------------------------------\n\n";
	std::cout << "Enter the mass of the first object: ";
	double mass1{ inputValidator() };
	std::cout << "Enter the mass of the second object: ";
	double mass2{ inputValidator() };
	std::cout << "Enter the distance between the two objects: ";
	double distance{ inputValidator() };

	auto potEnergy{ ((-1) * gravityConst * mass1 * mass2) / distance };
	std::cout << "\nThe potential energy between the two objects is equal to: " << potEnergy << " J\n";
}

void gravitationalPotential()
{
	std::cout << "Your function of choice: gravitational potential!\n"
		<< "---------------------------------------------------------------------------\n\n";
	std::cout << "Enter the mass of the object: ";
	double mass{ inputValidator() };
	std::cout << "Enter the distance between the object and the point: ";
	double distance{ inputValidator() };

	auto gravityPotential{ (-1) * gravityConst * mass / distance };
	std::cout << "\nThe gravitational potential at this point is equal to: " << gravityPotential << " J/kg\n";
}

void escapeVelocity()
{
	std::cout << "Your function of choice: escape velocity!\n"
		<< "---------------------------------------------------------------------------\n\n";
	std::cout << "Enter the mass of the planet: ";
	double mass{ inputValidator() };
	std::cout << "Enter the radius of the planet: ";
	double radius{ inputValidator() };

	auto escapeVel{ sqrt(2 * gravityConst * mass / radius) };
	std::cout << "\nThe escape velocity for this planet is equal to: " << escapeVel << " m/s\n";
}

void gravitationalAcceleration()
{
	std::cout << "Your function of choice: gravitational acceleration!\n"
		<< "---------------------------------------------------------------------------\n\n";
	std::cout << "Enter the mass of the planet: ";
	double mass{ inputValidator() };
	std::cout << "Enter the radius of the planet: ";
	double radius{ inputValidator() };

	auto gravityAcceleration{ (gravityConst * mass) / (radius * radius) };
	std::cout << "\nThe gravitational acceleration of this planet is equal to: " << gravityAcceleration << " m/s^2\n";
}

void workAgainstGravity()
{
	std::cout << "Your function of choice: work done against gravity!\n"
		<< "---------------------------------------------------------------------------\n\n";
	std::cout << "Enter the mass of the object you're moving: ";
	double mass1{ inputValidator() };
	std::cout << "Enter the mass of the other object: ";
	double mass2{ inputValidator() };
	std::cout << "Enter the starting distance betweent the objects: ";
	double distance1{ inputValidator() };
	std::cout << "Enter the distance between objects after moving them: ";
	double distance2{ inputValidator() };

	auto workAgGravity{ gravityConst * mass1 * mass2 * (1 / distance1 - 1 / distance2) };
	std::cout << "\nThe work against gravitational force is equal to: " << workAgGravity << " J\n";
}

void latitudeWeight()
{
	std::cout << "Your function of choice: weight at given latitude!\n"
		<< "---------------------------------------------------------------------------\n\n";
	std::cout << "Enter the latitude in degrees: ";
	double latitude{ inputValidator() * pi / 180 };
	std::cout << "Enter the mass of the object: ";
	double mass{ inputValidator() };

	auto weight{ sqrt((gravityConst * EarthMass / EarthRadius) * (gravityConst * EarthMass / pow(EarthRadius, 3) 
				- 2 * pow(EarthSpeed, 2)) + pow(EarthSpeed, 4) * pow(EarthRadius, 2) * pow(cos(latitude), 2) )};
	std::cout << "\nThe weight of the object at that latitude is equal to: " << weight << " N\n";
}

void gravityChoice()
{
	int choice{ static_cast<int>(inputValidator()) };
	std::cout << '\n';

	switch (choice)
	{
	case 1:
		std::cout << "---------------------------------------------------------------------------\n";
		gravitationalForce();
		break;
	case 2:
		std::cout << "---------------------------------------------------------------------------\n";
		potentialEnergy();
		break;
	case 3:
		std::cout << "---------------------------------------------------------------------------\n";
		gravitationalPotential();
		break;
	case 4:
		std::cout << "---------------------------------------------------------------------------\n";
		escapeVelocity();
		break;
	case 5:
		std::cout << "---------------------------------------------------------------------------\n";
		gravitationalAcceleration();
		break;
	case 6:
		std::cout << "---------------------------------------------------------------------------\n";
		workAgainstGravity();
		break;
	case 7:
		std::cout << "---------------------------------------------------------------------------\n";
		latitudeWeight();
		break;
	default:
		std::cout << "The number you've chosen does not correspond to any available function. Please try again: ";
		gravityChoice();
	}
}

void gravitation()
{
	std::cout << "Your chosen field: gravitation\n"
		<< "---------------------------------------------------------------------------\n"
		<< "What function are you looking for?\n\n"
		<< " - gravitational force (1)\n"
		<< " - potential energy (2)\n"
		<< " - gravitational potential (3)\n"
		<< " - escape velocity (4)\n"
		<< " - gravitational acceleration (5)\n"
		<< " - work done against the gravitational force (6)\n"
		<< " - weight of an object at given latitude on Earth (7)\n\n"
		<< "Function: ";
	gravityChoice();
	
	std::cout << "\n---------------------------------------------------------------------------\n";
	std::cout << "\nDo you wish to calculate anything else? (Y/N): ";
	char endOrNot;
	std::cin >> endOrNot;
	std::cin.ignore(32767, '\n');
	
	if (endOrNot == 'y' || endOrNot == 'Y')
	{
		std::cout << "\n---------------------------------------------------------------------------\n";
		gravitation();
	}
}