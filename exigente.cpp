#include "exigente.h"

exigente::exigente():combinatie(),animale_periculoase(),durata_maxima(0),nr_maxim_spectatori(0) {}
exigente::exigente(std::vector<mix> a, std::vector<std::string> b, int c,int d):combinatie(a),animale_periculoase(b),durata_maxima(c),nr_maxim_spectatori(d) {}
exigente::exigente(const exigente&e)
{
    for(auto it:e.combinatie)
    {
        combinatie.push_back(it);
    }
    for(auto it:e.animale_periculoase)
    {
        animale_periculoase.push_back(it);
    }

    durata_maxima=e.durata_maxima;


    nr_maxim_spectatori=e.nr_maxim_spectatori;

}
exigente::~exigente()
{
    combinatie.clear();
    animale_periculoase.clear();
    durata_maxima=0;
    nr_maxim_spectatori=0;
}
std::ostream &operator << (std::ostream &output, exigente &e)
{
    if(e.combinatie.size()>0)
    {
        output<<"Combinatii tip/gen:\n";
        int i=0;
        for(auto&it:e.combinatie)
        {
            output<<++i<<": "<<it;
        }
    }
    if(e.animale_periculoase.size()>0)
    {
        output<<"Animale periculoase:\n";
        int i=0;
        for(auto&it:e.animale_periculoase)
        {
            output<<++i<<": "<<it<<"\n";
        }
    }
    if(e.durata_maxima)
        output<<"Durata maxima (minute): "<<e.durata_maxima<<"\n";
    if(e.nr_maxim_spectatori)
        output<<"Numar maxim de spectatori: "<<e.nr_maxim_spectatori<<"\n";

    return output;
}
std::istream &operator >> (std::istream &input, exigente  &e)
{
    if(&input==&std::cin)
        std::cout<<"Introduceti numarul de combinatii tip/gen: ";
    int n;
    input>>n;
    for(int i=1; i<=n; i++)
    {
        if(&input==&std::cin)
            std::cout<<i<<":\n";
        mix m;
        input>>m;
        e.combinatie.push_back(m);
    }
    if(&input==&std::cin)
        std::cout<<"Introduceti numarul de animale periculoase: ";

    input>>n;
    input.get();
    for(int i=1; i<=n; i++)
    {
        if(&input==&std::cin)
            std::cout<<"Introduceti animalul nr "<<i<<": ";
        std::string m;
        getline(input,m);
        e.animale_periculoase.push_back(m);
    }
    if(&input==&std::cin)
        std::cout<<"Introduceti durata maxima (minute): ";
    input>>e.durata_maxima;
    if(&input==&std::cin)
        std::cout<<"Introduceti numarul maxim de spectatori: ";
    input>>e.nr_maxim_spectatori;
    return input;
}
exigente  exigente::operator=(const exigente &e)
{
    if(this==&e)
        return *this;
    combinatie.clear();
    for(auto&it:e.combinatie)
    {
        combinatie.push_back(it);
    }
    animale_periculoase.clear();
    for(auto&it:e.animale_periculoase)
    {
        animale_periculoase.push_back(it);
    }
    durata_maxima=e.durata_maxima;
    nr_maxim_spectatori=e.nr_maxim_spectatori;

    return *this;
}
void n_exigente(std::vector<exigente*> &v,int n)
{
    while(n)
    {
        exigente e;
        std::cin>>e;
        v.push_back(new exigente(e));
        n--;
    }
    for(auto&it:v)
        std::cout<<*it;

}
std::vector<mix> exigente::get_combinatie()
{
    return combinatie;
}
std::vector<std::string> exigente::get_animale_periculoase()
{
    return animale_periculoase;
}
int exigente::get_durata_maxima()
{
    return durata_maxima;
}
int exigente::get_nr_maxim_spectatori()
{
    return nr_maxim_spectatori;
}
