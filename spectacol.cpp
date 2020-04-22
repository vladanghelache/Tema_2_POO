#include "prezentare.h"
#include "spectacol.h"
#include "teatru.h"
#include "circ.h"
#include "opera.h"
#include <bits/stdc++.h>

spectacol::spectacol():nume(""),gen(""),durata(0),pt_adulti(0),v_prezentari() {}
spectacol::spectacol(std::string x,std::string y,int w, bool z, std::vector<prezentare*> vec):nume(x),gen(y),durata(w), pt_adulti(z),v_prezentari(vec) {}
spectacol::spectacol(const spectacol& s)
{
    nume=s.nume;
    gen=s.gen;
    durata=s.durata;
    pt_adulti=s.pt_adulti;
    for(auto&it:s.v_prezentari)
    {
        v_prezentari.push_back(new prezentare(*it));
    }
}
spectacol::~spectacol()
{
    gen.clear();
    nume.clear();
    durata=0;
    pt_adulti=0;
    for(auto&it:v_prezentari)
    {
        delete it;
    }
    v_prezentari.clear();

}
std::ostream &operator<<(std::ostream& output,spectacol& s)
{
    output<<"Nume spectacol: "<<s.nume<<"\n"<<"Gen: "<<s.gen<<"\n"<<"Durata spectacol(min): "<<s.durata<<"\n";
    if (s.pt_adulti==0)
        output<<"Spectacolul e adecvat pentru toate categoriile de varsta \n";
    else
        output<<"Spectacolul e adecvat numai pentru adulti \n";
    output<<"Prezentari:"<<std::endl;
    for(auto&it:s.v_prezentari)
    {
        output<<*it;
    }
    return output;
}
std::istream &operator>>(std::istream& input, spectacol& s)
{
    if(&input==&std::cin)
        std::cout<<"Introduceti numele spectacolului: ";
    getline(input,s.nume);
    if(&input==&std::cin)
        std::cout<<"Introduceti genul: ";
    getline(input,s.gen);

    if(&input==&std::cin)
        std::cout<<"Introduceti categoria de varsta ('0'=pentru toate varstele; '1'=numai pentru adulti): ";
    input>>s.pt_adulti;
    if(&input==&std::cin)
        std::cout<<"Introduceti numarul de prezentari: ";
    int n;
    input>>n;
    input.get();
    while(n)
    {
        prezentare p;
        input>>p;
        s.v_prezentari.push_back(new prezentare(p));
        n--;
    }

    return input;
}
spectacol& spectacol::operator=(const spectacol&s)
{
    if (this==&s)
    {
        return *this;
    }

    nume=s.nume;
    gen=s.gen;
    durata=s.durata;
    pt_adulti=s.pt_adulti;
    for(auto&it:v_prezentari)
    {
        delete it;
    }
    v_prezentari.clear();
    for(auto&it:s.v_prezentari)
    {
        v_prezentari.push_back(new prezentare(*it));
    }
    return *this;
}
void spectacol::add_prezentare(prezentare p)
{
    v_prezentari.push_back(new prezentare(p));
}
void n_spectacole(std::vector<spectacol*>&v,int n)
{
    while(n)
    {
        std::cout<<"Precizati tipul spectacolului pe care doriti sa il introduceti: ";
        std::string s;
        std::cin>>s;
        std::cin.get();
        if(s=="teatru")
        {
            teatru t;
            std::cin>>t;
            v.push_back(new teatru(t));
            n--;
        }
        else
        {
            if (s=="circ")
            {
                circ c;
                std::cin>>c;
                v.push_back(new circ(c));
                n--;
            }
            else
            {
                if (s=="opera")
                {
                    opera o;
                    std::cin>>o;
                    v.push_back(new opera(o));
                    n--;
                }
                else
                {
                    std::cout<<"Nu exista astfel de spectacol";
                }
            }
        }

    }
    for (auto&it:v)
    {
        if(teatru* t=dynamic_cast<teatru*>(it))
            std::cout<<*t;
        if(opera* o=dynamic_cast<opera*>(it))
            std::cout<<*o;
        if(circ* c=dynamic_cast<circ*>(it))
            std::cout<<*c;
    }
}
std::string spectacol::get_gen()
{
    return gen;
}
std::string spectacol::get_nume()
{
    return nume;
}
int spectacol::get_durata()
{
    return durata;
}
bool spectacol::get_pt_adulti()
{
    return pt_adulti;
}
std::vector<prezentare*> spectacol::get_v_prezentari()
{
    return v_prezentari;
}

