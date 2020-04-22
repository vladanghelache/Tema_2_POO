#include "act.h"
#include <iostream>

act::act():solist_principal(),durata(0) {}
act::act(solist s,int x):solist_principal(s),durata(x) {}
act::act(const act& a)
{
    solist_principal=a.solist_principal;
    durata=a.durata;
}
act::~act()
{
    durata=0;
}
void act::set_solist_principal(solist s)
{
    solist_principal=s;
}
void act::set_durata(int x)
{
    durata=x;
}
solist act::get_solist_principal()
{
    return solist_principal;
}
int act::get_durata()
{
    return durata;
}
std::ostream &operator << (std::ostream &output, act &a)
{
    output<<a.solist_principal<<"Durata actului (min): "<<a.durata<<"\n";

    return output;
}
std::istream &operator >> (std::istream &input, act &a)
{
    input>>a.solist_principal;
    if(&input==&std::cin)
        std::cout<<"Introduceti durata actului (min): ";
    input>>a.durata;
    input.get();
    return input;
}
act act::operator=(const act&a)
{
    if(this==&a)
        return *this;
    solist_principal=a.solist_principal;
    durata=a.durata;
    return *this;
}
void n_acte(std::vector<act*> &v,int n)
{
    while(n)
    {
        act a;
        std::cin>>a;
        v.push_back(new act(a));
        n--;
    }
    for(auto&it:v)
        std::cout<<*it;
}
