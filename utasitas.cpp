#include "utasitas.h"
using namespace std;

string remove_char(string adat, char mit) {
	char c = adat[0];
	unsigned int i = 0;
	string temp;
	while (c != '\0') {
		if (c != mit) {
			temp += adat[i];
		}
		i++;
		c = adat[i];
	}
	return temp;
}

string nev_megmondo(string adat) {
	unsigned int i = 0;
	string temp; 
	while (adat[i] != '=') {
		temp += adat[i];
		i++;
	}
	return remove_char(temp, ' ');
}

double ertek_megmondo(Regiszter_tomb regiszter_tomb, string adat){
	unsigned int i = 0;
	double eredmeny;
	double bal_ertek;
	double jobb_ertek;
	string bal;
	string jobb;
	string op;
	string temp;
	while (adat[i] != '=') {
		i++;
	}
	i++;
	while (adat[i] != '\0') {
		temp += adat[i];
		i++;
	}
	temp = remove_char(temp, ' ');
	i = 0;
	while (temp[i] != '+' && temp[i] != '-' && temp[i] != '*' && temp[i] != '/'){
		if (temp[i] == '\0') {
			if (bal[0] >= 'A' && bal[0] <= 'Z' || bal[0] >= 'a' && bal[0] <= 'z') {
					if (regiszter_tomb.is_elem(bal) == -1) {
						bal_ertek = 0;
					}
					else {
						bal_ertek = regiszter_tomb.tell_ertek(regiszter_tomb.is_elem(bal));
					}
				}
				else {
					bal_ertek = atof(bal.c_str());
				}
				return bal_ertek;
			}
		bal += temp[i];
		i++;
	}
	op += temp[i];
	i++;
	while (temp[i] != '\0') {
		jobb += temp[i];
		i++;
	}
	if (bal[0] >= 'A' && bal[0] <= 'Z' || bal[0] >= 'a' && bal[0] <= 'z') {
		if (regiszter_tomb.is_elem(bal) == -1) {
			bal_ertek = 0;
		}
		else {
			bal_ertek = regiszter_tomb.tell_ertek(regiszter_tomb.is_elem(bal));
		}
	}
	else {
		bal_ertek = atof(bal.c_str());
	}

	if (jobb[0] >= 'A' && jobb[0] <= 'Z' || jobb[0] >= 'a' && jobb[0] <= 'z') {
		if (regiszter_tomb.is_elem(jobb) == -1) {
			jobb_ertek = 0;
		}
		else {
			jobb_ertek = regiszter_tomb.tell_ertek(regiszter_tomb.is_elem(jobb));
		}
	}
	else {
		jobb_ertek = atof(jobb.c_str());
	}
	if (op == "+") {
		eredmeny = bal_ertek + jobb_ertek;
	}
	if (op == "-") {
		eredmeny = bal_ertek - jobb_ertek;
	}
	if (op == "*") {
		eredmeny = bal_ertek * jobb_ertek;
	}
	if (op == "/") {
		eredmeny = bal_ertek / jobb_ertek;
	}
	return eredmeny;
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
		cout << remove_char(temp, '\"');
	}
	else{
		int regiszter_szama = regiszter_tomb.is_elem(temp);
		if (regiszter_szama != -1) {
			cout << regiszter_tomb.tell_ertek(regiszter_szama);
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

int INPUT::execute(Regiszter_tomb & regiszter_tomb){
	double input;
	cin >> input;
	regiszter_tomb.set_reg(tell_utasitas_parameter(), input);
	return -1;
}

int PRINTNL::execute(Regiszter_tomb& regiszter_tomb){
	PRINT::execute(regiszter_tomb);
	cout << endl;
	return -1;
}

int LET::execute(Regiszter_tomb & regiszter_tomb){
	regiszter_tomb.set_reg(nev_megmondo(tell_utasitas_parameter()), ertek_megmondo(regiszter_tomb, tell_utasitas_parameter()));
	return -1;
}
