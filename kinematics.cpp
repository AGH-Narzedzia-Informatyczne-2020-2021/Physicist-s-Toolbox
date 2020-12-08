#include <iostream>
#include <cmath>
#include "constants.h"
#include "declarations.h"

void horizontal_projection()
{
    std::cout << "Your function of choice: horizontal projection!\n"
        << "---------------------------------------------------------------------------\n\n"
        << "What do you want to calculate (1-7):\n\n"
        << "Vertical speed in the moment (1)\n"
        << "Horizontal speed in the moment (2)\n"
        << "Total speed in the moment (3)\n"
        << "Coordinates of the body (4)\n"
        << "Fall time (5)\n"
        << "Throw range (6)\n"
        << "Final speed of the body (7)\n";
    std::cout << "\nOption nr: ";
    
    int option{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    if (option == 1) //Vertical speed in the moment
    {
        std::cout << "Enter height: ";
        auto h_0{ inputValidator() };
        std::cout << "Enter the time from the throw: ";
        auto t{ inputValidator() };
        
        if (sqrt(2 * h_0 / EarthGrav) < t)
        {
            std::cout << "\nThe body will already be on the ground at the given time";
        }
        else
        {
            auto v_y{ EarthGrav * t };
            std::cout << "\nThe vertical speed is equal to: " << v_y << " m/s\n";
        }
    }
    else if (option == 2) //2.Horizontal speed in the moment
    {
        std::cout << "At this level we assume no wind resistance,"
            << "so the horizontal speed is constant at all times equal to the initial horizontal speed\n";
    }
    else if (option == 3) //Total speed in the moment
    {
        std::cout << "Enter the height: ";
        auto h_0{ inputValidator() };
        std::cout << "Enter the time from the throwing moment: ";
        auto t{ inputValidator() };
        std::cout << "Enter the initial horizontal speed: ";
        auto v_x{ inputValidator() };
        
        if (sqrt(2 * h_0 / EarthGrav) < t)
        {
            std::cout << "\nThe body will already be on the ground at the given time";
        }
        else
        {
            auto v_y{ EarthGrav * t };
            auto v{ sqrt((v_x * v_x) + (v_y * v_y)) };
            std::cout << "\nTotal speed is equal to: " << v << " m/s\n";
        }
    }
    else if (option == 4) //Coordinates of the body
    {
        std::cout << "Enter the height: ";
        auto h_0{ inputValidator() };
        std::cout << "Enter the time from the throw: ";
        auto t{ inputValidator()};
        std::cout << "Enter the initial horizontal speed: ";
        auto v_x{ inputValidator() };

        if (sqrt(2 * h_0 / EarthGrav) < t)
        {
            std::cout << "\nThe body will already be on the ground at the given time";
        }
        else
        {
            auto h{ (h_0 - ((EarthGrav * t * t) / 2)) };
            auto x{ v_x * t };
            std::cout << "\nThe body will be at height: " << h << " m, and horizontally spaced by: "
                << x << " m from the point of throw\n";
        }

    }
    else if (option == 5) //Fall time
    {
        std::cout << "Enter the height: ";
        auto h{ inputValidator() };
       
        auto t{ sqrt(2 * h / EarthGrav) };
        std::cout << "\nThe time of the fall is equal to: " << t << " s\n";
    }
    else if (option == 6) //flight distance
    {
        std::cout << "Enter the height: ";
        auto h_0{ inputValidator() };
        std::cout << "Enter the initial horizontal speed: ";
        auto v_0{ inputValidator() };

        auto distance{ v_0 * sqrt((2 * h_0) / EarthGrav) };
        std::cout << "\nThe flight distance is equal to: " << distance << " m\n";
    }
    else if (option == 7) //Final speed of the body
    {
        std::cout << "Enter the height: ";
        auto h_0{ inputValidator() };
        std::cout << "Enter the initial horizontal speed: ";
        auto v_x{ inputValidator() };

        auto v{ sqrt((v_x * v_x) + (2 * EarthGrav * h_0)) };
        std::cout << "Final speed of the body is equal to: " << v << " m/s\n";
    }
    else
    {
        std::cout << "The number you've chosen does not correspond to any available function. Please try again.\n"
            << "\n---------------------------------------------------------------------------\n";
        horizontal_projection();
    }
}

void free_fall()
{
    std::cout << "Your function of choice: free fall!\n"
        << "---------------------------------------------------------------------------\n\n"
        << "What do you want to calculate (1-4) :\n\n"
        << "The time it takes for the body to reach its maximum height when thrown upwards (1)\n"
        << "The maximum height that the body can reach when thrown upwards (2)\n"
        << "Time of body free fall from height (3)\n"
        << "The speed at which a freely falling body will hit the ground (4)\n";
    std::cout << "\nOption nr: ";

    int option{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    if (option == 1) //Time-maximum height
    {
        std::cout << "Enter the initial speed of the up throw: ";
        auto v_0{ inputValidator() };
        
        auto t{ v_0 / EarthGrav };
        std::cout << "\nThe time it takes the object to reach maximum height is equal to: " << t << " s\n";
    }
    else if (option == 2) //Maximum height
    {
        std::cout << "Enter the initial speed of the up throw: ";
        auto v_0{ inputValidator() };
        
        auto h{ (v_0 * v_0) / (2 * EarthGrav) };
        std::cout << "\nThe maxiumum height the object will reach is equal to: " << h << " m\n";
    }
    else if (option == 3) //Time of free fall
    {
        std::cout << "Enter the height: ";
        auto h{ inputValidator() };
        
        auto t{ sqrt(2 * h / EarthGrav) };
        std::cout << "\nThe time of the fall is equal to: " << t << " s\n";
    }
    else if (option == 4) //The speed at which a freely falling body will hit the ground
    {
        std::cout << "Enter the height from which the body was dropped: ";
        auto h_0{ inputValidator() };
        
        auto v{ sqrt(2 * EarthGrav * h_0) };
        std::cout << "\nThe final velocity is equal to: " << v << " m/s\n";
    }
    else
    {
        std::cout << "The number you've chosen does not correspond to any available function. Please try again.\n"
            << "\n---------------------------------------------------------------------------\n";
        free_fall();
    }
}

void circular_motion()
{
    std::cout << "Your function of choice: circular motion!\n"
        << "---------------------------------------------------------------------------\n\n"
        << "What do you want to calculate (1-6):\n\n"
        << "Period and frequency in circular motion (1)\n"
        << "Period (knowing the frequency) (2)\n"
        << "Frequency (knowing the period) (3)\n"
        << "Linear speed in a circular motion (4)\n"
        << "Angular speed regarding linear speed (5)\n"
        << "Centrifugal acceleration (6)\n";
    std::cout << "\nOption nr: ";

    int option{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    if (option == 1)//Period and frequency
    {
        std::cout << "Enter the number of revolutions per minute: ";
        auto n{ inputValidator() };
        auto t{ 60 };
        std::cout << "\nFrequency is equal to: " << n / t << " Hz\n";
        std::cout << "Period is equal to: " << t / n << " s\n";
    }
    else if (option == 2)//Period
    {
        std::cout << "Enter the frequency: ";
        auto f{ inputValidator() };
        std::cout << "Period is equal to: " << 1 / f << " s\n";
    }
    else if (option == 3)//Frequency
    {
        std::cout << "Enter the period: ";
        auto T{ inputValidator() };
        std::cout << "Frequencyis equal to: " << 1 / T << " Hz\n";
    }
    else if (option == 4)//Linear speed
    {
        std::cout << "Enter the radius of a circle: ";
        auto r{ inputValidator() };
        double T{};
        std::cout << "\nChoose if you'll be entering frequency (f) or period (T)\n"
            << "Choice: ";

        char sign;
        while (true)
        {
            std::cin >> sign;
            if (sign == 'f' || sign == 'T')
            {
                std::cin.ignore(32767, '\n');
                std::cout << "\nEnter the value: ";
                break;
            }
            else
            {
                std::cout << "\nWrong letter. Please try again: ";
            }
        }

        if (sign == 'f')
        {
            auto f{ inputValidator() };
            T = 1 / f;
        }
        else if (sign == 'T')
        {
            T = inputValidator();
        }

        std::cout << "\nThe linear speed is equal to: " << (2 * pi * r) / T << " m/s\n";
    }
    else if (option == 5)//Angular speed
    {
        std::cout << "Enter the linear speed: ";
        auto v{ inputValidator() };
        std::cout << "Enter the radius of a circle: ";
        auto r{ inputValidator() };
        
        std::cout << "\nAngular speed is equal to: " << v / r << " rad/s\n";
    }
    else if (option == 6)//Centrifugal acceleration
    {
        std::cout << "Enter the radius of a circle: ";
        auto r{ inputValidator() };
        std::cout << "Do you know the angular (1) or linear (2) speed?";
        std::cout << "Option: ";

        while (true)
        {
            int option2{ static_cast<int>(inputValidator()) };

            if (option2 == 1)
            {
                std::cout << "\nEnter the angular speed: ";
                auto vk{ inputValidator() };
                std::cout << "\nThe centrifugal speed is equal to: " << vk * vk * r << " rad/s^2\n";
                break;
            }
            else if (option2 == 2)
            {
                std::cout << "\nEnter the linear speed: ";
                auto v{ inputValidator() };
                std::cout << "\nThe centrifugal speed is equal to: " << v * v / r << " m/s^2\n";
                break;
            }
            else
                std::cout << "\nWrong number. Please try again: ";
        }
    }
    else
    {
        std::cout << "The number you've chosen does not correspond to any available function. Please try again.\n"
            << "\n---------------------------------------------------------------------------\n";
        circular_motion();
    }
}

void kinChoice()
{
    int choice{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    switch (choice)
    {
    case 1:
        std::cout << "---------------------------------------------------------------------------\n";
        horizontal_projection();
        break;
    case 2:
        std::cout << "---------------------------------------------------------------------------\n";
        free_fall();
        break;
    case 3:
        std::cout << "---------------------------------------------------------------------------\n";
        circular_motion();
        break;
    default:
        std::cout << "The number you've chosen does not correspond to any available function. Please try again: ";
        kinChoice();
    }
}

void kinematics()
{
    std::cout << "Your chosen field: kinematics\n"
        << "---------------------------------------------------------------------------\n" 
        << "What function are you looking for?\n\n"
        << " - horizontal projection (1)\n"
        << " - free fall (2)\n"
        << " - circular motion (3)\n\n"
        << "Function nr: ";
    kinChoice();
    
    std::cout << "\n---------------------------------------------------------------------------\n";
    std::cout << "Do you wish to calculate anything else in this field? (Y/N): ";
    char endOrNot;
    std::cin >> endOrNot;
    std::cin.ignore(32767, '\n');

    if (endOrNot == 'y' || endOrNot == 'Y')
    {
        std::cout << "\n---------------------------------------------------------------------------\n";
        kinematics();
    }
}
