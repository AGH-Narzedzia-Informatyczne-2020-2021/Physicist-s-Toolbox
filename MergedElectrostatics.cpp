#include <iostream>
#include <cmath>
#include <vector>
#include "constants.h"
#include "declarations.h"

struct Charge {
	double charge;
	double xposition;
	double yposition;
	double distance;
	double sin0;
	double cos0;
};

double sinus(double x0, double y0, double xpos, double ypos)
{
	double sinus = (y0 - ypos) / sqrt((y0 - ypos) * (y0 - ypos) + (x0 - xpos) * (x0 - xpos));
	return sinus;
}

double cosinus(double x0, double y0, double xpos, double ypos)
{
	double cosinus = (x0 - xpos) / sqrt((y0 - ypos) * (y0 - ypos) + (x0 - xpos) * (x0 - xpos));
	return cosinus;
}

void force()
{
	std::cout << "Your function of choice: resultant force!\n"
		<< "---------------------------------------------------------------------------\n\n"
		<< "You will be asked to input these data for each object:\n\n"
		<< " - charge of each object\n"
		<< " - horizontal (x) coordinate of the position of your object\n"
		<< " - vertical (y) coordinate of the position of your object\n"
		<< "\nNumber of objects: ";
	int n{ static_cast<int>(inputValidator()) };
	std::vector<Charge> tablica(n);

	int i;
	for (i = 0; i < n; ++i)
	{
		struct Charge charge0;
		std::cout << "\nObject number " << i + 1 << "\n\n";
		std::cout << "Enter the charge of " << i + 1 << " object: ";
		double c{ inputValidator() };
		charge0.charge = c;

		std::cout << "Enter the horizontal (x) coordinate of the position of your " << i + 1 << " object: ";
		double xp{ inputValidator() };
		charge0.xposition = xp;

		std::cout << "Enter the vertical (y) coordinate of the position of your " << i + 1 << " object: ";
		double yp{ inputValidator() };
		charge0.yposition = yp;
		tablica[i] = charge0;
	}

	std::cout << "\nEnter the coordinates of the point where you want to get to know resultant potenctial: \n";
	std::cout << "X coordinate: ";
	double xres{ inputValidator() };
	std::cout << "Y coordinate: ";
	double yres{ inputValidator() };
	std::cout << "\nEnter the value of the charge: \n";
	double char0{ inputValidator() };

	for (i = 0; i < n; ++i)
	{
		tablica[i].sin0 = sinus(xres, yres, tablica[i].xposition, tablica[i].yposition);
		tablica[i].cos0 = cosinus(xres, yres, tablica[i].xposition, tablica[i].yposition);
	}

	for (i = 0; i < n; ++i)
	{
		double d = (tablica[i].xposition - xres) * (tablica[i].xposition - xres) + (tablica[i].yposition - yres) * (tablica[i].yposition - yres);
		tablica[i].distance = sqrt(d);
		if (tablica[i].distance == 0) {
			printf("ERROR");
		}
	}

	double resForceX{};
	double resForceY{};

	for (i = 0; i < n; ++i)
	{
		resForceX += (tablica[i].charge / (tablica[i].distance) * (tablica[i].distance)) * tablica[i].cos0;
		resForceY += (tablica[i].charge / (tablica[i].distance) * (tablica[i].distance)) * tablica[i].sin0;
	}

	double resForce = sqrt((resForceY * resForceY) + (resForceX * resForceX)) * CoulombConst * char0;

	std::cout << "\nResultantant force wchich acts on the charge in the point (" << xres << " ; " << yres << ") is equal to: "
		<< resForce << " N\n";
}

void potential()
{
	std::cout << "Your function of choice: resultant potential!\n"
		<< "---------------------------------------------------------------------------\n\n"
		<< "You will be asked to input these data for each object:\n\n"
		<< " - charge of each object\n"
		<< " - horizontal (x) coordinate of the position of your object\n"
		<< " - vertical (y) coordinate of the position of your object\n"
		<< "\nNumber of objects: ";
	int n{ static_cast<int>(inputValidator()) };
	std::vector<Charge> tablica(n);

	int i;
	for (i = 0; i < n; ++i)
	{
		struct Charge charge0;
		std::cout << "\nObject number " << i + 1 << "\n\n";
		std::cout << "Enter the charge of " << i + 1 << " object: ";
		double c{ inputValidator() };
		charge0.charge = c;

		std::cout << "Enter the horizontal (x) coordinate of the position of your " << i + 1 << " object: ";
		double xp{ inputValidator() };
		charge0.xposition = xp;

		std::cout << "Enter the vertical (y) coordinate of the position of your " << i + 1 << " object: ";
		double yp{ inputValidator() };
		charge0.yposition = yp;
		tablica[i] = charge0;
	}

	std::cout << "\nEnter the coordinates of the point where you want to get to know resultant potenctial: \n";
	std::cout << "X coordinate: ";
	double xres{ inputValidator() };
	std::cout << "Y coordinate: ";
	double yres{ inputValidator() };

	for (i = 0; i < n; ++i)
	{
		double d = (tablica[i].xposition - xres) * (tablica[i].xposition - xres) + (tablica[i].yposition - yres) * (tablica[i].yposition - yres);
		tablica[i].distance = sqrt(d);
		std::cout << tablica[i].distance << '\n';
	}

	double resPotential{};

	for (i = 0; i < n; ++i)
	{
		resPotential += tablica[i].charge / tablica[i].distance;
	}

	resPotential *= CoulombConst;

	std::cout << "\nResultantant potential in the point (" << xres << " ; " << yres << ") is equal to: "
		<< resPotential << " V\n";
}

void intensity()
{
	std::cout << "Your function of choice: resultant intensity!\n"
		<< "---------------------------------------------------------------------------\n\n"
		<< "You will be asked to input these data for each object:\n\n"
		<< " - charge of each object\n"
		<< " - horizontal (x) coordinate of the position of your object\n"
		<< " - vertical (y) coordinate of the position of your object\n"
		<< "\nNumber of objects: ";
	int n{ static_cast<int>(inputValidator()) };
	std::vector<Charge> tablica(n);

	int i;
	for (i = 0; i < n; ++i)
	{
		struct Charge charge0;
		std::cout << "\nObject number " << i + 1 << "\n\n";
		std::cout << "Enter the charge of " << i + 1 << " object: ";
		double c{ inputValidator() };
		charge0.charge = c;

		std::cout << "Enter the horizontal (x) coordinate of the position of your " << i + 1 << " object: ";
		double xp{ inputValidator() };
		charge0.xposition = xp;

		std::cout << "Enter the vertical (y) coordinate of the position of your " << i + 1 << " object: ";
		double yp{ inputValidator() };
		charge0.yposition = yp;
		tablica[i] = charge0;
	}

	std::cout << "\nEnter the coordinates of the point where you want to get to know resultant potenctial: \n";
	std::cout << "X coordinate: ";
	double xres{ inputValidator() };
	std::cout << "Y coordinate: ";
	double yres{ inputValidator() };

	for (i = 0; i < n; ++i)
	{
		tablica[i].sin0 = sinus(xres, yres, tablica[i].xposition, tablica[i].yposition);
		tablica[i].cos0 = cosinus(xres, yres, tablica[i].xposition, tablica[i].yposition);
	}

	for (i = 0; i < n; ++i)
	{
		double d = (tablica[i].xposition - xres) * (tablica[i].xposition - xres) + (tablica[i].yposition - yres) * (tablica[i].yposition - yres);
		tablica[i].distance = sqrt(d);
		if (tablica[i].distance == 0) {
			printf("ERROR");
		}
	}

	double resIntensX{};
	double resIntensY{};

	for (i = 0; i < n; ++i)
	{
		resIntensX += (tablica[i].charge / (tablica[i].distance) * (tablica[i].distance)) * tablica[i].cos0;
		resIntensY += (tablica[i].charge / (tablica[i].distance) * (tablica[i].distance)) * tablica[i].sin0;
	}

	double resIntens = sqrt((resIntensY * resIntensY) + (resIntensX * resIntensX)) * CoulombConst;

	std::cout << "Resultantant intensivity in the point (" << xres << " ; " << yres << ") is equal to: "
		<< resIntens << " A\n";
}

void electroChoice()
{
	int choice{ static_cast<int>(inputValidator()) };
	std::cout << '\n';

	switch (choice)
	{
	case 1:
		std::cout << "---------------------------------------------------------------------------\n";
		force();
		break;
	case 2:
		std::cout << "---------------------------------------------------------------------------\n";
		potential();
		break;
	case 3:
		std::cout << "---------------------------------------------------------------------------\n";
		intensity();
		break;
	default:
		std::cout << "The number you've chosen does not correspond to any available function. Please try again: ";
		electroChoice();
	}
}

void electrostatics()
{
	std::cout << "Your chosen field: electrostatics\n"
		<< "---------------------------------------------------------------------------\n"
		<< "What function are you looking for?\n\n"
		<< " - resultant electrical force caused by n objects (1)\n"
		<< " - resultant ponetnial caused by n objects (2)\n"
		<< " - resultant intensity caused by n objects (3)\n\n"
		<< "Function: ";
	electroChoice();

	std::cout << "\n---------------------------------------------------------------------------\n";
	std::cout << "\nDo you wish to calculate anything else in this field? (Y/N): ";
	char endOrNot;
	std::cin >> endOrNot;
	std::cin.ignore(32767, '\n');

	if (endOrNot == 'y' || endOrNot == 'Y')
	{
		std::cout << "\n---------------------------------------------------------------------------\n";
		electrostatics();
	}
}