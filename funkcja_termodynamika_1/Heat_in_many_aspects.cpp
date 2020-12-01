//Heat in many aspects
#include <iostream>
#include <string>
#include <tgmath.h>

int main ()
{
  std::cout << "Welcome to 'Heat in many aspects'" << std::endl;
  std::cout << "Do you want to get the value of heat of an object or molar heat?" << std::endl;
  std::cout << "For molar heat type: 1, for heat of an object type 2:" << std::endl;
  double n;
    std::cin >> n ;
    if(n==1){
        std::cout << "Do you want to count molar heat using specific heat? Type: 1 to count using specific heat or 2 for equation without specific heat:" << std::endl;
        double r;
        std::cin >> r; 
        if(r==1){
            std::cout << "Type the value of specific heat: (in J/[kg*K])" << std::endl;
            double cs;
            std::cin >> cs;
            std::cout << "Type the value of molar mass of the object: (in kg/mol)" << std::endl;
            double M;
            std::cin>> M;
            double c;
            c=cs*M;
            std::cout << "The value of molar heat of this object is equal: (in j/[mol*kg]) "<< c << std::endl;
            
        }
        else if(r==2){
            std::cout << "Type the amount of heat delivered to an object: (in J)" << std::endl;
            double q;
            std::cin >> q;
            std::cout << "Type the amount of temeprature change: (in K)" << std::endl;
            double T;
            std::cin>> T;
            std::cout << "Type the amount of moles of the substance: (in mol)" << std::endl;
            double N;
            std::cin>> N;
            double c;
            c=q/(T*N);
            std::cout << "The value of molar heat of this object is equal: (in j/[mol*kg]) "<< c << std::endl;
            
        }
    }
    else if(n==2){
        std::cout << "Do you want to count heat in a phase change or regular heat? Type: 1 to count heat in a phase change or 2 for regural heat:" << std::endl;
        double k;
        std::cin>> k;
        if(k==1){
            std::cout << "Choose a phase change. Type: 1 for melting or 2 for evaporation:" << std::endl;
            double z;
            std::cin>> z;
            if(z==1){
                std::cout << "Type the mass of an object: (in kg)" << std::endl;
                double m;
                std::cin>> m;
                std::cout << "Type constant heat of melting: (in J/kg)" << std::endl;
                double L;
                std::cin>> L;
                double c;
                c-m*L;
                std::cout << "The value of heat of this phase change of the object is equal: (in J) "<< c << std::endl;
                
            }
            else if(z==2){
                std::cout << "Type the mass of an object: (in kg)" << std::endl;
                double m;
                std::cin>> m;
                std::cout << "Type constant heat of evaporating: (in J/kg)" << std::endl;
                double R;
                std::cin>> R;
                double c;
                c-m*R;
                std::cout << "The value of heat of this phase change of the object is equal: (in J) "<< c << std::endl;
                
            }
        }
        else if(k==2){
            std::cout << "Type the mass of an object: (in kg)" << std::endl;
            double m;
            std::cin>> m;
            std::cout << "Type constant specific heat of a substance: (in J/kg)" << std::endl;
            double w;
            std::cin>> w;
            std::cout << "Type the amount of temeprature change: (in K)" << std::endl;
            double T;
            std::cin>> T;
            double c;
            c=m*w*T;
            std::cout << "The value of heat of this phase change of the object is equal: (in J) "<< c << std::endl;
            
        }
      

    }

 
}
