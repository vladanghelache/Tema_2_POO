#ifndef MIX_H_INCLUDED
#define MIX_H_INCLUDED

struct mix
{
private:
    std::string tip;
    std::string gen;
public:
    mix()
    {
        tip="";
        gen="";
    }
    mix(std::string a,std::string b)
    {
        tip=a;
        gen=b;
    }
    mix(const mix& m)
    {
        tip=m.tip;
        gen=m.gen;
    }
    ~mix()
    {
        tip.clear();
        gen.clear();
    }
    std::string get_tip()
    {
        return tip;
    }
    std::string get_gen()
    {
        return gen;
    }
    void set_tip(std::string s)
    {
        tip=s;
    }
    void set_gen(std::string s)
    {
        gen=s;
    }
    mix  operator=(const mix &m)
    {
        if(this==&m)
            return *this;
        tip=m.tip;
        gen=m.gen;

        return *this;
    }
    friend std::ostream &operator << (std::ostream &output, mix &m)
    {
        output<<m.tip<<" / "<<m.gen<<"\n";
        return output;
    }
    friend std::istream &operator >> (std::istream &input, mix  &m)
    {
        if(&input==&std::cin)
            std::cout<<"Introduceti tipul: ";
        input>>m.tip;
        if(&input==&std::cin)
            std::cout<<"Introduceti genul: ";
        input>>m.gen;
        return input;
    }

};


#endif // MIX_H_INCLUDED
