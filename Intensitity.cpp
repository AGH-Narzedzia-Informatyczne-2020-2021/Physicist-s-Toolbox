#include <iostream>
#include<cmath>
using namespace std;
enum Quarter { pierwsza = 1, druga = 2, trzecia = 3, czwarta = 4 };
struct Charge {
	double charge;
	double xposition;
	double yposition;
	double distance;
	unsigned int pos;
};

unsigned int findQuarter(double x0, double y0, double xpos, double ypos)
//funcion which returns the number of quarter where the charge is located in regard to the examined point
{
	unsigned int pos;
	if (x0 > xpos)
	{
		if (y0 > ypos)
		{
			pos = 1;
		}
		else
		{
			pos = 4;
		}
	}
	else
	{
		if (y0 > ypos)
		{
			pos = 2;
		}
		else
		{
			pos = 3;
		}
	}
	return pos;
}

double sinus(double x0, double y0, double xpos, double ypos, unsigned int quarter)
{
	double sinus = 0;
	switch (pos)
	{

	}
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
		tablica[i].pos = findQuarter(xres, yres, tablica[i].xposition, tablica[i].yposition);
	}

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


	cout << "Your resultantant potencial in the point (" << xres << " ; " << yres << ") equals: " << endl;
	cout << resPotential << " Volts" << endl;

}

int main()
{
	Intensity();
	return 0;
}