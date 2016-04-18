#include "regiszter.h"

Regiszter::Regiszter(){
    nev = '\0';
    ertek = 0;
}

void Regiszter::set_nev(string NEV){
    nev = NEV;
}

void Regiszter::set_ertek(double ERTEK){
    ertek = ERTEK;
}

string Regiszter::tell_nev(){
    return nev;
}

double Regiszter::tell_ertek(){
    return ertek;
}
