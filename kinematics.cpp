#include <iostream>
#include <string>
#include <tgmath.h>
#include "constants.h"

using namespace std;

void horizontal_projection()
{
    cout << "Wybrales rzut poziomy! Wybierz co chcesz policzyc(1-7):\n"
        << "1.Predkosc pionowa w danej chwili\n"
        << "2.Predkosc pozioma w danej chwili\n"
        << "3.Predkosc skladowa w danej chwili\n"
        << "4.Wspolrzedne polozenia ciala\n" 
        << "5.Czas spadku(lotu)\n"
        << "6.Zasieg rzutu\n"
        << "7.Wartosc predkosci koncowej ciala\n";
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

void free_fall()
{
    cout << "Your choice: free fall! What function are you looking for?\n"
        << "1.Czas, po ktorym cialo rzucone w gore osiagnie maksymalna wysokosc\n"
        << "2.Maksymalna wysokosc, jaka osiagnie cialo rzucone w gore\n"
        << "3.Czas swobodnego spadania ciala z wysokosci\n"
        << "4.Predkosc, z jaka uderzy w ziemie swobodnie spadajace cialo\n" ;
    int option = 0;
    char koniec;
    cin >> option;

    if(option == 1) //Czas-ciało rzucone w górę
    {
        double t = 0, v_0 = 0;
        cout << "Podaj predkosc poczatkowa rzutu w gore (m/s): ";
        cin >> v_0;
        t = v_0 / EarthGrav;
        cout << t << "s";
    }    
    if(option == 2) //Maksymalna wysokosc
    {
        double v_0 = 0, h = 0;
        cout << "Podaj predkosc poczatkowa rzutu w gore (m/s): ";
        cin >> v_0;
        h = (v_0 * v_0)/(2 * EarthGrav);
        cout << h << "m";
    }
    if(option == 3) //Czas swobodnego spadku
    {
        double h = 0, t = 0;
        cout << "Podaj wysokosc(metry): ";
        cin >> h;
        t = sqrt(2*h/EarthGrav);
        cout << t << "s" << endl;
    }
    if(option == 4) //Predkosc uderzenia w ziemie
    {
        double h_0 = 0, v = 0;
        cout << "Podaj wysokosc z jakiej upuszczono cialo (m): ";
        cin >> h_0;
        v = sqrt(2 * EarthGrav * h_0);
        cout << v << "m/s";
    }
}

void circular_motion()
{
    cout << "Your choice: circular motion! What function are you looking for?\n"
        << "1.Okres i czestotliwosc ruchu po okregu\n"
        << "2.Okres(znajac czestotliwosc)\n"
        << "3.Czestotliwosc(znajac okres)\n"
        << "4.Predkosc liniowa w ruchu po okregu\n"
        << "5.Predkosc katowa wzgledem liniowej\n"
        << "6.Przyspieszenie dosrodkowe\n";
    int option = 0;
    char koniec;
    cin >> option;

    if(option == 1)
    {
        double n = 0, t = 60;
        cout << "Podaj liczbe obrotow na minute: ";
        cin >> n;
        cout << "Czestotliwosc: " << n / t << " Hz\n";
        cout << "Okres: " << t / n << " s";
    } 
    if(option == 2)
    {
        double f = 0;
        cout << "Podaj czestotliwosc: ";
        cin >> f;
        cout << "Okres: " << 1/f << " s";
    }
    if(option == 3)
    {
        double T = 0;
        cout << "Podaj okres: ";
        cin >> T;
        cout << "Czestotliwosc: " << 1/T << " Hz";
    }
    if(option == 4)
    {
        double r = 0, T = 0, f = 0;
        char znak;
        cout << "Podaj promien okregu: ";
        cin >> r;
        cout << "Podaj czestotliwosc lub okres"
            << "(jesli podajesz okres, przed wprowadzeniem wpisz literke 'f' i potwierdz 'enter', a nastepnie podaj wartosc."
            << "W przeciwnym wypadku 'T' i wartosc): ";
        cin >> znak;

        if(znak == 'f')
        {
            cin >> f;
            T = 1 / f;
        }
        else if(znak == 'T')
        {
            cin >> T;
        }
        else
        {
            cout << "Zly znak";
            exit(1);
        }
        
        cout << "Predkosc liniowa wynosi: " << (2 * pi * r)/T << " m/s";     
    }
    if(option == 5)
    {
        double v = 0, r = 0;
        cout << "Podaj predkosc liniowa: ";
        cin >> v;
        cout << "Podaj promien: ";
        cin >> r;
        cout << "Predkosc katowa wynosi: " << v / r << " rad/s";
    }
    if(option == 6)
    {

    }
}

/*int main()
{
    //free_fall();
    circular_motion();
    printf("ok");
    return 0;
}*/