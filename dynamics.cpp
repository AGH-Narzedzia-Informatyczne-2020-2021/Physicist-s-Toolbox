#include <iostream>
#include <tgmath.h>
#include "dynamics.h"
#include "constants.h"

using namespace std;

void slippery_slope_without_friction()
{
    cout << "\nYour choice: Slippery slope without friction! Choose what you want to calculate(1-5):\n\n"
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
    cout << "\nYour choice: Slippery slope with friction! Choose what you want to calculate(1-5):\n\n"
         << "1.Body acceleration(slippery slope).\n"
         << "2.The time it takes for body to slide down from a given height.\n"
         << "3.The final speed.\n"
         << "4.The net force(down, parallel to the slippery slope).\n"
         << "5.The friction force.\n";
    int option = 0;
    cout << "\nOption nr: ";
    cin >> option;
    cout << endl;
    cout << "\nEnter the friction ratio: ";
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

void Newtons_laws_of_motion() {
    cout << "\nYour choice: Newtons laws of motion! Choose what you want to calculate(1-3):\n\n"
         << "1.The force.\n"
         << "2.The weight.\n"
         << "3.The acceleration.\n";
    int option = 0;
    cout << "\nOption nr: ";
    cin >> option;
    cout << endl;

    if (option == 1)
    {
        double weight, acceleration;
        cout << "Enter the weight of the body: ";
        cin >> weight;
        cout << "Enter the acceleration of the body: ";
        cin >> acceleration;
        cout << "The force is equal to: " << weight * acceleration << "N" << endl;
    }
    else if (option == 2)
    {
        double force, acceleration;
        cout << "Enter the force: ";
        cin >> force;
        cout << "Enter the acceleration of the body: ";
        cin >> acceleration;
        cout << "The weight is equal to: " << force/acceleration << "kg" << endl;
    }
    else if (option == 3)
    {
        double weight, force;
        cout << "Enter the force: ";
        cin >> force;
        cout << "Enter the weight of the body: ";
        cin >> weight;
        cout << "The acceleration is equal to: " << force / weight << "m/s^2" << endl;
    }
    else
    {
        cout << "The number you chose does not correspond to any available function. Please try again.\n\n";
        Newtons_laws_of_motion();
    }
}

void Linear_momentum() {
    cout << "\nYour choice: Linear momentum! Choose what you want to calculate(1-3):\n\n"
         << "1.The linear momentum.\n"
         << "2.The speed.\n"
         << "3.The weight.\n";
    int option = 0;
    cout << "\nOption nr: ";
    cin >> option;
    cout << endl;

    if (option == 1)
    {
        double weight, speed;
        cout << "Enter the weight of the body: ";
        cin >> weight;
        cout << "Enter the speed of the body: ";
        cin >> speed;
        cout << "The linear momentum is equal to: " << weight * speed << "kg*m/s" << endl;
    }
    else if (option == 2)
    {
        double momentum, weight;
        cout << "Enter the weight of the body: ";
        cin >> weight;
        cout << "Enter the linear momentum of the body: ";
        cin >> momentum;
        cout << "The weight is equal to: " << momentum/weight << "m/s" << endl;
    }
    else if (option == 3)
    {
        double momentum, speed;
        cout << "Enter the linear momentum: ";
        cin >> momentum;
        cout << "Enter the speed of the body: ";
        cin >> speed;
        cout << "The acceleration is equal to: " << momentum / speed << "kg" << endl;
    }
    else
    {
        cout << "The number you chose does not correspond to any available function. Please try again.\n\n";
        Linear_momentum();
    }
}

void dynamics()
{
    cout << "\nYour chosen field: dynamics\nWhat function are you looking for?\n\n"
         << "1.Slippery slope without friction\n"
         << "2.Slippery slope with friction\n"
         << "3.Newton's law of motion\n"
         << "4.Linear momentum\n\n"
         << "If you want to count the friction force on flat ground, enter angle = 0\n\n"
         << "Function nr: ";
    int choice;
    cin >> choice;
    cout << endl;

    switch (choice)
    {
        case 1:
            cout << "---------------------------------------------------------------------------\n";
            slippery_slope_without_friction();
            break;
        case 2:
            cout << "---------------------------------------------------------------------------\n";
            slippery_slope_with_friction();
            break;
        case 3:
            cout << "---------------------------------------------------------------------------\n";
            Newtons_laws_of_motion();
            break;
        case 4:
            cout << "---------------------------------------------------------------------------\n";
            Linear_momentum();
            break;
        default:
            cout << "The number you chose does not correspond to any available function. Please try again.\n\n";
            dynamics();
    }
    cout << "\n---------------------------------------------------------------------------\n";
    cout << "Do you wish to calculate anything else? (Y/N): ";
    char endOrNot;
    cin >> endOrNot;
    if (endOrNot == 'y' || endOrNot == 'Y')
        dynamics();
    else if(endOrNot == 'n' || endOrNot == 'N')
        exit;
}
int main()
{
    dynamics();
    return 0;
}