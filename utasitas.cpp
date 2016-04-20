#include "utasitas.h"
using namespace std;

string remove_quote(string adat){
	char c = adat[0];
	unsigned int i = 0;
	string temp;
	while (c != '\0'){
		if (c != '\"') {
			temp += adat[i];
		}
		i++;
		c = adat[i];
	}
	return temp;
}

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

string Utasitas::tell_utasitas_parameter(){
	return adat;
}
ostream& operator<<(ostream& os, Utasitas utasitas){
    os << utasitas.tell_utasitas();
    return os;
}

int PRINT::execute(Regiszter_tomb & regiszter_tomb){
	string temp = tell_utasitas_parameter();
	if (temp[0] == '\"') {
		cout << remove_quote(temp) << endl;
	}
	else{
		string regiszter_nev;
		regiszter_nev += temp[0];
		int regiszter_szama = regiszter_tomb.is_elem(regiszter_nev);
		if (regiszter_szama != -1) {
			cout << regiszter_tomb.tell_ertek(regiszter_szama) << endl;
		}
		else{
			cout << "Nincs ilyen regiszter";
		}
	}
	
	return - 1;
}

int GOTO::execute(Regiszter_tomb & regiszter_tomb){
	
	return atoi(tell_utasitas_parameter().c_str())/10-1;
}
