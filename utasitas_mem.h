#ifndef UTASITAS_MEM_H_INCLUDED
#define UTASITAS_MEM_H_INCLUDED

#include "utasitas.h"

class Utasitas_mem{
    Utasitas** utasitasok;
    unsigned int utasitasok_szama;
public:
    Utasitas_mem();
    void utasitas_mem_inc();
    void add_utasitas(string utasitas);
    void print_utasitasok();
    void execute(unsigned int PC);
};

Utasitas* operator+(Utasitas* utasitasok, string utasitas);

#endif // UTASITAS_MEM_H_INCLUDED
