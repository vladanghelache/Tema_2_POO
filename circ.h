#ifndef CIRC_H_INCLUDED
#define CIRC_H_INCLUDED
#include "spectacol.h"
#include "numar.h"
#include <iostream>
#include <string>
#include <vector>

class circ:public spectacol
{
    std::vector<numar*> v_numere;
public:
    circ();
    circ(std::vector<numar*>,std::string,int,bool,std::vector<prezentare*>);
    circ(const circ&);
    ~circ();
    std::vector<numar*> get_v_numere();
    friend std::ostream &operator << (std::ostream &output, circ &c);
    friend std::istream &operator >> (std::istream &input, circ &c);
    circ operator=(const circ&);
    friend void n_circuri(std::vector<circ*> &v,int n);
    std::string get_tip_spectacol();
};



#endif // CIRC_H_INCLUDED
