#include <iostream>
#include <string>
#include "utasitas_mem.h"

using namespace std;

string tipus_megmondo(string utasitas){
    string temp;
    unsigned int i = 0;

    while(utasitas[i] != ' '){
        i++;
    }
    i++;
    while(utasitas[i] != ' '){
        temp += utasitas[i];
        i++;
    }
    return temp;
}

string parameter_megmondo(string utasitas){
    string temp;
    unsigned int i = 0;

    while(utasitas[i] != ' '){
        i++;
    }
    i++;
    while(utasitas[i] != ' '){
        i++;
    }
    i++;
    while(utasitas[i] != '\0'){
        temp += utasitas[i];
        i++;
    }
    return temp;
}

Utasitas_mem::Utasitas_mem(){
    utasitasok_szama = 0;
}

void Utasitas_mem::add_utasitas(string utasitas){
    string tipus;
    string parameter;
    tipus = tipus_megmondo(utasitas);
    parameter = parameter_megmondo(utasitas);

    if(tipus == "LET" || tipus == "let"){
        utasitasok[utasitasok_szama] = new LET;
        utasitasok[utasitasok_szama]->set_utasitas(tipus, parameter);
        utasitasok_szama++;
    }
    if(tipus == "PRINT" || tipus == "print"){
        utasitasok[utasitasok_szama] = new PRINT;
        utasitasok[utasitasok_szama]->set_utasitas(tipus, parameter);
        utasitasok_szama++;
    }
    if(tipus == "IF" || tipus == "if"){
        utasitasok[utasitasok_szama] = new IF;
        utasitasok[utasitasok_szama]->set_utasitas(tipus, parameter);
        utasitasok_szama++;
    }
    if(tipus == "INPUT" || tipus == "INPUT"){
        utasitasok[utasitasok_szama] = new INPUT;
        utasitasok[utasitasok_szama]->set_utasitas(tipus, parameter);
        utasitasok_szama++;
    }
    if(tipus == "GOTO" || tipus == "goto"){
        utasitasok[utasitasok_szama] = new GOTO;
        utasitasok[utasitasok_szama]->set_utasitas(tipus, parameter);
        utasitasok_szama++;
    }
}

void Utasitas_mem::print_utasitasok(){
    for(unsigned int i = 0; i < utasitasok_szama; i++){
        cout << (i+1) * 10 << " " << utasitasok[i]->tell_utasitas() << endl;
    }
}
void Utasitas_mem::execute(unsigned int PC){
    utasitasok[PC]->execute();
}
