//Funkcje do programu Physicist's Toolbox z zakresu kinematyki.
#include <iostream>
#include <string>
#include <tgmath.h>
#include "constants.h"

using namespace std;

void rzut_poziomy()
{
    cout << ("Wybrales rzut poziomy! Wybierz co chcesz policzyc(1-7):\n");
    cout << ("1.Predkosc pionowa w danej chwili\n2.Predkosc pozioma w danej chwili\n3.Predkosc skladowa w danej chwili\n4.Wspolrzedne polozenia ciala\n5.Czas spadku(lotu)\n6.Zasieg rzutu\n7.Wartosc predkosci koncowej ciala\n");
    int option = 0;
    char koniec;
    cin >> option;

    if(option == 1) //Predkosc pionowa w danej chwili
    {
        double h_0 = 0, t = 0, v_y = 0;
        cout << "Podaj wysokosc(metry): ";
        cin >> h_0;
        cout << "Podaj czas od momentu wyrzutu(sekundy): ";
        cin >> t;
        if(sqrt(2*h_0/EarthGrav) < t)
        {
            cout << "Cialo w podanym czasie juz bedzie na ziemi";
        }
        else
        {
            v_y = EarthGrav * t;
            cout << v_y << "m/s" << endl; 
        }
    
    }    
    if(option == 2) //Predkosc pozioma w danej chwili
    {
        cout << "Na tym poziomie zakladamy brak oporow ruchu, a wiec predkosc poziome w kazdej chwili jest stala, rowna predkosci poziomej poczatkowej" << endl;   
    }
    if(option == 3) //Predkosc skladowa w danej chwili
    {
        double h_0 = 0, t = 0, v_y = 0, v_x = 0, v = 0;
        cout << "Podaj wysokosc(metry): ";
        cin >> h_0;
        cout << "Podaj czas od momentu wyrzutu(sekundy): ";
        cin >> t;
        cout << "Podaj predkosc poczatkowa pozioma(czyli z jaka wyrzucono cialo): ";
        cin >> v_x;
        if(sqrt(2*h_0/EarthGrav) < t)
        {
            cout << "Cialo w podanym czasie juz bedzie na ziemi";
        }
        else
        {
            v_y = EarthGrav * t;
            v = sqrt((v_x * v_x)+(v_y * v_y));
            cout << v << "m/s" << endl; 
        }
     
    }
    if(option == 4) //Wspolrzedne polozenia ciala
    {
        double h_0 = 0, t = 0, v_y = 0, h = 0, x = 0, v_x = 0;
        cout << "Podaj wysokosc(metry): ";
        cin >> h_0;
        cout << "Podaj czas od momentu wyrzutu(sekundy): ";
        cin >> t;
        cout << "Podaj predkosc poczatkowa pozioma(czyli z jaka wyrzucono cialo): ";
        cin >> v_x;
        if(sqrt(2*h_0/EarthGrav) < t)
        {
            cout << "Cialo w podanym czasie juz bedzie na ziemi";
        }
        else
        {
            h = (h_0 - ((EarthGrav * t * t)/2));
            x = v_x * t;
            cout << "Cialo bedzie na wysokosci: " << h << "m, a oddalone w poziomie o: " << x << "m od punktu wyrzutu" << endl;
        }
    
    }
    if(option == 5) //Czas spadku(lotu)
    {
        double h = 0, t = 0;
        cout << "Podaj wysokosc(metry): ";
        cin >> h;
        t = sqrt(2*h/EarthGrav);
        cout << t << "s" << endl;
    }
    if(option == 6) //Zasieg rzutu
    {
        double h_0 = 0, v_0 = 0, zasieg = 0;
        cout << "Podaj wysokosc(metry): ";
        cin >> h_0;
        cout << "Podaj predkosc poczatkowa(m/s): ";
        cin >> v_0;

            zasieg = v_0 * sqrt((2 * h_0)/EarthGrav);
            cout << zasieg << "m" << endl; 
    }
    if(option == 7) //Wartosc predkosci koncowej ciala
    {
        double h_0 = 0, v_y = 0, v = 0, v_x = 0;
        cout << "Podaj wysokosc(metry): ";
        cin >> h_0;
        cout << "Podaj predkosc poczatkowa pozioma(czyli z jaka wyrzucono cialo): ";
        cin >> v_x;
        
        v = sqrt((v_x * v_x) + (2 * EarthGrav * h_0));
        cout << "Predkosc koncowa skladowa wynosi: " << v << "m/s" << endl;
     
    }
}
