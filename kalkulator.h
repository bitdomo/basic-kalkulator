#ifndef KALKULATOR_H_INCLUDED
#define KALKULATOR_H_INCLUDED
#include "PC.h"
#include "regiszter_tomb.h"
#include "utasitas_mem.h"

class Kalkulator{
    pc PC;
    Regiszter_tomb regiszterek;
    Utasitas_mem utasitas_mem;
public:
    void inc_pc();
    void set_pc(unsigned int i);
    unsigned int tell_pc();
    void set_reg(string NEV, double ERTEK);
    string tell_reg_nev(int regiszter_szama);
    double tell_reg_ertek(int regiszter_szama);
    void add_utasitas(string utasitas);
    void print_utasitasok();
    int execute(unsigned int PC);
};

#endif // KALKULATOR_H_INCLUDED
