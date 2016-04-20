#ifndef REGISZTER_TOMB_H_INCLUDED
#define REGISZTER_TOMB_H_INCLUDED
#include "regiszter.h"
class Regiszter_tomb {
	Regiszter* regiszterek;
	int meret;
public:	
	void Regiszter_tomb::inc_reg();
	int is_elem(string NEV);
	void set_reg(string NEV, double ERTEK);
	string tell_nev(int regiszter_szama);
	double tell_ertek(int regiszter_szama);
};

#endif // PC_H_INCLUDED
