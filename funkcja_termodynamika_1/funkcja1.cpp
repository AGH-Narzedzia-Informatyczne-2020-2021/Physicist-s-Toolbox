//First function concerning thermodynamics
#include <iostream>
#include <string>
#include <tgmath.h>
#include "constants.h"

void TheFirstLaw()
{
  cout << "The first law of thermodynamics is also known as The Law of Conservation of Energy" << endl;
  unsigned double q;
  cout << "Type how much heat was supplied to the system:" << endl;
  cin >> q;
  cout << "Type how much work was done on the layout:" << endl;
  unsigned double w;
  cin >> w;
  u=q+w;
  for(q<0)
  {
    cout << "Internal energy decrease in the system is equal %d, u" << endl;
  }
  else
  {
   cout << "Internal energy increase in the system is equal %d, u" << endl; 
  }

}

int main ()
{
  printf("TheFirstLaw");
  return: 0;
}
