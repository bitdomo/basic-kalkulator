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

void Kalkulator::set_reg_nev(unsigned int regiszter_szama, string NEV){
    regiszter[regiszter_szama].set_nev(NEV);
}

void Kalkulator::set_reg_ertek(unsigned int regiszter_szama, double ERTEK){
    regiszter[regiszter_szama].set_ertek(ERTEK);
}

string Kalkulator::tell_reg_nev(unsigned int regiszter_szama){
    return regiszter[regiszter_szama].tell_nev();
}

double Kalkulator::tell_reg_ertek(unsigned int regiszter_szama){
    return regiszter[regiszter_szama].tell_ertek();
}

void Kalkulator::add_utasitas(string utasitas){
    utasitas_mem.add_utasitas(utasitas);
}

void Kalkulator::print_utasitasok(){
    utasitas_mem.print_utasitasok();
}
void Kalkulator::execute(unsigned int PC){
    utasitas_mem.execute(PC);
    inc_pc();
}
