#include "numar.h"

numar::numar():pt_adulti(0),anim(0),animale() {}
numar::numar(bool b,bool c,std::vector<std::string> v):pt_adulti(b),anim(c),animale(v) {}
numar::numar(const numar& n)
{
    pt_adulti=n.pt_adulti;
    anim=n.anim;
    for(auto&it:n.animale)
    {
        animale.push_back(it);
    }
}
numar::~numar()
{
    pt_adulti=0;
    anim=0;
    animale.clear();
}
bool numar::get_pt_adulti()
{
    return pt_adulti;
}
std::vector<std::string> numar::get_animale()
{
    return animale;
}
void numar::add_animal(std::string animal)
{
    if(anim==0)
        anim=1;
    animale.push_back(animal);
}
std::ostream &operator << (std::ostream &output, numar &n)
{
    if (n.pt_adulti==0)
        output<<"Numarul e adecvat pentru toate categoriile de varsta \n";
    else
        output<<"Numarul e adecvat numai pentru adulti \n";
    if (n.anim==1)
    {
        output<<"Animale folosite: ";
        for(auto&it:n.animale)
            output<<it<<" ";
    }
    else
    {
        output<<"Nu sunt folosite animale pentru acest numar";
    }
    output<<"\n";
    return output;
}
std::istream &operator >> (std::istream &input, numar  &n)
{
    if(&input==&std::cin)
        std::cout<<"Introduceti categoria de varsta ('0'=pentru toate varstele; '1'=numai pentru adulti): ";
    input>>n.pt_adulti;
    if(&input==&std::cin)
        std::cout<<"Numarul foloseste animale('1') / numarul nu foloseste animale('0'): ";
    input>>n.anim;
    if(n.anim==1)
    {
        if(&input==&std::cin)
            std::cout<<"Introduceti numarul de animalele folosite: ";
        int nr;
        input>>nr;
        input.get();
        for(int i=1; i<=nr; i++)
        {
            if(&input==&std::cin)
                std::cout<<"Introduceti animalul "<<i<<": ";
            std::string s;
            getline(input,s);
            n.animale.push_back(s);
        }
    }
    else
    {
        input.get();
    }
    return input;
}
numar  numar::operator=(const numar &n)
{
    if(this==&n)
        return *this;
    pt_adulti=n.pt_adulti;
    anim=n.anim;
    animale.clear();
    for(auto&it:n.animale)
    {
        animale.push_back(it);
    }
    return *this;
}
void n_numere(std::vector<numar *> &v,int n)
{
    while(n)
    {
        numar a;
        std::cin>>a;
        v.push_back(new numar(a));
        n--;
    }
    for(auto&it:v)
        std::cout<<*it;
}
void numar::set_pt_adulti(bool b)
{
    pt_adulti=b;
}
