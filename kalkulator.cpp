#include "kalkulator.h"

void Kalkulator::inc_pc(){
    PC.inc_pc();
}

void Kalkulator::set_pc(unsigned int i){
    PC.set_pc(i);
}

unsigned int Kalkulator::tell_pc(){
    return PC.tell_pc();
}

void Kalkulator::set_reg(string NEV, double ERTEK){
    regiszterek.set_reg(NEV, ERTEK);
}

string Kalkulator::tell_reg_nev(int regiszter_szama){
    return regiszterek.tell_nev(regiszter_szama);
}

double Kalkulator::tell_reg_ertek(int regiszter_szama){
    return regiszterek.tell_ertek(regiszter_szama);
}

void Kalkulator::add_utasitas(string utasitas){
    utasitas_mem.add_utasitas(utasitas);
}

void Kalkulator::print_utasitasok(){
    utasitas_mem.print_utasitasok();
}
int Kalkulator::execute(unsigned int PC){
    return utasitas_mem.execute(regiszterek, PC);
}
