#include "PC.h"
pc::pc(){
    counter=0;
}

void pc::inc_pc(){
    counter++;
}

void pc::set_pc(unsigned int i){
    counter = i;
}

unsigned int pc::tell_pc(){
    return counter;
}
