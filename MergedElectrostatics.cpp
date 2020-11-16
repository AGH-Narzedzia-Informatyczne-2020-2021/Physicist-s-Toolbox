//Merged elelectrostatics
#include <iostream>
#include "constants.h"

using mainspace std;

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

void Force()
{

	cout << endl << "You will be asked to input these data for each object:" << endl;
	cout << "1. Charge expressed in Culombs e.g. 1 or -5.5" << endl;
	cout << "2. Horizontal (x) coordinate of the position of your object" << endl;
	cout << "3. Vertical (y) coordinate of the position of your object" << endl;

	cout << "Type how many objects will we be considering?" << endl;
	unsigned int n;
	cin >> n;

	struct Charge tablica[n];

	int i;
	for (i = 0; i < n; ++i)
	{
		struct Charge charge0;
		cout << endl << "Object number " << i + 1 << endl << endl;
		cout << "Input the charge of " << i + 1 << " object expressed in Culombs : ";
		double c;
		cin >> c;
		charge0.charge = c;

		cout << "Input the horizontal (x) coordinate of the position of your " << i + 1 << " object expressed in meters : ";
		double xp;
		cin >> xp;
		charge0.xposition = xp;

		cout << "Input the vertical (y) coordinate of the position of your " << i + 1 << " object expressed in meters : ";
		double yp;
		cin >> yp;
		charge0.yposition = yp;
		tablica[i] = charge0;

		//cout << tablica[i].xposition<<endl;
	}

	cout << endl << "Input the coordinates of the point where you want to get to know resultant potenctial " << endl;
	cout << "X coordinate: ";
	double xres = 0, yres = 0;
	cin >> xres;
	cout << "Y coordinate: ";
	cin >> yres;
	cout << endl << "Input the value of the charge expressed in Culoumbs: " << endl;
	double char0 = 0;
	cin >> char0;

	for (i = 0; i < n; ++i)
	{
		tablica[i].sin0 = sinus(xres, yres, tablica[i].xposition, tablica[i].yposition);
		tablica[i].cos0 = cosinus(xres, yres, tablica[i].xposition, tablica[i].yposition);
	}

	for (i = 0; i < n; i++)
	{
		double d = (tablica[i].xposition - xres) * (tablica[i].xposition - xres) + (tablica[i].yposition - yres) * (tablica[i].yposition - yres);
		tablica[i].distance = sqrt(d);
		if (tablica[i].distance == 0) {
			printf("ERROR");
		}
		//cout << tablica[i].distance << endl;
	}

	double resForceX = 0, resForceY = 0;

	for (i = 0; i < n; i++)
	{
		resForceX += (tablica[i].charge / (tablica[i].distance) * (tablica[i].distance)) * tablica[i].cos0;
		resForceY += (tablica[i].charge / (tablica[i].distance) * (tablica[i].distance)) * tablica[i].sin0;
	}

	double resForce = sqrt((resForceY * resForceY) + (resForceX * resForceX)) * vacuumElectr * char0;

	cout << "Resultantant force wchich acts on the charge " << char0 << "in the point (" << xres << " ; " << yres << ") equals: " << endl;
	cout << resForce << " Newtons" << endl;

}

void Potential()
{
	cout << "Type how many objects will we be considering?" << endl;
	unsigned int n;
	cin >> n;
	cout << endl << "You will be asked to input these data for each object:" << endl;
	cout << "1. Charge expressed in Culombs e.g. 1 or -5.5" << endl;
	cout << "2. Horizontal (x) coordinate of the position of your object" << endl;
	cout << "3. Vertical (y) coordinate of the position of your object" << endl;

	struct Charge tablica[n];

	int i;
	for (i = 0; i < n; i++)
	{
		struct Charge charge0;
		cout << endl << "Object number " << i + 1 << endl << endl;
		cout << "Input the charge of " << i + 1 << " object expressed in Culombs : ";
		double c;
		cin >> c;
		charge0.charge = c;

		cout << "Input the horizontal (x) coordinate of the position of your " << i + 1 << " object expressed in meters : ";
		double xp;
		cin >> xp;
		charge0.xposition = xp;

		cout << "Input the vertical (y) coordinate of the position of your " << i + 1 << " object expressed in meters : ";
		double yp;
		cin >> yp;
		charge0.yposition = yp;
		tablica[i] = charge0;

		//cout << tablica[i].xposition<<endl;
	}

	cout << endl << "Input the coordinates of the point where you want to get to know resultant potenctial " << endl;
	cout << "X coordinate: ";
	double xres = 0, yres = 0;
	cin >> xres;
	cout << "Y coordinate: ";
	cin >> yres;

	for (i = 0; i < n; i++)
	{
		double d = (tablica[i].xposition - xres) * (tablica[i].xposition - xres) + (tablica[i].yposition - yres) * (tablica[i].yposition - yres);
		tablica[i].distance = sqrt(d);
		cout << tablica[i].distance << endl;
	}

	double resPotential = 0;

	for (i = 0; i < n; i++)
	{
		resPotential += tablica[i].charge / tablica[i].distance;
	}

	resPotential *= vacuumElectr;

	cout << "Your resultantant potencial in the point (" << xres << " ; " << yres << ") equals: " << endl;
	cout << resPotential << " Volts" << endl;

}

void Intensity()
{

	cout << endl << "You will be asked to input these data for each object:" << endl;
	cout << "1. Charge expressed in Culombs e.g. 1 or -5.5" << endl;
	cout << "2. Horizontal (x) coordinate of the position of your object" << endl;
	cout << "3. Vertical (y) coordinate of the position of your object" << endl;

	cout << "Type how many objects will we be considering?" << endl;
	unsigned int n;
	cin >> n;

	struct Charge tablica[n];

	int i;
	for (i = 0; i < n; ++i)
	{
		struct Charge charge0;
		cout << endl << "Object number " << i + 1 << endl << endl;
		cout << "Input the charge of " << i + 1 << " object expressed in Culombs : ";
		double c;
		cin >> c;
		charge0.charge = c;

		cout << "Input the horizontal (x) coordinate of the position of your " << i + 1 << " object expressed in meters : ";
		double xp;
		cin >> xp;
		charge0.xposition = xp;

		cout << "Input the vertical (y) coordinate of the position of your " << i + 1 << " object expressed in meters : ";
		double yp;
		cin >> yp;
		charge0.yposition = yp;
		tablica[i] = charge0;

		//cout << tablica[i].xposition<<endl;
	}

	cout << endl << "Input the coordinates of the point where you want to get to know resultant potenctial " << endl;
	cout << "X coordinate: ";
	double xres = 0, yres = 0;
	cin >> xres;
	cout << "Y coordinate: ";
	cin >> yres;

	for (i = 0; i < n; ++i)
	{
		tablica[i].sin0 = sinus(xres, yres, tablica[i].xposition, tablica[i].yposition);
		tablica[i].cos0 = cosinus(xres, yres, tablica[i].xposition, tablica[i].yposition);
	}

	for (i = 0; i < n; i++)
	{
		double d = (tablica[i].xposition - xres) * (tablica[i].xposition - xres) + (tablica[i].yposition - yres) * (tablica[i].yposition - yres);
		tablica[i].distance = sqrt(d);
		if (tablica[i].distance == 0) {
			printf("ERROR");
		}
		//cout << tablica[i].distance << endl;
	}

	double resIntensX = 0, resIntensY = 0;

	for (i = 0; i < n; i++)
	{
		resIntensX += (tablica[i].charge / (tablica[i].distance) * (tablica[i].distance)) * tablica[i].cos0;
		resIntensY += (tablica[i].charge / (tablica[i].distance) * (tablica[i].distance)) * tablica[i].sin0;
	}

	double resIntens = sqrt((resIntensY * resIntensY) + (resIntensX * resIntensX)) * vacuumElectr;

	cout << "Your resultantant intensivity in the point (" << xres << " ; " << yres << ") equals: " << endl;
	cout << resIntens << " Ampers" << endl;

}



int main()
{
	cout << "\nYour chosen field: gravitation\n\nWhat function are you looking for?\n";
	cout << "The resultant electrical force caused by n objects (1) \n";
	cout << "The resultant ponetnial caused by n objects (2)\n";
	cout << "The resultant intensity caused by n objects (3)\n\n";
	cout << "Function: ";
	int choice = 1;
	cout << "\n";

	switch (choice)
	{
	case 1:
		Force();
		break;
	case 2:
		Potential();
		break;
	case 3:
		Intensity();
		break;
	}
	return 0;
}