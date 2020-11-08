#include <iostream>
#include <cmath>
using namespace std;
struct Charge {
    double charge;
    double xposition;
    double yposition;
    double distance;
};

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

	resPotential *= 0.079577;

	cout << "Your resultantant potencial in the point (" << xres << " ; " << yres << ") equals: " << endl;
	cout << resPotential << " Volts" << endl;

}

int main()
{
	Potential();
	return 0;
}