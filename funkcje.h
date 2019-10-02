// sin() wymaga radianow
float naRadiany(float stopnie)
{
    return (stopnie*M_PI)/180;
}
// oblicz wartosc nosnej w pozycji x i czestotliwosci
float nosna(float faza, int czestotliwosc)
{
    return sin(naRadiany(faza)*czestotliwosc);
}
// oblicz wartosc sygnalu
float sygnal(float faza, int ilosc_przebiegow, int czestotliwosc)
{
    return sin((naRadiany(faza)/(ilosc_przebiegow/360))*czestotliwosc);
}
