#ifndef REGISZTER_H_INCLUDED
#define REGISZTER_H_INCLUDED
#include <string>

using namespace std;

class Regiszter{
    string nev;
    double ertek;
public:
    Regiszter();
    void set_nev(string NEV);
    void set_ertek(double ERTEK);
    string tell_nev();
    double tell_ertek();
};

#endif // REGISZTER_H_INCLUDED
