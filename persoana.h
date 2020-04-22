#ifndef PERSOANA_H_INCLUDED
#define PERSOANA_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include "pofta.h"
#include "exigente.h"

class persoana
{
    std::string nume;
    int varsta;
    std::vector<pofta*> v_pofte;
    exigente exig;
public:
    persoana();
    persoana(std::string,int,std::vector<pofta*>,exigente);
    persoana(const persoana&);
    ~persoana();
    friend std::ostream &operator << (std::ostream &output, persoana &p);
    friend std::istream &operator >> (std::istream &input, persoana  &p);
    persoana  operator=(const persoana &);
    friend void n_persoane(std::vector<persoana*> &v,int n);
    std::string get_nume();
    int get_varsta();
    exigente get_exig();
    std::vector<pofta*> get_v_pofte();

};
#endif // PERSOANA_H_INCLUDED
