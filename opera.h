#ifndef OPERA_H_INCLUDED
#define OPERA_H_INCLUDED
#include "spectacol.h"
#include "act.h"
#include <vector>

class opera:public spectacol{
    std::vector<act*> v_acte;
    int pauza;
public:
    opera();
    opera(std::vector<act*>,int,std::string,std::string,int,bool,std::vector<prezentare*>);
    opera(const opera&);
    ~opera();
    std::vector<act*> get_v_acte();
    int get_pauza();
    friend std::ostream &operator << (std::ostream &output, opera &s);
    friend std::istream &operator >> (std::istream &input, opera &s);
    opera operator=(const opera&);
    friend void n_opere(std::vector<opera*> &v,int n);
    std::string get_tip_spectacol();
};


#endif // OPERA_H_INCLUDED
