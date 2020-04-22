#include "persoana.h"

persoana::persoana():nume(""),varsta(0),v_pofte(),exig() {}
persoana::persoana(std::string a,int b,std::vector<pofta*> c,exigente d):nume(a),varsta(b),v_pofte(c),exig(d) {}
persoana::persoana(const persoana& p)
{
    nume=p.nume;
    varsta=p.varsta;
    for(auto&it:p.v_pofte)
        v_pofte.push_back(new pofta(*it));
    exig=p.exig;
}
persoana::~persoana()
{
    nume.clear();
    varsta=0;
    for(auto&it:v_pofte)
    {
        delete it;
    }
    v_pofte.clear();

}
std::ostream &operator << (std::ostream &output, persoana &p)
{
    output<<"Numele: "<<p.nume<<"\nVarsta: "<<p.varsta<<"\n";
    int i=0;
    for(auto&it:p.v_pofte)
    {
        output<<"Pofta "<<++i<<": \n"<<*it;
    }
    output<<"Exigente: \n"<<p.exig;
    return output;
}
std::istream &operator >> (std::istream &input, persoana  &p)
{
    if(&input==&std::cin)
        std::cout<<"Introduceti numele persoanei: ";
    getline(input,p.nume);
    if(&input==&std::cin)
        std::cout<<"Introduceti varsta persoanei: ";
    input>>p.varsta;
    if(&input==&std::cin)
        std::cout<<"Introduceti numarul de pofte: ";
    int n;
    input>>n;
    input.get();
    while(n)
    {
        pofta t;
        input>>t;
        p.v_pofte.push_back(new pofta(t));
        n--;
    }
    if(&input==&std::cin)
        std::cout<<"Exigente: \n";
    input>>p.exig;
    input.get();
    return input;
}
persoana persoana::operator=(const persoana &p)
{
    if(this==&p)
        return *this;
    nume=p.nume;
    varsta=p.varsta;
    for(auto&it:v_pofte)
        delete it;
    v_pofte.clear();
    for(auto&it:p.v_pofte)
        v_pofte.push_back(new pofta(*it));
    exig=p.exig;
    return *this;
}
void n_persoane(std::vector<persoana*> &v,int n)
{
    while(n)
    {
        persoana p;
        std::cin>>p;
        v.push_back(new persoana(p));
        n--;
    }
    for(auto&it:v)
        std::cout<<*it;
}
std::string persoana::get_nume()
{
    return nume;
}
int persoana::get_varsta()
{
    return varsta;
}
exigente persoana::get_exig()
{
    return exig;
}
std::vector<pofta*> persoana::get_v_pofte()
{
    return v_pofte;
}

