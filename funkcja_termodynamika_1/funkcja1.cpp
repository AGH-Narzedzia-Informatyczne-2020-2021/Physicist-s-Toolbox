//First function concerning thermodynamics
#include <iostream>
#include <string>
#include <tgmath.h>
#include "constants.h"

int main ()
{
  std::cout << "The first law of thermodynamics is also known as The Law of Conservation of Energy" << std::endl;
  double q;
  std::cout << "Type how much heat was supplied to the system (in Joules):" << std::endl;
  std::cin >> q;
  std::cout << "Type how much work was done on the system (in Joules):" << std::endl;
  double w;
  std::cin >> w;
  double u;
  u=q+w;
  if(u<0)
  {
   std::cout << "Internal energy decrease in the system is equal (in Joules) "<< u << std::endl;
  }
  else
  {
   std::cout << "Internal energy increase in the system is equal (in Joules) " << u << std::endl; 
  }

}
