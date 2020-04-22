#include "solist.h"
#include <iostream>
solist::solist():nume(""),voce("") {}
solist::solist(std::string x,std::string y):nume(x),voce(y) {}
solist::solist(const solist&s)
{
    nume=s.nume;
    voce=s.voce;
}
solist::~solist()
{
    nume.clear();
    voce.clear();

}
void solist::set_nume(std::string s)
{
    nume=s;
}
void solist::set_voce(std::string s)
{
    voce=s;
}
std::string solist::get_nume()const
{
    return nume;
}
std::string solist::get_voce()const
{
    return voce;
}
std::ostream &operator << (std::ostream &output, solist &s)
{
    output<<"Nume solist: "<<s.nume<<"\n"<<"Voce solist: "<<s.voce<<"\n";
    return output;
}
std::istream &operator >> (std::istream &input, solist &s)
{
    if(&input==&std::cin)
        std::cout<<"Introduceti numele solistului: ";
    getline(input,s.nume);
    if(&input==&std::cin)
        std::cout<<"Introduceti voce: ";
    getline(input,s.voce);

    return input;
}
solist solist::operator=(const solist&s)
{
    nume=s.nume;
    voce=s.voce;

    return *this;
}
void n_solisti(std::vector<solist*> &v,int n)
{
    while(n)
    {
        solist s;
        std::cin>>s;
        v.push_back(new solist(s));
        n--;
    }
    for(auto&it:v)
        std::cout<<*it;
}
