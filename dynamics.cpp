#include <iostream>
#include <string>
#include <tgmath.h>
#include "dynamics.h"
#include "constants.h"

using namespace std;

void slippery_slope_without_friction()
{
    cout << "Your choice: Slippery slope without friction! Choose what you want to calculate(1-7):\n\n"
         << "1.Body acceleration(slippery slope).\n"
         << "2.The time it takes for body to slide down from a given height.\n"
         << "3.The angle of the slope.\n"
         << "4.Body pressure.\n";
    //     << "5.Fall time.\n"
    //     << "6.Throw range.\n"
    //     << "7.Final speed of the body.\n";
    int option = 0;
    cout << "\nOption nr: ";
    cin >> option;
    cout << endl;

    if (option == 1)
    {
        double angle;
        cout << "Enter angle of the slope (degrees): ";
        cin >> angle;
        cout << "\nBody acceleration: " << EarthGrav * sin(angle*pi/180) << endl;
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
        cout << "Time: " << time << endl;
    }
}

int main()
{
    slippery_slope_without_friction();
    return 0;
}