#ifndef SPECTACOL_H_INCLUDED
#define SPECTACOL_H_INCLUDED
#include "prezentare.h"
#include <iostream>
#include <vector>

class spectacol{
protected:
    std::string gen;
    std::string nume;
    int durata;
    bool pt_adulti;
    std::vector<prezentare*> v_prezentari;
public:
    spectacol();
    spectacol(std::string,std::string,int,bool,std::vector<prezentare*>);
    spectacol(const spectacol&);
    virtual ~spectacol();
    std::string get_gen();
    std::string get_nume();
    int get_durata();
    bool get_pt_adulti();
    std::vector<prezentare*> get_v_prezentari();
    friend std::ostream &operator<<(std::ostream& output,spectacol& s);
    friend std::istream &operator>>(std::istream& input,spectacol& s);
    spectacol& operator=(const spectacol&);
    void add_prezentare(prezentare);
    friend void n_spectacole(std::vector<spectacol*> &v,int n);
    virtual std::string get_tip_spectacol()=0;

};
#endif // SPECTACOL_H_INCLUDED
