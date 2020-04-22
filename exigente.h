#ifndef EXIGENTE_H_INCLUDED
#define EXIGENTE_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include "mix.h"

class exigente
{
    std::vector<mix> combinatie;
    std::vector<std::string> animale_periculoase;
    int  durata_maxima;
    int  nr_maxim_spectatori;

public:
    exigente();
    exigente(std::vector<mix>, std::vector<std::string>, int, int);
    exigente(const exigente&);
    ~exigente();
    friend std::ostream &operator << (std::ostream &output, exigente &e);
    friend std::istream &operator >> (std::istream &input, exigente  &e);
    exigente  operator=(const exigente &);
    friend void n_exigente(std::vector<exigente*> &v,int n);
    std::vector<mix> get_combinatie();
    std::vector<std::string> get_animale_periculoase();
    int get_durata_maxima();
    int get_nr_maxim_spectatori();
};

#endif // EXIGENTE_H_INCLUDED
