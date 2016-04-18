#include <iostream>
#include "kalkulator.h"

using namespace std;

int main()
{
    Kalkulator kalkulator;

    kalkulator.inc_pc();
    cout << kalkulator.tell_pc() << "\n";
    kalkulator.set_pc(32);
    cout << kalkulator.tell_pc() << "\n";
    cout << kalkulator.tell_reg_nev(0) << "\n" << kalkulator.tell_reg_ertek(0) << "\n";
    kalkulator.set_reg_nev(0, "a");
    kalkulator.set_reg_ertek(0, 43);
    cout << kalkulator.tell_reg_nev(0) << "\n" << kalkulator.tell_reg_ertek(0) << "\n";
    kalkulator.print_utasitasok();
    kalkulator.add_utasitas("10 print hello vilag");
    kalkulator.add_utasitas("20 goto 10");
    kalkulator.print_utasitasok();
    kalkulator.set_pc(0);
    kalkulator.execute(kalkulator.tell_pc());
    cout << kalkulator.tell_pc() << "\n";
    kalkulator.execute(kalkulator.tell_pc());
    cout << kalkulator.tell_pc() << "\n";
    return 0;
}
