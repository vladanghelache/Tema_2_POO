#ifndef NUMAR_H_INCLUDED
#define NUMAR_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>

class numar{
protected:
    bool pt_adulti;
    bool anim;
    std::vector<std::string> animale;
public:
    numar();
    numar(bool,bool,std::vector<std::string>);
    numar(const numar&);
    ~numar();
    bool get_pt_adulti();
    std::vector<std::string> get_animale();
    void set_pt_adulti(bool);
    void add_animal(std::string);
    friend std::ostream &operator << (std::ostream &output, numar &t);
    friend std::istream &operator >> (std::istream &input, numar  &t);
    numar  operator=(const numar &);
    friend void n_numere(std::vector<numar *> &v,int n);
};
#endif // NUMAR_H_INCLUDED
