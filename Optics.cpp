#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "constants.h"
#include "declarations.h"

void snellLaw()
{
    std::cout << "Your function of choice: Snell's law!\n"
        << "---------------------------------------------------------------------------\n\n"
        << "What do you want to calculate (1-2):\n\n"
        << "Refractive index (1)\n"
        << "Angle (2)\n";
    std::cout << "\nOption nr: ";

    int option{ static_cast<int>(inputValidator()) };
    std::cout << '\n';
    
    if (option == 1)
    {
        std::cout << "Enter known value of the angle: ";
        auto ang1{ inputValidator() };
        std::cout << "Enter known value of the refrective index: ";
        auto n1{ inputValidator() };
        std::cout << "Enter the second known angle: ";
        auto ang2{ inputValidator() };

        double n2 = n1 * sin((pi / 180) * ang1) / sin((pi / 180) * ang2);
        std::cout << "\nReflective index is equal to: " << n2 << '\n';
    }
    else if (option == 2)
    {
        std::cout << "Enter known value of the angle: ";
        auto ang1{ inputValidator() };
        std::cout << "Enter known value of the refrective index: ";
        auto n1{ inputValidator() };
        std::cout << "Enter the second known refractive index: ";
        auto n2{ inputValidator() };

        double ang2 = asin(n1 * sin((pi / 180) * ang1) / n2);
        ang2 *= (pi / 180);
        std::cout << "\nAngle is equal to: " << n2 << " degrees\n";
    }
    else
    {
        std::cout << "The number you've chosen does not correspond to any available function. Please try again\n"
            << "\n---------------------------------------------------------------------------\n";
        snellLaw();
    }
}

void imageFormation()
{
    std::cout << "Your function of choice: imaging properties!\n"
        << "---------------------------------------------------------------------------\n\n"
        << "What do you want to calculate (1-3):\n\n"
        << "The focal lenght of the lens (1)\n"
        << "The distance between object and the lens (2)\n"
        << "The distance between image and the lens (3)\n";
        std::cout << "\nOption nr: ";

    int option{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    if (option == 1)
    {
        std::cout << "Enter the distance from the object to the lens: ";
        auto x{ inputValidator() };
        std::cout << "Enter the distance from the lens to the image: ";
        auto y{ inputValidator() };

        double f = (x * y) / (x + y);
        std::cout << "\nThe focal lenght of the lens is equal to: " << f << " m\n";
    }
    else if (option == 2)
    {
        std::cout << "Enter the focal lenght of the lens: ";
        auto f{ inputValidator() };
        std::cout << "Enter the distance from the lens to the image: ";
        auto y{ inputValidator() };
        
        double x = (f * y) / (y - f);
        std::cout << "\nThe distance from the object to the lens is equal to: " << x << " m\n";
    }
    else if (option == 3)
    {
        std::cout << "Enter the focal lenght of the lens: ";
        auto f{ inputValidator() };
        std::cout << "Enter the distance from the object to the lens: ";
        auto x{ inputValidator() };
        
        double y = (f * x) / (x - f);
        std::cout << "The distance from the lens to the image is equal to: " << y << " m\n";
    }
    else
    {
        std::cout << "The number you've chosen does not correspond to any available function. Please try again\n"
            << "\n---------------------------------------------------------------------------\n";
        imageFormation();
    }
}

void magnification()
{
    std::cout << "Your function of choice: magnification!\n"
        << "---------------------------------------------------------------------------\n\n"
        << "Which set of data do you have (1-2):\n\n"
        << "Height of the object and the image (1)\n"
        << "Distance of the object and the image from the lens (2)\n";
    std::cout << "\nOption nr: ";

    int option{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    if (option == 1)
    {
        std::cout << "Enter the height of the object: ";
        auto x{ inputValidator() };
        std::cout << "Enter the height of the image: ";
        auto y{ inputValidator() };
        
        double p = abs(y / x);
        std::cout << "\nMagnification is equal to: " << p << '\n';
    }
    else if (option == 2)
    {
        std::cout << "Enter the distance from the object to the lens: ";
        auto x{ inputValidator() };
        std::cout << "Enter the distance from the lens to the image: ";
        auto y{ inputValidator() };
        
        double p = abs(y / x);
        std::cout << "\nMagnification is equal to: " << p << '\n';
    }
    else
    {
        std::cout << "The number you've chosen does not correspond to any available function. Please try again\n"
            << "\n---------------------------------------------------------------------------\n";
        magnification();
    }
}

void opticsChoice()
{
    int choice{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    switch (choice)
    {
    case 1:
        std::cout << "---------------------------------------------------------------------------\n";
        snellLaw();
        break;
    case 2:
        std::cout << "---------------------------------------------------------------------------\n";
        imageFormation();
        break;
    case 3:
        std::cout << "---------------------------------------------------------------------------\n";
        magnification();
        break;
    default:
        std::cout << "The number you've chosen does not correspond to any available function. Please try again: ";
        opticsChoice();
    }
}

void optics()
{
    std::cout << "Your chosen field: optics\n"
        << "---------------------------------------------------------------------------\n"
        << "What function are you looking for?\n\n"
        << " - Snell's Law (1)\n"
        << " - image formation (2)\n"
        << " - magnification of an object (3)\n\n"
        << "Function: ";
    opticsChoice();

    std::cout << "\n---------------------------------------------------------------------------\n";
    std::cout << "Do you wish to calculate anything else in this field? (Y/N): ";
    char endOrNot;
    std::cin >> endOrNot;
    std::cin.ignore(32767, '\n');

    if (endOrNot == 'y' || endOrNot == 'Y')
    {
        std::cout << "\n---------------------------------------------------------------------------\n";
        optics();
    }
}
