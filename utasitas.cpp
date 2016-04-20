#include "utasitas.h"
#include "iostream"
using namespace std;

Utasitas::Utasitas(){
    tipus = '\0';
    adat = '\0';
}

void Utasitas::set_utasitas(string TIPUS, string ADAT){
    tipus = TIPUS;
    adat = ADAT;
}

string Utasitas::tell_utasitas(){

    return tipus + " " + adat;
}

ostream& operator<<(ostream& os, Utasitas utasitas){
    os << utasitas.tell_utasitas();
    return os;
}
