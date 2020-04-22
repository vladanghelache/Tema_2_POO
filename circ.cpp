#include "circ.h"

circ::circ():spectacol(),v_numere()
{
    (*this).spectacol::gen="comedie";
}
circ::circ(std::vector<numar*> vec,std::string a,int b,bool c,std::vector<prezentare*> d):spectacol(a,"comedie",b,c,d),v_numere(vec) {}
circ::circ(const circ& c):spectacol(c)
{
    for(auto&it:c.v_numere)
        v_numere.push_back(new numar(*it));

}
circ::~circ()
{
    for(auto&it:v_numere)
        delete it;
    v_numere.clear();

}
std::vector<numar*> circ::get_v_numere()
{
    return v_numere;
}
std::ostream &operator << (std::ostream &output, circ &c)
{
    output<<"Tipul spectacolului: "<<c.get_tip_spectacol()<<"\n";
    output<<((spectacol &)c);
    int i=0;
    for(auto&it:c.v_numere)
    {
        output<<"Numarul: "<<++i<<"\n"<<*it;
    }
    output<<"Intre numere nu se ia pauza\n";
    return output;
}
std::istream &operator >> (std::istream &input, circ &c)
{
    if(&input==&std::cin)
        std::cout<<"Introduceti numele spectacolului: ";
    getline(input,c.nume);
    c.gen="comedie";

    if(&input==&std::cin)
        std::cout<<"Introduceti numarul de prezentari: ";
    int n;
    input>>n;
    input.get();
    while(n)
    {
        prezentare p;
        input>>p;
        c.v_prezentari.push_back(new prezentare(p));
        n--;
    }
    if(&input==&std::cin)
        std::cout<<"Introduceti durata(min): ";
    input>>c.durata;
    if(&input==&std::cin)
        std::cout<<"Introduceti numarul de numere: ";
    int m;
    input>>m;
    while(m)
    {
        numar r;
        input>>r;
        c.v_numere.push_back(new numar(r));
        m--;
    }
    for (auto&it:c.v_numere)
    {
        if((*it).get_pt_adulti()==1)
            c.pt_adulti=1;
    }

}
circ circ::operator=(const circ& c)
{
    if(this==&c)
        return *this;
    for(auto&it:v_numere)
        delete it;
    v_numere.clear();
    for(auto&it:c.v_numere)
        v_numere.push_back(new numar(*it));
    (*this).spectacol::operator=(c);
    return *this;
}
void n_circuri(std::vector<circ*> &v,int n)
{
    while(n)
    {
        circ c;
        std::cin>>c;
        v.push_back(new circ(c));
        n--;
    }
    for(auto&it:v)
        std::cout<<*it;
}
std::string circ::get_tip_spectacol()
{
    return "circ";
}
