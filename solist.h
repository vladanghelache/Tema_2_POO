#ifndef SOLIST_H_INCLUDED
#define SOLIST_H_INCLUDED
#include <string>
#include <vector>

class solist{
protected:
    std::string nume;
    std::string voce;
public:
    solist();
    solist(std::string,std::string);
    solist(const solist&);
    ~solist();
    void set_nume(std::string);
    void set_voce(std::string);
    std::string get_nume()const;
    std::string get_voce()const;
    friend std::ostream &operator << (std::ostream &output, solist &s);
    friend std::istream &operator >> (std::istream &input, solist &s);
    solist operator=(const solist&);
    friend void n_solisti(std::vector<solist*> &v,int n);
};
#endif // SOLIST_H_INCLUDED
