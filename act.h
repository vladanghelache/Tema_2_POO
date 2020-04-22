#ifndef ACT_H_INCLUDED
#define ACT_H_INCLUDED
#include "solist.h"

class act{
protected:
    solist solist_principal;
    int durata;
public:
    act();
    act(solist,int);
    act(const act&);
    ~act();
    void set_solist_principal(solist);
    void set_durata(int);
    solist get_solist_principal();
    int get_durata();
    friend std::ostream &operator << (std::ostream &output, act &a);
    friend std::istream &operator >> (std::istream &input, act &a);
    act operator=(const act&);
    friend void n_acte(std::vector<act*> &v,int n);
};
#endif // ACT_H_INCLUDED
