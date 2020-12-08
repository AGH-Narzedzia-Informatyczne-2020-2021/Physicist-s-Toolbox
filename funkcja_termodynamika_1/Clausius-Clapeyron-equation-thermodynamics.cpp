//Clausius-Clapeyron equation - thermodynamics
#include <iostream>
#include <string>
#include <tgmath.h>
#include "constants.h"

int main ()
{
  std::cout << "Welcome to Clausius-Clapeyron equation" << std::endl;
  std::cout << "Here you can get the value of the pressure of a gas or the value of its volume!" << std::endl;
  double n;
  std::cout << "Type the amount of moles of the gas:" << std::endl;
  std::cin >> n;
  std::cout << "What is the temperature (in kelvins)?" << std::endl;
  double T;
  std::cin >> T;
  double R = 8.314 ;
  double WYNIK;
  WYNIK = n*R*T;

    std::cout << "According to the Clausius-Clapeyron equation pressure of the gas multiplied by its volume equals "<< WYNIK << std::endl;
 
    std::cout << "What do you need to know the value of? Type: 1 for pressure or 2 for volume: "<< std::endl;
    double o;
    std::cin >> o ;
    if(o==1){
        std::cout << "What is the volume of the gas? (in moles/dm3)" << std::endl;
        double V;
        std::cin >> V;  
        double p;
        p=(n*R*T)/V;
        std::cout << "Pressure is eqaul tp: (in pascals) "<< p << std::endl;
        
    }
    else if(o==2){
        std::cout << "What is the pressure of the gas? (in pascals)" << std::endl;
        double p;
        std::cin >> p;  
        double V;
        V=(n*R*T)/p;
        std::cout << "The volume of the gas is equal: (in moles/dm3) "<< V << std::endl;
        
    }
    
}
