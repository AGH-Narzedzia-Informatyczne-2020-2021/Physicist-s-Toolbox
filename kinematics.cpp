#include <iostream>
#include <string>
#include <tgmath.h>
#include "constants.h"

using namespace std;

void horizontal_projection()
{
    cout << "Your choice: horizontal projection! Choose what you want to calculate(1-7):\n"
        << "1.Vertical speed in the moment.\n"
        << "2.Horizontal speed in the moment.\n"
        << "3.Total speed in the moment.\n"
        << "4.Coordinates of the body.\n" 
        << "5.Fall time.\n"
        << "6.Throw range.\n"
        << "7.Final speed of the body.\n";
    int option = 0;
    cin >> option;

    if(option == 1) //Vertical speed in the moment
    {
        double h_0 = 0, t = 0, v_y = 0;
        cout << "Enter height (metres): ";
        cin >> h_0;
        cout << "Enter the time from the throwing moment (seconds): ";
        cin >> t;
        if(sqrt(2*h_0/EarthGrav) < t)
        {
            cout << "The body will already be on earth at the given time";
        }
        else
        {
            v_y = EarthGrav * t;
            cout << v_y << "m/s" << endl; 
        }
    
    }    
    if(option == 2) //2.Horizontal speed in the moment
    {
        cout << "At this level, we assume no wind resistance,"
         << "so the horizontal speed is constant at all times, equal to the initial horizontal speed" << endl;   
    }
    if(option == 3) //Total speed in the moment
    {
        double h_0 = 0, t = 0, v_y = 0, v_x = 0, v = 0;
        cout << "Enter the height (metres): ";
        cin >> h_0;
        cout << "Enter the time from the throwing moment (seconds): ";
        cin >> t;
        cout << "Enter the initial horizontal speed (m/s): ";
        cin >> v_x;
        if(sqrt(2*h_0/EarthGrav) < t)
        {
            cout << "The body will already be on earth at the given time";
        }
        else
        {
            v_y = EarthGrav * t;
            v = sqrt((v_x * v_x)+(v_y * v_y));
            cout << v << "m/s" << endl; 
        }
     
    }
    if(option == 4) //Coordinates of the body
    {
        double h_0 = 0, t = 0, v_y = 0, h = 0, x = 0, v_x = 0;
        cout << "Enter the height (metres): ";
        cin >> h_0;
        cout << "Enter the time from the throwing moment (seconds): ";
        cin >> t;
        cout << "Enter the initial horizontal speed (m/s): ";
        cin >> v_x;
        if(sqrt(2*h_0/EarthGrav) < t)
        {
            cout << "The body will already be on earth at the given time";
        }
        else
        {
            h = (h_0 - ((EarthGrav * t * t)/2));
            x = v_x * t;
            cout << "The body will be in height: " << h << "m, and horizontally spaced by: ";
            cout << x << "m from the throw point" << endl;
        }
    
    }
    if(option == 5) //Fall time
    {
        double h = 0, t = 0;
        cout << "Enter the height (metres): ";
        cin >> h;
        t = sqrt(2*h/EarthGrav);
        cout << t << "s" << endl;
    }
    if(option == 6) //Zasieg rzutu
    {
        double h_0 = 0, v_0 = 0, zasieg = 0;
        cout << "Enter the height (metres): ";
        cin >> h_0;
        cout << "Enter the initial horizontal speed (m/s): ";
        cin >> v_0;

            zasieg = v_0 * sqrt((2 * h_0)/EarthGrav);
            cout << zasieg << "m" << endl; 
    }
    if(option == 7) //Final speed of the body
    {
        double h_0 = 0, v_y = 0, v = 0, v_x = 0;
        cout << "Enter the height (metres): ";
        cin >> h_0;
        cout << "Enter the initial horizontal speed (m/s): ";
        cin >> v_x;
        
        v = sqrt((v_x * v_x) + (2 * EarthGrav * h_0));
        cout << "Final speed of the body: " << v << "m/s" << endl;
     
    }
    else
    {
        cout << "The number you chose does not correspond to any available function. Please try again.\n";
        
    }
    
}

void free_fall()
{
    cout << "Your choice: free fall! What function are you looking for?\n"
        << "1.The time it takes for the body to reach its maximum height when thrown upwards.\n"
        << "2.The maximum height that the body can reach when thrown upwards.\n"
        << "3.Time of body free fall from height.\n"
        << "4.The speed at which a freely falling body will hit the ground.\n" ;
    int option = 0;
    char koniec;
    cin >> option;

    if(option == 1) //Time-maximum height
    {
        double t = 0, v_0 = 0;
        cout << "Enter the initial speed of the up throw (m/s): ";
        cin >> v_0;
        t = v_0 / EarthGrav;
        cout << t << "s";
    }    
    if(option == 2) //Maximum height
    {
        double v_0 = 0, h = 0;
        cout << "Enter the initial speed of the up throw (m/s): ";
        cin >> v_0;
        h = (v_0 * v_0)/(2 * EarthGrav);
        cout << h << "m";
    }
    if(option == 3) //Time of free fall
    {
        double h = 0, t = 0;
        cout << "Enter the height (metres): ";
        cin >> h;
        t = sqrt(2*h/EarthGrav);
        cout << t << "s" << endl;
    }
    if(option == 4) //The speed at which a freely falling body will hit the ground
    {
        double h_0 = 0, v = 0;
        cout << "Enter the height from which the body was dropped (metres): ";
        cin >> h_0;
        v = sqrt(2 * EarthGrav * h_0);
        cout << v << "m/s";
    }
    else
    {
        cout << "The number you chose does not correspond to any available function. Please try again.\n";
        free_fall();
    }
}

void circular_motion()
{
    cout << "Your choice: circular motion! What function are you looking for?\n"
        << "1.Period and frequency in circular motion.\n"
        << "2.Period (knowing the frequency).\n"
        << "3.Frequency (knowing the period).\n"
        << "4.Linear speed in a circular motion.\n"
        << "5.Angular speed regarding linear speed.\n"
        << "6.Centrifugal acceleration.\n";
    int option = 0;
    char koniec;
    cin >> option;

    if(option == 1)//Period and frequency
    {
        double n = 0, t = 60;
        cout << "Enter the number of revolutions per minute: ";
        cin >> n;
        cout << "Frequency: " << n / t << " Hz\n";
        cout << "Period: " << t / n << " s";
    } 
    if(option == 2)//Period
    {
        double f = 0;
        cout << "Enter the frequency: ";
        cin >> f;
        cout << "Period: " << 1/f << " s";
    }
    if(option == 3)//Frequency
    {
        double T = 0;
        cout << "Enter the period: ";
        cin >> T;
        cout << "Frequency: " << 1/T << " Hz";
    }
    if(option == 4)//Linear speed
    {
        double r = 0, T = 0, f = 0;
        char sign;
        cout << "Enter the radius of a circle (m): ";
        cin >> r;
        cout << "Enter the frequency or period"
            << "(If you enter the period key in: 'f' and push 'enter', and enter the value."
            << "Otherwise key in: 'T' and the value): ";
        cin >> sign;

        if(sign == 'f')
        {
            cin >> f;
            T = 1 / f;
        }
        else if(sign == 'T')
        {
            cin >> T;
        }
        else
        {
            cout << "Inappropriate letter\n";
            circular_motion();
        }
        
        cout << "The linear speed: " << (2 * pi * r)/T << " m/s";     
    }
    if(option == 5)//Angular speed
    {
        double v = 0, r = 0;
        cout << "Enter the linear speed: ";
        cin >> v;
        cout << "Enter the radius of a circle: ";
        cin >> r;
        cout << "Angular speed: " << v / r << " rad/s";
    }
    if(option == 6)//Centrifugal acceleration
    {
        double v = 0, r = 0, vk = 0, option2 = 0;
        cout << "Enter the radius of a circle: ";
        cin >> r;
        cout << "Do you know the angular (1) or linear (2) speed? ";
        cin >> option2;
        if(option2 == 1)
        {
            cout << "Enter this speed (rad/s): ";
            cin >> vk;
            cout << "The centrifugal speed: " << vk * vk * r << "rad/s^2";
        }
        if(option2 == 2)
        {
            cout << "Enter this speed (m/s): ";
            cin >> v;
            cout << "The centrifugal speed: " << v * v / r << "m/s^2";
        }
        
    }
    else
    {
        cout << "The number you chose does not correspond to any available function. Please try again.\n";
        circular_motion();
    }
}

void kinematics()
{
	cout << "\nYour chosen field: kinematics\n\nWhat function are you looking for?\n"
		<< "1.Horizontal projection\n"
		<< "2.Free fall\n"
		<< "3.Circular motion\n\n"
		<< "Function nr: ";
    int choice;
    cin >> choice;

	switch (choice)
	{
	case 1:
		horizontal_projection();
		break;
	case 2:
		free_fall();
		break;
	case 3:
		circular_motion();
		break;
	default:
		cout << "The number you chose does not correspond to any available function. Please try again.\n";
		kinematics();
	}
}

int main()
{
    horizontal_projection();

    return 0;
}