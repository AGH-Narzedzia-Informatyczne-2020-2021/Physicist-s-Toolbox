#include <iostream>
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
         << "4.The force parallel to the slippery slope.\n"
         << "5.The final speed";
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
    else if(option == 5)
    {
        double height, angle, distance, acceleration, time;
        cout << "Enter the height: ";
        cin >> height;
        cout << "Enter the angle: ";
        cin >> angle;
        distance = height/sin(angle*pi/180);
        acceleration = EarthGrav * sin(angle*pi/180);
        time = sqrt(2*distance/acceleration);
        cout << "The final speed is equal to: " << acceleration * time << " m/s" << endl;
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
         << "3.The final speed.\n"
         << "4.The net force(down, parallel to the slippery slope).\n"
         << "5.The friction force.\n";
    int option = 0;
    cout << "\nOption nr: ";
    cin >> option;
    cout << endl;
    cout << "\nEnter the friction ratio(Otherwise, enter 0): ";
    double friction;
    cin >> friction;

    if (option == 1)
    {
        double angle, acceleration;
        cout << "\nEnter the angle of the slippery slope: ";
        cin >> angle;
        acceleration = EarthGrav*(sin(angle*pi/180) - (friction * cos(angle*pi/180)));
        cout << "\nAcceleration is equal to: " << acceleration << " m/s^2" << endl;
    }
    else if (option == 2)
    {
        double height, angle, time;
        cout << "\nEnter the height of the slippery slope: ";
        cin >> height;
        cout << "\nEnter the angle of the slippery slope: ";
        cin >> angle;
        time = sqrt((2 * height)/(EarthGrav * sin(angle*pi/180) * (sin(angle*pi/180) - (friction * cos(angle*pi/180)))));
        cout << "\nTime is equal to: " << time << " s" << endl;
    }
    else if (option == 3)
    {
        double height, angle, speed;
        cout << "\nEnter the height of the slippery slope: ";
        cin >> height;
        cout << "\nEnter the angle of the slippery slope: ";
        cin >> angle;
        speed = sqrt((2 * height * EarthGrav) * (sin(angle*pi/180) - (friction * cos(angle*pi/180))) / sin(angle*pi/180));
        cout << "\nThe final speed is equal to: " << speed << " m/s" << endl;
    }
    else if (option == 4)
    {
        double F, weight, angle, T, FN;
        cout << "\nEnter the weight of the body: ";
        cin >> weight;
        cout << "\nEnter the angle of the slippery slope: ";
        cin >> angle;
        F = weight * EarthGrav * sin(angle * pi / 180);
        FN = weight * EarthGrav * cos(angle*pi/180);
        T = friction * FN;
        cout << "\nThis Force is equal to: " << F - T << " N" << endl;
    }
    else if (option == 5)
    {
        double weight, FN, T, angle;
        cout << "\nEnter the weight of the body: ";
        cin >> weight;
        cout << "\nEnter the angle of the slippery slope: ";
        cin >> angle;
        FN = weight * EarthGrav * cos(angle*pi/180);
        T = friction * FN;
        cout << "\nThe friction force is equal to: " << T << " N" << endl;
    }
    else
    {
        cout << "The number you chose does not correspond to any available function. Please try again.\n\n";
        slippery_slope_with_friction();
    }

}
int main()
{
    slippery_slope_with_friction();
    return 0;
}