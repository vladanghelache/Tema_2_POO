#ifndef TEATRU_H_INCLUDED
#define TEATRU_H_INCLUDED
#include "spectacol.h"
#include <iostream>
#include <string>
#include <vector>

class teatru:public spectacol{
    bool interactiv;
public:
    teatru();
    teatru(bool,std::string,std::string,int,bool,std::vector<prezentare*>);
    teatru(const teatru&);
    ~teatru();
    bool get_interactiv();
    int durata_variabila();
    friend std::ostream &operator << (std::ostream &output, teatru &t);
    friend std::istream &operator >> (std::istream &input, teatru &t);
    teatru operator=(const teatru&);
    friend void n_teatre(std::vector<teatru*> &v,int n);
    std::string get_tip_spectacol();
};
#endif // TEATRU_H_INCLUDED
