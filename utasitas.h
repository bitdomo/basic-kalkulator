#ifndef UTASITAS_H_INCLUDED
#define UTASITAS_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

class Utasitas{
    string tipus;
    string adat;
public:
    Utasitas();
    void set_utasitas(string TIPUS, string ADAT);
    string tell_utasitas();
    virtual void execute(){};
};

class LET : public Utasitas{
    void execute(){
        cout << "LELELELET";
    }
};

class PRINT : public Utasitas{
    void execute(){
        cout << "PRIIIIIINT";
    }
};

class IF : public Utasitas{

};

class INPUT : public Utasitas{

};

class GOTO : public Utasitas{
    void execute(){
        cout << "GOGOGOOGOGO";
    }
};
ostream& operator<<(ostream& os, Utasitas utasitas);
#endif // UTASITAS_H_INCLUDED
