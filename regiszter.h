#ifndef REGISZTER_H_INCLUDED
#define REGISZTER_H_INCLUDED
#include <string>

using namespace std;

class Regiszter{
    string nev;
    double ertek;
public:
    Regiszter();
    void set(string NEV, double ERTEK);
    string tell_nev();
    double tell_ertek();
};

#endif // REGISZTER_H_INCLUDED
