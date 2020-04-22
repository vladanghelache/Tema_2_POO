#include "opera.h"
#include <iostream>

opera::opera():spectacol(),v_acte(),pauza(0) {}
opera::opera(std::vector<act*> v,int t,std::string x,std::string y,int w, bool z, std::vector<prezentare*> vec):spectacol(x,y,w,z,vec),v_acte(v),pauza(t)
{
    for(auto&it:v_acte)
        durata+=it->get_durata();
    durata+=pauza*(v_acte.size()-1);
}
opera::opera(const opera&o):spectacol(o)
{
    pauza=o.pauza;
    for (auto&it:o.v_acte)
    {
        v_acte.push_back(new act(*it));
    }
}
opera::~opera()
{
    pauza=0;
    for(auto&it:v_acte)
        delete it;
    v_acte.clear();
}
std::vector<act*> opera::get_v_acte()
{
    return v_acte;
}
int opera::get_pauza()
{
    return pauza;
}

std::ostream &operator << (std::ostream &output, opera &s)
{
    output<<"Tipul spectacolului: "<<s.get_tip_spectacol()<<"\n";
    output<<((spectacol&)s);
    int i=1;
    for(auto&it:s.v_acte)
    {
        output<<"Actul: "<<i<<"\n"<<*it;
        i++;
    }
    output<<"Pauza (min): "<<s.pauza<<"\n";
    return output;

}
std::istream &operator >> (std::istream &input, opera &s)
{
    input>>((spectacol&)s);
    if(&input==&std::cin)
        std::cout<<"Introduceti numarul de acte: ";
    int n;
    input>>n;
    input.get();
    while(n)
    {
        act a;
        input>>a;
        s.v_acte.push_back(new act(a));
        n--;
    }
    if(&input==&std::cin)
        std::cout<<"Introduceti pauza (min): ";
    input>>s.pauza;
    input.get();
    for(auto&it:s.v_acte)
        s.durata+=it->get_durata();
    s.durata+=s.pauza*(s.v_acte.size()-1);
    return input;
}
opera opera::operator=(const opera& o)
{
    if(this==&o)
    {
        return *this;
    }
    for (auto&it:v_acte)
    {
        delete it;
    }
    v_acte.clear();
    pauza=o.pauza;
    for (auto&it:o.v_acte)
    {
        v_acte.push_back(new act(*it));
    }
    (*this).spectacol::operator=(o);
    return *this;
}
void n_opere(std::vector<opera*> &v,int n)
{
    while(n)
    {
        opera o;
        std::cin>>o;
        v.push_back(new opera(o));
        n--;
    }
    for(auto&it:v)
        std::cout<<*it;
}
std::string opera::get_tip_spectacol()
{
    return "opera";
}
