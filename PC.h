#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED

class pc{
    unsigned int counter;
public:
    pc();
    void inc_pc();
    void set_pc(unsigned int i);
    unsigned int tell_pc();
};

#endif // PC_H_INCLUDED
