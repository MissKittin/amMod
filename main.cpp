#include <cstdlib>
#include <iostream>
#include <iomanip> // eliminacja notacji wylkadniczej
#include <math.h>
#include <fstream>
#include "funkcje.h"

using namespace std;

int main(int argc, char *argv[])
{
    // output do tekstu - otworz
    ofstream fout;
    fout.open("output.txt");

    // Eliminacja notacji wykladniczej
    fout << "Stopnie;Nosna;Sygnal;Modulacja" << endl;
    fout << fixed << setprecision(20) << showpoint;

    // Ustawienia
    int czestotliwosc_nosnej=500; // na jakich falach nadaje
    int ilosc_przebiegow=360000; // dokladnosc wykresu, im wieksza tym lepsza, ale wiekszy plik wyjsciowy
    int czestotliwosc_sygnalu=10; // jaka czestotliwosc sinusa

    // Wypisz dane
    cout << "Liczba przebiegow: " << ilosc_przebiegow << "\nCzestotliwosc sinusa nosnej: " << czestotliwosc_nosnej << "Hz\nCzestotliwosc sinusa sygnalu: " << czestotliwosc_sygnalu << "Hz\n\n Liczenie (kropka co 1000 obliczen)\n";

    // Petelka
    int ind=0;
    for(int i=0; i<=ilosc_przebiegow; i++)
    {
        // kropka co 1000 petle
        if(ind == 1000)
        {
            ind=0;
            cout << ".";
        }
        else
            ind=ind+1;

        // licz i zrzucaj do pliku
        fout << i << ";" << nosna(i,czestotliwosc_nosnej) << ";" << sygnal(i,ilosc_przebiegow,czestotliwosc_sygnalu) << ";" << nosna(i,czestotliwosc_nosnej)*sygnal(i,ilosc_przebiegow,czestotliwosc_sygnalu) << endl;
    }

    // zamknij output
    fout.close();

    cout << "\n Obliczono! ";
    system("PAUSE");
    return EXIT_SUCCESS;
}
