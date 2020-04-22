#include "teatru.h"
#include <stdlib.h>

teatru::teatru():spectacol(),interactiv(0) {}
teatru::teatru(bool b,std::string x,std::string y,int w, bool z, std::vector<prezentare*> vec):spectacol(x,y,w,z,vec),interactiv(b) {}
teatru::teatru(const teatru& t):spectacol(t)
{
    interactiv=t.interactiv;
}
teatru::~teatru()
{
    interactiv=0;
}
bool teatru::get_interactiv()
{
    return interactiv;
}
int teatru::durata_variabila()
{
    if(interactiv==0)
    {
        return 0;
    }
    if(pt_adulti==1)
    {
        return rand()%(v_prezentari[0]->get_nr_locuri()/2)+v_prezentari[0]->get_nr_locuri()/2;
    }
    int durata_adulti=rand()%(v_prezentari[0]->get_nr_locuri()/4)+v_prezentari[0]->get_nr_locuri()/4;
    int durata_copii=(rand()%(v_prezentari[0]->get_nr_locuri()/4)+v_prezentari[0]->get_nr_locuri()/4)*2;

    return durata_adulti+durata_copii;
}
std::ostream &operator << (std::ostream &output, teatru &t)
{
    output<<"Tipul spectacolului: "<<t.get_tip_spectacol()<<"\n";
    output<<((spectacol &) t);
    if(t.interactiv==1)
    {

        output<<"Interactiv\n"<<"Durata variabila: "<<t.durata_variabila()<<"\n";
    }
    else
        output<<"Neinteractiv\n";
    return output;
}
std::istream &operator >> (std::istream &input, teatru &t)
{
    input>>((spectacol&) t);
    if(&input==&std::cin)
        std::cout<<"Introduceti durata(min): ";
    input>>t.durata;
    if(&input==&std::cin)
        std::cout<<"Introduceti tipul teatrului ('1'=interactiv , '0'=neinteractiv): ";
    input>>t.interactiv;
    input.get();
    return input;
}
teatru teatru::operator=(const teatru& t)
{
    if(this==&t)
    {
        return *this;
    }
    interactiv=t.interactiv;
    (*this).spectacol::operator=(t);
    return *this;
}
void n_teatre(std::vector<teatru*> &v,int n)
{
    while(n)
    {
        teatru t;
        std::cin>>t;
        v.push_back(new teatru(t));
        n--;
    }
    for(auto&it:v)
        std::cout<<*it;
}

std::string teatru::get_tip_spectacol()
{
    return "teatru";
}
