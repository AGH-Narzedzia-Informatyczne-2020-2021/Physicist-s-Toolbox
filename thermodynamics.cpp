#include <iostream>
#include <cmath>
#include "constants.h"
#include "declarations.h"

void firstLaw()
{
	std::cout << "Your function of choice: change of energy in the system!\n"
		<< "---------------------------------------------------------------------------\n\n";
	std::cout << "The first law of thermodynamics is also known as The Law of Conservation of Energy\n\n";
	std::cout << "Type how much heat was supplied to the system: ";
	auto q{ inputValidator() };
	std::cout << "Type how much work was done on/by the system: ";
	auto w{ inputValidator() };

	auto u{ q + w };
	if (u < 0)
	{
		std::cout << "\nInternal energy decrease in the system is equal to: " << u << " J\n";
	}
	else
	{
		std::cout << "\nInternal energy increase in the system is equal to: " << u << " J\n";
	}

}

void idealGasLaw()
{
	std::cout << "Your function of choice: Clausius-Clapeyron equation!\n"
        << "---------------------------------------------------------------------------\n\n";
    std::cout << "What do you want to calculate (1-3):\n\n"
        << "Pressure of the gas times volume (1)\n"
        << "Pressure of the gas (2)\n"
        << "Volume of the gas (3)\n";
    std::cout << "\nOption nr: ";
    
    int option{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

	if (option == 1) // p*V
    {
        std::cout << "Enter the amount of moles of the gas: ";
        auto n{ inputValidator() };
        std::cout << "Enter the temperature: ";
        double T{ inputValidator() };
        double result = n * gasConst * T;

        std::cout << "\nAccording to the Clausius-Clapeyron equation pressure of the gas multiplied by its volume is equal to: " << result << " J\n";
	}
	else if (option == 2) //pressure
    {
        std::cout << "Enter the amount of moles of the gas: ";
        auto n{ inputValidator() };
        std::cout << "Enter the temperature: ";
        double T{ inputValidator() };
        std::cout << "Enter the volume of the gas: ";
        double V{ inputValidator() };
        
        double p{ (n * gasConst * T) / V };
        std::cout << "\nPressure of the gas is equal to: " << p << " Pa\n";
	}
    else if (option == 3) //volume
    {
        std::cout << "Enter the amount of moles of the gas: ";
        auto n{ inputValidator() };
        std::cout << "Enter the temperature: ";
        double T{ inputValidator() };
        std::cout << "Enter the pressure of the gas: ";
        double p{ inputValidator() };
        double V{ (n * gasConst * T) / p };
        std::cout << "\nThe volume of the gas is equal to: " << V << " m^3\n";
    }
    else
    {
        std::cout << "The number you've chosen does not correspond to any available function. Please try again\n"
            << "\n---------------------------------------------------------------------------\n";
        idealGasLaw();
    }
}

void heat()
{
    std::cout << "Your function of choice: heat in many aspects!\n"
        << "---------------------------------------------------------------------------\n\n";
    std::cout << "What do you want to calculate (1-3):\n\n"
        << "Molar heat of the object (1)\n"
        << "Heat of the object during phase change (2)\n"
        << "Regular heat of the object (3)\n";
    std::cout << "\nOption nr: ";

    int option{ static_cast<int>(inputValidator()) };
    std::cout << '\n';

    if (option == 1) //molar heat
    {
        std::cout << "Do you want to count molar heat using (1-2):\n"
            << " - specific heat (1)\n"
            << " - equation without specific heat (2)\n"
            << "\nChoice: ";
       
        while (true)
        {
            int choice{ static_cast<int>(inputValidator()) };

            if (choice == 1)
            {
                std::cout << "\nEnter the value of specific heat: ";
                double cs{ inputValidator() };
                std::cout << "Enter the value of molar mass of the object: ";
                double M{ inputValidator() };

                double c{ cs * M };
                std::cout << "\nThe value of molar heat of this object is equal to: " << c << " J\n";
                break;
            }
            else if (choice == 2)
            {
                std::cout << "\nEnter the amount of heat delivered to the object: ";
                double q{ inputValidator() };
                std::cout << "Enter the change in temperature: ";
                double T{ inputValidator() };
                std::cout << "Enter the amount of moles of the object: ";
                double n{ inputValidator() };

                double c{ q / (T * n) };
                std::cout << "\nThe value of molar heat of this object is equal to: " << c << " J\n";
                break;
            }
            else
            {
                std::cout << "\nWrong number. Please try again: ";
            }
        }
    }
    else if (option == 2) //heat during phase change
    {
        std::cout << "Choose the phase change (1-2):\n"
            << " - melting (1)\n"
            << " - evaporation (2)\n"
            << "\nPhase: ";

            while (true)
            {
                int phase{ static_cast<int>(inputValidator()) };

                if (phase == 1) //melting
                {
                    std::cout << "\nEnter the mass of the object: ";
                    double m{ inputValidator() };
                    std::cout << "Enter the constant heat of melting: ";
                    double L{ inputValidator() };

                    double c{ m * L };
                    std::cout << "\nThe heat of this phase change is equal to: " << c << " J\n";
                    break;
                }
                else if (phase == 2) //evaporation
                {
                    std::cout << "\nEnter the mass of an object: ";
                    double m{ inputValidator() };
                    std::cout << "Etner constant heat of evaporating: ";
                    double R{ inputValidator() };

                    double c{ m * R };
                    std::cout << "\nThe heat of this phase change is equal to: " << c << " J\n";
                    break;
                }
                else
                {
                    std::cout << "\nWrong number. Please try again: ";
                }
            }
    }
    else if (option == 3) //regular heat
    {
        std::cout << "Enter the mass of an object: ";
            double m{ inputValidator() };
            std::cout << "Enter the constant specific heat of a substance: ";
            double w{ inputValidator() };
            std::cout << "Enter the change of temperature: ";
            double T{ inputValidator() };
            
            double c{ m * w * T };
            std::cout << "\nThe regular heat of the object is equal to: " << c << " J\n";
    }
    else
    {
        std::cout << "The number you've chosen does not correspond to any available function. Please try again\n"
            << "\n---------------------------------------------------------------------------\n";
        heat();
    }
}

void thermoChoice()
{
	int choice{ static_cast<int>(inputValidator()) };
	std::cout << '\n';
	
	switch (choice)
	{
	case 1:
		std::cout << "---------------------------------------------------------------------------\n";
		firstLaw();
		break;
    case 2:
        std::cout << "---------------------------------------------------------------------------\n";
        idealGasLaw();
        break;
    case 3:
        std::cout << "---------------------------------------------------------------------------\n";
        heat();
        break;
	default:
		std::cout << "The number you've chosen does not correspond to any available function. Please try again: ";
		thermoChoice();
	}
}

void thermodynamics()
{
	std::cout << "Your chosen field: thermodynamics\n"
		<< "---------------------------------------------------------------------------\n"
		<< "What function are you looking for?\n\n"
		<< " - change of energy in the system (1)\n"
        << " - Clausius-Clapeyron equation (2)\n"
        << " - heat in many aspects (3)\n"
		<< "\nFunction: ";
	thermoChoice();

	std::cout << "\n---------------------------------------------------------------------------\n";
	std::cout << "\nDo you wish to calculate anything else in this field? (Y/N): ";
	char endOrNot;
	std::cin >> endOrNot;
	std::cin.ignore(32767, '\n');

	if (endOrNot == 'y' || endOrNot == 'Y')
	{
		std::cout << "\n---------------------------------------------------------------------------\n";
		thermodynamics();
	}
}