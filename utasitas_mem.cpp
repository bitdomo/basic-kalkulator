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
        temp += toupper(utasitas[i]);
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
    utasitasok = new Utasitas*[0];
    utasitasok_szama = 0;
}
void Utasitas_mem::utasitas_mem_inc(){
    Utasitas** temp = utasitasok;
    utasitasok = new Utasitas*[utasitasok_szama + 1];
    for(unsigned int i = 0; i < utasitasok_szama; i++){
        utasitasok[i] = temp[i];
    }
    utasitasok_szama++;
}
void Utasitas_mem::add_utasitas(string utasitas){
    string tipus = tipus_megmondo(utasitas);
    string parameter = parameter_megmondo(utasitas);
    if(tipus == "LET"){
        utasitas_mem_inc();
        utasitasok[utasitasok_szama - 1] = new LET;
        utasitasok[utasitasok_szama - 1]->set_utasitas(tipus, parameter);
    }
    if(tipus == "PRINT"){
        utasitas_mem_inc();
        utasitasok[utasitasok_szama - 1] = new PRINT;
        utasitasok[utasitasok_szama - 1]->set_utasitas(tipus, parameter);
    }
	if (tipus == "PRINTNL") {
		utasitas_mem_inc();
		utasitasok[utasitasok_szama - 1] = new PRINTNL;
		utasitasok[utasitasok_szama - 1]->set_utasitas(tipus, parameter);
	}
    if(tipus == "IF"){
        utasitas_mem_inc();
        utasitasok[utasitasok_szama - 1] = new IF;
        utasitasok[utasitasok_szama - 1]->set_utasitas(tipus, parameter);
    }
    if(tipus == "INPUT"){
        utasitas_mem_inc();
        utasitasok[utasitasok_szama - 1] = new INPUT;
        utasitasok[utasitasok_szama - 1]->set_utasitas(tipus, parameter);
    }
    if(tipus == "GOTO"){
        utasitas_mem_inc();
        utasitasok[utasitasok_szama - 1] = new GOTO;
        utasitasok[utasitasok_szama - 1]->set_utasitas(tipus, parameter);
    }
}

void Utasitas_mem::print_utasitasok(){
    for(unsigned int i = 0; i < utasitasok_szama; i++){
        cout << (i+1) * 10 << " " << utasitasok[i]->tell_utasitas() << endl;
    }
}
int Utasitas_mem::execute(Regiszter_tomb& regiszterek, unsigned int PC){
	if (utasitasok_szama == PC) {
		return -2;
	}
    return utasitasok[PC]->execute(regiszterek);
}
