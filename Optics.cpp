#include <iostream>
#include <cmath>
#include <math.h>
#include <stdlib.h>

using namespace std;

void Snellaw()
{
    cout << "Which variable do You want to calculate?" << endl;
    cout << "(1) refractive index" << endl << "(2) angle" << endl;
    unsigned int a = 1;
    cin >> a;
    double n1, n2, ang1, ang2;
    cout << "Input known value of an angle (expressed in degrees)" << endl;
    cin >> ang1;
    cout << "Input known value of a refrective index" << endl;
    cin >> n1;
    switch (a)
    {
    case 1:
        cout << "Input the second known angle" << endl;
        cin >> ang2;
        n2 = n1 * sin((M_PI / 180) * ang1) / sin((M_PI / 180) * ang2);
        cout << "Searched reflective index equals: " << n2 << endl;
        break;
    case 2:
        cout << "Input the second known refractive index" << endl;
        cin >> n2;
        ang2 = asin(n1 * sin((M_PI / 180) * ang1) / n2);
        ang2 *= (M_PI / 180);
        cout << "Searched angle equals: " << n2 << endl;
        break;
    }
}

void LensMaker()
{
    cout << "Which variable do You want to calculate?" << endl;
    cout << "(1) f" << endl << "(2) x" << endl << "(3) y" << endl;
    unsigned int a = 1;
    cin >> a;
    float x, y, f;
    switch (a)
    {
    case 1:
        cout << "Input the value of x expressed in meters: " << endl;
        cin >> x;
        cout << "Input the value of y expressed in meters: " << endl;
        cin >> y;
        f = (x * y) / (x + y);
        cout << "Searched value of f equals: " << f << " meters" << endl;
        break;

    case 2:
        cout << "Input the value of f expressed in meters: " << endl;
        cin >> f;
        cout << "Input the value of y expressed in meters: " << endl;
        cin >> y;
        x = (f * y) / (y - f);
        cout << "Searched value of x equals: " << x << " meters" << endl;
        break;

    case 3:
        cout << "Input the value of f expressed in meters: " << endl;
        cin >> f;
        cout << "Input the value of x expressed in meters: " << endl;
        cin >> y;
        x = (f * x) / (x - f);
        cout << "Searched value of y equals: " << y << " meters" << endl;
        break;
    }
}

void Magnification()
{
    float x, y, p = 0;
    unsigned int choice = 1;
    cout << "Which set of data do you have: " << endl << "Hight of the object and the picture (1)" << endl;
    cout << "Distance of the object and the picture from the lens (2)" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Input the hight of an object: ";
        cin >> x;
        cout << "Input the hight of a picture: ";
        cin >> y;
        break;
    case 2:
        cout << "Input the distance of an object from the lens (x): ";
        cin >> x;
        cout << "Input the distance of an picture from the lens (y): ";
        cin >> y;
        break;
    }
    p = abs(y / x);
    cout << endl << "Magnification equals: " << p << endl;

}


int main()
{
    cout << "\nYour chosen field: optics\n\nWhich function are you looking for?\n";
    cout << "The Snell's Law  (1) \n";
    cout << "The lens Maker's equation (2)\n";
    cout << "Magnification of an object (3)\n\n";
    cout << "Function: ";
    int choice = 1;
    cout << "\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        Snellaw();
        break;
    case 2:
        LensMaker();
        break;
    case 3:
        Magnification();
        break;
    }
    return 0;
}
