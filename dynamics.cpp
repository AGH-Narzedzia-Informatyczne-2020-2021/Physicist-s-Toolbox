#include <iostream>
#include <cmath>
#include "constants.h"
#include "declarations.h"

void slippery_slope_without_friction()
{
    std::cout << "Your function of choice: slippery slope without friction!\n"
        << "---------------------------------------------------------------------------\n\n"
        << "What do you want to calculate (1-5):\n\n"
        << "Acceleration of the object on slippery slope (1)\n"
        << "The time it takes for body to slide down from a given height (2)\n"
        << "Sine of the angle of the slope (3)\n"
        << "The force parallel to the slippery slope (4)\n"
        << "The final speed (5)\n";
    std::cout << "\nOption nr: ";
    
    int option{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    if (option == 1) // body acceleration
    {
        std::cout << "Enter angle of the slope: ";
        auto angle{ inputValidator() };

        std::cout << "\nAcceleration of the object is equal to: " << EarthGrav * sin(angle * pi / 180) << " m/s^2\n";
    }
    else if (option == 2) // sliding time
    {
        std::cout << "Enter angle of the slope: ";
        auto angle{ inputValidator() };
        std::cout << "Enter height of the body: ";
        auto height{ inputValidator() };
        
        double distance = height / sin(angle * pi / 180);
        double acceleration = EarthGrav * sin(angle * pi / 180);
        double time = sqrt(2 * distance / acceleration);
        std::cout << "\nSliding time is equal to: " << time << " s\n";
    }
    else if (option == 3) // sin of the angle
    {
        std::cout << "Enter the time of sliding of the body: ";
        auto time{ inputValidator() };
        std::cout << "Enter the height from which body slides: ";
        auto height{ inputValidator() };
        double sine = sqrt(2 * height / EarthGrav / time / time);
        std::cout << "\nSine of the angle is equal to: " << sine << '\n';
    }
    else if (option == 4) // parallel force
    {
        std::cout << "Enter the weight of the body: ";
        auto weight{ inputValidator() };
        std::cout << "Enter the angle of the slippery slope: ";
        auto angle{ inputValidator() };
        
        double force = weight * EarthGrav * sin(angle * pi / 180);
        std::cout << "\nParallel force is equal to: " << force << " N\n";
    }
    else if (option == 5) // final speed
    {
        std::cout << "Enter the height: ";
        auto height{ inputValidator() };
        std::cout << "Enter the angle: ";
        auto angle{ inputValidator() };

        double distance = height / sin(angle * pi / 180);
        double acceleration = EarthGrav * sin(angle * pi / 180);
        double time = sqrt(2 * distance / acceleration);
        std::cout << "\nThe final speed is equal to: " << acceleration * time << " m/s\n";
    }
    else
    {
        std::cout << "The number you've chosen does not correspond to any available function. Please try again\n"
            << "\n---------------------------------------------------------------------------\n";
        slippery_slope_without_friction();
    }
}

void slippery_slope_with_friction()
{
    std::cout << "Your function of choice: slippery slope with friction!\n"
        << "---------------------------------------------------------------------------\n\n"
        << "What do you want to calculate (1-5):\n\n"
        << "Acceleration of the object on slippery slope (1)\n"
        << "The time it takes for body to slide down from a given height (2)\n"
        << "The final speed (3)\n"
        << "The net force (down, parallel to the slippery slope) (4)\n"
        << "The friction force (5)\n";
    std::cout << "\nOption nr: ";
    
    int option{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    if (option == 1) //acceleration of the object
    {
        std::cout << "Enter the friction ratio: ";
        double friction{ inputValidator() };
        std::cout << "Enter the angle of the slippery slope: ";
        auto angle{ inputValidator() };
        
        double acceleration = EarthGrav * (sin(angle * pi / 180) - (friction * cos(angle * pi / 180)));
        std:: cout << "\nAcceleration is equal to: " << acceleration << " m/s^2\n";
    }
    else if (option == 2) //sliding time
    {
        std::cout << "Enter the friction ratio: ";
        double friction{ inputValidator() };
        std::cout << "Enter the height of the slippery slope: ";
        auto height{ inputValidator() };
        std:: cout << "Enter the angle of the slippery slope: ";
        auto angle{ inputValidator() };
        
        double time = sqrt((2 * height) / (EarthGrav * sin(angle * pi / 180) * (sin(angle * pi / 180) - (friction * cos(angle * pi / 180)))));
        std::cout << "\nSliding ime is equal to: " << time << " s\n";
    }
    else if (option == 3) //final speed
    {
        std::cout << "Enter the friction ratio: ";
        double friction{ inputValidator() };
        std::cout << "Enter the height of the slippery slope: ";
        auto height{ inputValidator() };
        std::cout << "Enter the angle of the slippery slope: ";
        auto angle{ inputValidator() };
        
        double speed = sqrt((2 * height * EarthGrav) * (sin(angle * pi / 180) - (friction * cos(angle * pi / 180))) / sin(angle * pi / 180));
        std::cout << "\nThe final speed is equal to: " << speed << " m/s\n";
    }
    else if (option == 4) //net force
    {
        std::cout << "Enter the friction ratio: ";
        double friction{ inputValidator() };
        std::cout << "Enter the weight of the body: ";
        auto weight{ inputValidator() };
        std::cout << "Enter the angle of the slippery slope: ";
        auto angle{ inputValidator() };
        
        double F = weight * EarthGrav * sin(angle * pi / 180);
        double FN = weight * EarthGrav * cos(angle * pi / 180);
        double T = friction * FN;
        std::cout << "\nNet force is equal to: " << F - T << " N\n";
    }
    else if (option == 5) //friction force
    {
        std::cout << "Enter the friction ratio: ";
        double friction{ inputValidator() };
        std::cout << "Enter the weight of the body: ";
        auto weight{ inputValidator() };
        std::cout << "Enter the angle of the slippery slope: ";
        auto angle{ inputValidator() };

        double FN = weight * EarthGrav * cos(angle * pi / 180);
        double T = friction * FN;
        std::cout << "\nThe friction force is equal to: " << T << " N\n";
    }
    else
    {
        std::cout << "The number you've chosen does not correspond to any available function. Please try again\n"
            << "\n---------------------------------------------------------------------------\n";
        slippery_slope_with_friction();
    }

}

void Newtons_laws_of_motion() 
{
    std::cout << "Your function of choice: Newtons laws of motion!\n"
        << "---------------------------------------------------------------------------\n\n"
        << "What do you want to calculate (1-3):\n\n"
        << "The force (1)\n"
        << "The weight (2)\n"
        << "The acceleration (3)\n";
    std::cout << "\nOption nr: ";
    
    int option{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    if (option == 1) //force
    {
        std::cout << "Enter the weight of the body: ";
        auto weight{ inputValidator() };
        std::cout << "Enter the acceleration of the body: ";
        auto acceleration{ inputValidator() };
        
        std::cout << "\nThe force is equal to: " << weight * acceleration << " N\n";
    }
    else if (option == 2) //weight
    {
        std::cout << "Enter the force: ";
        auto force{ inputValidator() };
        std::cout << "Enter the acceleration of the body: ";
        auto acceleration{ inputValidator() };

        std::cout << "\nThe weight is equal to: " << force / acceleration << " kg\n";
    }
    else if (option == 3) //acceleration
    {
        std::cout << "Enter the force: ";
        auto force{ inputValidator() };
        std::cout << "Enter the weight of the body: ";
        auto weight{ inputValidator() };
        std::cout << "\nThe acceleration is equal to: " << force / weight << " m/s^2\n";
    }
    else
    {
        std::cout << "The number you've chosen does not correspond to any available function. Please try again\n"
            << "\n---------------------------------------------------------------------------\n";
        Newtons_laws_of_motion();
    }
}

void linear_momentum()
{
    std::cout << "Your function of choice: linear momentum!\n"
        << "---------------------------------------------------------------------------\n\n"
        << "What do you want to calculate (1-3):\n\n"
        << "The linear momentum (1)\n"
        << "The speed (2)\n"
        << "The weight (3)\n";
    std::cout << "\nOption nr: ";

    int option{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    if (option == 1) //linear momentum
    {
        std::cout << "Enter the weight of the body: ";
        auto weight{ inputValidator() };
        std::cout << "Enter the speed of the body: ";
        auto speed{ inputValidator() };
        
        std::cout << "\nThe linear momentum is equal to: " << weight * speed << " kg*m/s\n";
    }
    else if (option == 2) //speed
    {
        std::cout << "Enter the weight of the body: ";
        auto weight{ inputValidator() };
        std::cout << "Enter the linear momentum of the body: ";
        auto momentum{ inputValidator() };

        std::cout << "\nThe weight is equal to: " << momentum / weight << " m/s\n";
    }
    else if (option == 3) //weight
    {
        std::cout << "Enter the linear momentum: ";
        auto momentum{ inputValidator() };
        std::cout << "Enter the speed of the body: ";
        auto speed{ inputValidator() };
        std::cout << "\nThe acceleration is equal to: " << momentum / speed << " kg\n";
    }
    else
    {
        std::cout << "The number you've chosen does not correspond to any available function. Please try again\n"
            << "\n---------------------------------------------------------------------------\n";
        linear_momentum();
    }
}

void dynChoice()
{
    int choice{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    switch (choice)
    {
    case 1:
        std::cout << "---------------------------------------------------------------------------\n";
        slippery_slope_without_friction();
        break;
    case 2:
        std::cout << "---------------------------------------------------------------------------\n";
        slippery_slope_with_friction();
        break;
    case 3:
        std::cout << "---------------------------------------------------------------------------\n";
        Newtons_laws_of_motion();
        break;
    case 4:
        std::cout << "---------------------------------------------------------------------------\n";
        linear_momentum();
        break;
    default:
        std::cout << "The number you've chosen does not correspond to any available function. Please try again: ";
        dynChoice();
    }
}

void dynamics()
{
    std::cout << "Your chosen field: dynamics\n"
        << "---------------------------------------------------------------------------\n"
        << "What function are you looking for?\n\n"
        << " - slippery slope without friction (1)\n"
        << " - slippery slope with friction (2)\n"
        << " - Newton's law of motion (3)\n"
        << " - linear momentum (4)\n\n"
        << "If you want to count the friction force on flat ground enter angle = 0\n\n"
        << "Function: ";
    dynChoice();
    
    std::cout << "\n---------------------------------------------------------------------------\n";
    std::cout << "\nDo you wish to calculate anything else in this field? (Y/N): ";
    char endOrNot;
    std::cin >> endOrNot;
    std::cin.ignore(32767, '\n');

    if (endOrNot == 'y' || endOrNot == 'Y')
    {
        std::cout << "\n---------------------------------------------------------------------------\n";
        dynamics();
    }
}