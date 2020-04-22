#ifndef PREZENTARE_H_INCLUDED
#define PREZENTARE_H_INCLUDED
#include <string>
#include <vector>
class prezentare{
protected:
    int nr_locuri;
    std::string data;
public:
    prezentare();
    prezentare(int,std::string);
    prezentare(const prezentare&);
    ~prezentare();
    void set_data(std::string);
    void set_nr_locuri(int);
    int get_nr_locuri()const;
    std::string get_data()const;
    friend std::ostream &operator << (std::ostream &output, prezentare &m);
    friend std::istream &operator >> (std::istream &input, prezentare &m);
    prezentare operator=(const prezentare&);
    friend void n_prezentari(std::vector<prezentare*> &v,int n);
};
#endif // PREZENTARE_H_INCLUDED
