#include "pofta.h"


pofta::pofta():gen(""),tip(""),durata_minima(0),animal(""),tip_teatru(""),tip_de_voce("") {}
pofta::pofta(std::string a,std::string b,int c,std::string d,std::string e,std::string f):gen(b),tip(a),durata_minima(c),animal(d),tip_teatru(e),tip_de_voce(f) {}
pofta::pofta(const pofta& p)
{
    gen=p.gen;
    tip=p.tip;
    durata_minima=p.durata_minima;
    animal=p.animal;
    tip_teatru=p.tip_teatru;
    tip_de_voce=p.tip_de_voce;
}
pofta::~pofta()
{
    gen.clear();
    tip.clear();
    durata_minima=0;
    animal.clear();
    tip_teatru.clear();
    tip_de_voce.clear();

}
std::ostream &operator << (std::ostream &output, pofta &p)
{
    if(p.tip.compare("")!=0)
        output<<"Tipul dorit: "<<p.tip<<"\n";
    if(p.gen!="")
        output<<"Genul dorit: "<<p.gen<<"\n";
    if(p.durata_minima>0)
        output<<"Durata minima dorita (minute): "<<p.durata_minima<<"\n";
    if (p.tip=="circ")
        output<<"Tipul de animal dorit: "<<p.animal<<"\n";
    else
    {
        if((p.tip=="teatru")&&(p.tip_teatru!=""))
            output<<"Teatru "<<p.tip_teatru<<"\n";

        else
        {
            if((p.tip=="opera") && (p.tip_de_voce!=""))
                output<<"Tipul de voce dorit: "<<p.tip_de_voce<<"\n";
        }
    }
    return output;
}
std::istream &operator >> (std::istream &input, pofta  &p)
{
    if(&input==&std::cin)
        std::cout<<"Pentru a sari peste o cerinta introduceti 'skip', iar in cazul duratei minime introduceti '0'\n";
    if(&input==&std::cin)
        std::cout<<"Introduceti tipul dorit: ";
    input>>p.tip;
    if(p.tip=="skip")
        p.tip="";
    if(p.tip!="circ")
    {
        if(&input==&std::cin)
            std::cout<<"Introduceti genul dorit: ";
        input>>p.gen;
        if(p.gen=="skip")
            p.gen="";
    }
    else
    {
        p.gen="comedie";
    }
    if(&input==&std::cin)
        std::cout<<"Introduceti durata minima dorita (minute): ";
    input>>p.durata_minima;
    if(p.tip=="teatru")
    {
        if(&input==&std::cin)
            std::cout<<"Introduceti tipul de teatru dorit: ";
        input>>p.tip_teatru;
        if(p.tip_teatru=="skip")
            p.tip_teatru="";
    }
    else
    {
        if(p.tip=="circ")
        {
            if(&input==&std::cin)
                std::cout<<"Introduceti animalul dorit: ";
            input.get();
            getline(input,p.animal);
            if(p.animal=="skip")
                p.animal="";
        }
        else
        {
            if(p.tip=="opera")
            {
                if(&input==&std::cin)
                    std::cout<<"Introduceti tipul de voce dorit: ";
                input>>p.tip_de_voce;
                if(p.tip_de_voce=="skip")
                    p.tip_de_voce="";
            }
        }
    }
    return input;
}

pofta  pofta::operator=(const pofta &p)
{
    if(this==&p)
        return *this;
    gen=p.gen;
    tip=p.tip;
    durata_minima=p.durata_minima;
    animal=p.animal;
    tip_teatru=p.tip_teatru;
    tip_de_voce=p.tip_de_voce;

    return *this;
}
void n_pofte(std::vector<pofta*> &v,int n)
{
    while(n)
    {
        pofta p;
        std::cin>>p;
        v.push_back(new pofta(p));
        n--;
    }
    for (auto &it:v)
        std::cout<<*it;
}

std::string pofta::get_gen()
{
    return gen;
}
std::string pofta::get_tip()
{
    return tip;
}
int pofta::get_durata_minima()
{
    return durata_minima;
}
std::string pofta::get_animal()
{
    return animal;
}
std::string pofta::get_tip_teatru()
{
    return tip_teatru;
}
std::string pofta::get_tip_de_voce()
{
    return tip_de_voce;
}
