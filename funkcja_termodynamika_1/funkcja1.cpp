//First function concerning thermodynamics
#include <iostream>
#include <string>
#include <tgmath.h>
#include "constants.h"

void TheFirstLaw()
{
  std::cout << "The first law of thermodynamics is also known as The Law of Conservation of Energy" << endl;
  unsigned double q;
  std::cout << "Type how much heat was supplied to the system:" << endl;
  std::cin >> q;
  std::cout << "Type how much work was done on the layout:" << endl;
  unsigned double w;
  std::cin >> w;
  u=q+w;
  for(q<0)
  {
   std::cout << "Internal energy decrease in the system is equal"<< u << endl;
  }
  else
  {
   std::cout << "Internal energy increase in the system is equal" << u << endl; 
  }

}

int main ()
{
  printf("TheFirstLaw");
  return: 0;
}
