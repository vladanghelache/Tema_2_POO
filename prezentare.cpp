#include "prezentare.h"
#include <bits/stdc++.h>
#include <vector>

prezentare::prezentare():nr_locuri(0),data("") {}
prezentare::prezentare(int x,std::string y):nr_locuri(x),data(y) {}
prezentare::prezentare(const prezentare&p)
{
    nr_locuri=p.nr_locuri;
    data=p.data;
}
prezentare::~prezentare()
{
    nr_locuri=0;
    data.clear();
}
void prezentare::set_data(std::string y)
{
    data=y;
}
void prezentare::set_nr_locuri(int x)
{
    nr_locuri=x;
}
int prezentare::get_nr_locuri()const
{
    return nr_locuri;
}
std::string prezentare::get_data()const
{
    return data;
}
std::ostream &operator<<(std::ostream &output,prezentare &m)
{
    output<<"Data: "<<m.get_data()<<": "<<"Numar de locuri: "<<m.get_nr_locuri()<<std::endl;
    return output;
}

std::istream &operator>>(std::istream &input,prezentare &m)
{
    if(&input==&std::cin)
        std::cout<<"Introduceti data prezentarii: ";
    std::string s;
    getline(input,s);
    m.set_data(s);
    if(&input==&std::cin)
        std::cout<<"Introduceti numarul de locuri: ";
    int x;
    input>>x;
    m.set_nr_locuri(x);
    getline(input,s);

    return input;
}
void n_prezentari(std::vector<prezentare*> &v, int n)
{
    for(int i=0; i<n; i++)
    {
        prezentare p;
        std::cin>>p;
        v.push_back(new prezentare(p));

    }
    for(auto&it:v)
        std::cout<<*it;
}
prezentare prezentare:: operator=(const prezentare &p)
{
    if(this==&p)
    {
        return *this;
    }
    nr_locuri=p.nr_locuri;
    data=p.data;

    return *this;
}
