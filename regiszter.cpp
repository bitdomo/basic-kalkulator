#include <string>
#include "regiszter.h"

Regiszter::Regiszter(){
    nev = '\0';
    ertek = 0;
}

void Regiszter::set(string NEV, double ERTEK){
    nev = NEV;
	ertek = ERTEK;
}

string Regiszter::tell_nev(){
    return nev;
}

double Regiszter::tell_ertek(){
    return ertek;
}

