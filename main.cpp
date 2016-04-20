#include <iostream>
#include <string>
#include "kalkulator.h"
using namespace std;

int main(){
	string input;
	int status = 0;
    Kalkulator kalkulator;
	while (getline(cin, input)){
		if (input == "") {
			break;
		}
		kalkulator.add_utasitas(input);
	}
	cout << "\nKovetkezo utasitasok futtatasa\n\n";
	kalkulator.print_utasitasok();
	kalkulator.set_reg("a", 523);
	cout << "\n";
	while (1) {
		status = kalkulator.execute(kalkulator.tell_pc());
		if (status == -2) {
			break;
		}
		if (status == -1) {
			kalkulator.inc_pc();
		}
		else {
			kalkulator.set_pc(status);
		}
	}
	return 0;
}
