#include "regiszter_tomb.h"

void Regiszter_tomb::inc_reg(){
	Regiszter*  temp = regiszterek;
	regiszterek = new Regiszter[meret + 1];
	for (int i = 0; i < meret; i++) {
		regiszterek[i] = temp[i];
	}
	
}

int Regiszter_tomb::is_elem(string NEV){
	for (int i = 0; i < meret; i++){
		if (regiszterek[i].tell_nev() == NEV){
			return i;
		}
	}
	return -1;
}

void Regiszter_tomb::set_reg(string NEV, double ERTEK){
	int elem = is_elem(NEV);
	if (elem == -1){
		inc_reg();
		regiszterek[meret].set(NEV, ERTEK);
		meret++;
	}
	else{
		regiszterek[elem].set(NEV, ERTEK);
	}
}

string Regiszter_tomb::tell_nev(int regiszter_szama){
	if (regiszter_szama >= meret) {
		throw "Nincs Regiszter";
	}
	return regiszterek[regiszter_szama].tell_nev();
}

double Regiszter_tomb::tell_ertek(int regiszter_szama){
	if (regiszter_szama >= meret) {
		throw "Nincs Regiszter";
	}
	return regiszterek[regiszter_szama].tell_ertek();
}
