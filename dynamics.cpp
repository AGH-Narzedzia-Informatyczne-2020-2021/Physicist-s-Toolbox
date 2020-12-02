#include <iostream>
#include <string>
#include <tgmath.h>
#include "dynamics.h"
#include "constants.h"

using namespace std;

void slippery_slope_without_friction()
{
    cout << "\nYour choice: Slippery slope without friction! Choose what you want to calculate(1-7):\n\n"
         << "1.Body acceleration(slippery slope).\n"
         << "2.The time it takes for body to slide down from a given height.\n"
         << "3.Sine of the angle of the slope.\n"
         << "4.The force parallel to the slippery slope.\n";
    int option = 0;
    cout << "\nOption nr: ";
    cin >> option;
    cout << endl;

    if (option == 1)
    {
        double angle;
        cout << "Enter angle of the slope (degrees): ";
        cin >> angle;
        cout << "\nBody acceleration: " << EarthGrav * sin(angle*pi/180) << " m/s^2" << endl;
    }
    else if (option == 2)
    {
        double angle, height, time, distance, acceleration;
        cout << "Enter angle of the slope (degrees): ";
        cin >> angle;
        cout <<"\nEnter height of the body (metres): ";
        cin >> height;
        distance = height/sin(angle*pi/180);
        acceleration = EarthGrav * sin(angle*pi/180);
        time = sqrt(2*distance/acceleration);
        cout << "\nTime: " << time << " s" << endl;
    }
    else if (option == 3)
    {
        double height, time, sine;
        cout << "Enter the time of sliding the body: ";
        cin >> time;
        cout << "\nEnter the height from which body slides: ";
        cin >> height;
        sine = sqrt(2*height/EarthGrav/time/time);
        cout << "\nSine: " << sine << endl;
    }
    else if (option == 4)
    {
        double F, weight, angle;
        cout << "Enter the weight of the body: ";
        cin >> weight;
        cout << "\nEnter the angle of the slippery slope: ";
        cin >> angle;
        F = weight * EarthGrav * sin(angle*pi/180);
        cout << "\nThis Force is equal to: " << F << " N" << endl;
    }
    else
    {
        cout << "The number you chose does not correspond to any available function. Please try again.\n\n";
        slippery_slope_without_friction();
    }
}

void slippery_slope_with_friction()
{
    cout << "\nYour choice: Slippery slope with friction! Choose what you want to calculate(1-7):\n\n"
         << "1.Body acceleration(slippery slope).\n"
         << "2.The time it takes for body to slide down from a given height.\n"
         << "3.Sine of the angle of the slope.\n"
         << "4.The force parallel to the slippery slope.\n"
         << "5.The friction force.\n";
    int option = 0;
    cout << "\nOption nr: ";
    cin >> option;
    cout << endl;
    cout << "\nEnter the friction(Otherwise, enter 0): ";
    double friction;
    cin >> friction;

    if (option == 1)
    {

    }
}
int main()
{
    slippery_slope_without_friction();
    return 0;
}