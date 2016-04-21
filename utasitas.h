#ifndef UTASITAS_H_INCLUDED
#define UTASITAS_H_INCLUDED

#include <iostream>
#include <string>
#include "regiszter_tomb.h"

using namespace std;


class Utasitas{
    string tipus;
    string adat;
public:
    Utasitas();
    void set_utasitas(string TIPUS, string ADAT);
    string tell_utasitas();
	string tell_utasitas_parameter();
	virtual int execute(Regiszter_tomb& regiszter_tomb) { return -1; };
};

class LET : public Utasitas{
public:
	int execute(Regiszter_tomb& regiszter_tomb);
};

class PRINT : public Utasitas{
public:
	virtual int execute(Regiszter_tomb& regiszter_tomb);
};

class IF : public Utasitas{
public:
	int execute(Regiszter_tomb& regiszter_tomb) {
		cout << "IF futtatas\n";
		return -1;
	}
};

class INPUT : public Utasitas{
public:
	virtual int execute(Regiszter_tomb& regiszter_tomb);
};

class GOTO : public Utasitas{
public:
	int execute(Regiszter_tomb& regiszter_tomb);
};

class PRINTNL : public PRINT{
public:
	int execute(Regiszter_tomb& regiszter_tomb);
};

ostream& operator<<(ostream& os, Utasitas utasitas);
#endif // UTASITAS_H_INCLUDED
