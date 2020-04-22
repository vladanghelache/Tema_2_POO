#ifndef POFTA_H_INCLUDED
#define POFTA_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>


class pofta
{
    std::string gen;
    std::string tip;
    int durata_minima;
    std::string animal;
    std::string tip_teatru;
    std::string tip_de_voce;
public:
    pofta();
    pofta(std::string,std::string,int,std::string,std::string,std::string);
    pofta(const pofta&);
    ~pofta();
    friend std::ostream &operator << (std::ostream &output, pofta &p);
    friend std::istream &operator >> (std::istream &input, pofta  &p);
    pofta  operator=(const pofta &);
    friend void n_pofte(std::vector<pofta*> &v,int n);
    std::string get_gen();
    std::string get_tip();
    int get_durata_minima();
    std::string get_animal();
    std::string get_tip_teatru();
    std::string get_tip_de_voce();

};

#endif // POFTA_H_INCLUDED
