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
	try {
		cout << kalkulator.tell_reg_nev(0) << "\n";
	} catch (const char *p) {
		cout << p << endl;
	}
	try {
		cout << kalkulator.tell_reg_ertek(0) << "\n";
	} catch (const char *p) {
		cout << p << endl;
	}
		kalkulator.set_reg("a", 43);
	try {
		cout << kalkulator.tell_reg_nev(0) << "\n";
	} catch (const char *p) {
		cout << p << endl;
	}
	try{
		cout << kalkulator.tell_reg_ertek(0) << "\n";
	} catch (const char *p) {
		cout << p << endl;
	}
	kalkulator.set_reg("a", 31);
	try {
		cout << kalkulator.tell_reg_nev(0) << "\n";
	}
	catch (const char *p) {
		cout << p << endl;
	}
	try {
		cout << kalkulator.tell_reg_ertek(0) << "\n";
	}
	catch (const char *p) {
		cout << p << endl;
	}
	kalkulator.set_reg("b", -342);
	try {
		cout << kalkulator.tell_reg_nev(1) << "\n";
	}
	catch (const char *p) {
		cout << p << endl;
	}
	try {
		cout << kalkulator.tell_reg_ertek(1) << "\n";
	}
	catch (const char *p) {
		cout << p << endl;
	}
	kalkulator.set_reg("c", 555);
	try {
		cout << kalkulator.tell_reg_nev(2) << "\n";
	}
	catch (const char *p) {
		cout << p << endl;
	}
	try {
		cout << kalkulator.tell_reg_ertek(2) << "\n";
	}
	catch (const char *p) {
		cout << p << endl;
	}
	kalkulator	.print_utasitasok();
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
