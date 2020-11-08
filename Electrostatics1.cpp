#include <iostream>
using namespace std;
struct Charge {
	double charge;
	double xposition;
	double yposition;
};

void Intensity()
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
		cout << "Input the value of the charge of your " << i + 1 << " object expressed in Culombs : ";
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

	cout <<
}

int main()
{
	Intensity();
	return 0;
}