#include <iostream>
#include <fstream>
#include "spectacol.h"
#include "opera.h"
#include "teatru.h"
#include "circ.h"
#include "persoana.h"

using namespace std;
ifstream fin("data.in");
ifstream in("client.in");

int main()
{
    vector<spectacol*> vect_spectacole;
    vector<persoana*> vect_clienti;
    int n;
    fin>>n;
    while(n)///se citesc din fisier spectacolele;
    {
        string s;
        fin>>s;
        fin.get();
        if(s=="teatru")
        {
            teatru t;
            fin>>t;
            vect_spectacole.push_back(new teatru(t));
            n--;
        }
        else
        {
            if (s=="circ")
            {
                circ c;
                fin>>c;
                vect_spectacole.push_back(new circ(c));
                n--;
            }
            else
            {
                if (s=="opera")
                {
                    opera o;
                    fin>>o;
                    vect_spectacole.push_back(new opera(o));
                    n--;
                }

            }
        }
    }
    int m;
    in>>m;
    in.get();
    while(m)///se citesc din fisier clientii;
    {

        persoana p;
        in>>p;
        vect_clienti.push_back(new persoana(p));
        m--;
    }

    int ok;

    do
    {
        cout<<"0 = exit\n1 = afisare lista spectacole\n2 = afisare lista clienti\n3 = adaugare spectacol\n4 = adaugare prezentare pentru un anume spectacol\n5 = adaugare client\n6 = afisare spectacole potrivite pentru un anumit client\n";
        cout<<"\nIntroduceti cifra corespunzatoare actiunii pe care doriti sa o efectuati: ";
        cin>>ok;
        if(ok==1)
        {
            cout<<"\nLista spectacole:\n\n";
            int i=0;
            for (auto&it:vect_spectacole)/// se afiseaza spectacolele;
            {
                cout<<"Spectacolul nr: "<<++i<<"\n";
                if(teatru* t=dynamic_cast<teatru*>(it))
                    cout<<*t<<"\n";
                if(opera* o=dynamic_cast<opera*>(it))
                    cout<<*o<<"\n";
                if(circ* c=dynamic_cast<circ*>(it))
                    cout<<*c<<"\n";
            }
        }
        if(ok==2)
        {
            cout<<"\nLista clienti:\n\n";///se afiseaza clientii;
            for(auto&it:vect_clienti)
                cout<<*it<<"\n";
        }
        if(ok==3)
        {
            string s;
            cout<<"\nIntroduceti tipul spectacolului pe care doriti sa il adaugati: ";
            cin>>s;
            cin.get();
            if(s=="teatru")
            {
                teatru t;
                cin>>t;
                vect_spectacole.push_back(new teatru(t));
            }
            else
            {
                if (s=="circ")
                {
                    circ c;
                    cin>>c;
                    vect_spectacole.push_back(new circ(c));
                }
                else
                {
                    if (s=="opera")
                    {
                        opera o;
                        cin>>o;
                        vect_spectacole.push_back(new opera(o));
                    }

                }
            }
        }
        if(ok==4)
        {
            cout<<"\nIntroduceti numarul de ordine din lista al spectacolului caruia ii adaugati o prezentare: ";
            int i;
            cin>>i;
            prezentare prez;
            cin.get();
            cin>>prez;
            vect_spectacole[i-1]->add_prezentare(prez);
        }
        if(ok==5)
        {
            cin.get();
            persoana pers;
            cin>>pers;
            vect_clienti.push_back(new persoana(pers));
        }
        if(ok==6)
        {
            string s;
            cout<<"\nIntroduceti numele clientului: ";
            cin.get();
            getline(cin,s);
            for(auto&cl:vect_clienti)
            {
                if(s==cl->get_nume())
                {

                    for(auto&sp:vect_spectacole)
                    {
                        int verif=0;

                        for(auto&poft:cl->get_v_pofte())
                        {

                            if(teatru*t=dynamic_cast<teatru*>(sp))
                                if(poft->get_tip()=="teatru"||poft->get_tip()=="")
                                {
                                    if(poft->get_gen()==""||poft->get_gen()==t->get_gen())//daca genul nu e o cerinta sau daca genul de portiveste
                                    {
                                        if(poft->get_durata_minima()==0||poft->get_durata_minima()<=t->get_durata())//daca durataa minima nu e o cetinta sau daca cerinta e implinita
                                        {
                                            if(poft->get_tip_teatru()==""||(poft->get_tip_teatru()=="interactiv"&&t->get_interactiv()==1)||(poft->get_tip_teatru()=="neinteractiv"&&t->get_interactiv()==0))
                                            {
                                                verif=1;
                                            }
                                        }
                                    }


                                }
                            if(circ*c=dynamic_cast<circ*>(sp))
                                if(poft->get_tip()=="circ"||poft->get_tip()=="")
                                {
                                    if(poft->get_gen()==""||poft->get_gen()==c->get_gen())//daca genul nu e o cerinta sau daca genul de portiveste
                                    {
                                        if(poft->get_durata_minima()==0||poft->get_durata_minima()<=c->get_durata())//daca durataa minima nu e o cetinta sau daca cerinta e implinita
                                        {
                                            for(auto&nr:c->get_v_numere())
                                                for(auto&anml:nr->get_animale())
                                                    if(poft->get_animal()==""||(poft->get_animal()==anml))
                                                    {
                                                        verif=1;
                                                    }
                                        }
                                    }


                                }
                            if(opera*o=dynamic_cast<opera*>(sp))
                                if
                                (poft->get_tip()=="opera"||poft->get_tip()=="")
                                {
                                    if(poft->get_gen()==""||poft->get_gen()==o->get_gen())//daca genul nu e o cerinta sau daca genul de portiveste
                                    {
                                        if(poft->get_durata_minima()==0||poft->get_durata_minima()<=o->get_durata())//daca durataa minima nu e o cetinta sau daca cerinta e implinita
                                        {
                                            for(auto&ac:o->get_v_acte())
                                                if(poft->get_tip_de_voce()==""||(poft->get_tip_de_voce()==ac->get_solist_principal().get_voce()))
                                                {
                                                    verif=1;
                                                }
                                        }
                                    }


                                }
                        }
                        if(sp->get_pt_adulti()==1 && cl->get_varsta()<16)
                            verif=0;
                        if(cl->get_exig().get_durata_maxima()>0&&cl->get_exig().get_durata_maxima()<sp->get_durata())
                            verif=0;
                        int k=0;
                        for(auto&prez:sp->get_v_prezentari())
                            if(cl->get_exig().get_nr_maxim_spectatori()>0&&cl->get_exig().get_nr_maxim_spectatori()<prez->get_nr_locuri())
                                k++;
                        if(k==sp->get_v_prezentari().size())
                            verif=0;


                        if(teatru* t=dynamic_cast<teatru*>(sp))
                        {
                            for(auto&comb:cl->get_exig().get_combinatie())
                                if(comb.get_tip()=="teatru" && comb.get_gen()==t->get_gen())
                                    verif=0;
                            if(t->get_interactiv()==1 &&cl->get_exig().get_nr_maxim_spectatori()>0&&cl->get_exig().get_nr_maxim_spectatori()<t->durata_variabila())
                                verif=0;

                        }
                        if(opera* o=dynamic_cast<opera*>(sp))
                        {
                            for(auto&comb:cl->get_exig().get_combinatie())
                                if(comb.get_tip()=="opera"&&comb.get_gen()==o->get_gen())
                                    verif=0;
                        }

                        if(circ* c=dynamic_cast<circ*>(sp))
                        {
                            for(auto&comb:cl->get_exig().get_combinatie())
                                if(comb.get_tip()=="circ"&&comb.get_gen()==c->get_gen())
                                    verif=0;
                            for(auto&a_p:cl->get_exig().get_animale_periculoase())
                                for(auto&nmr:c->get_v_numere())
                                    for(auto&a:nmr->get_animale())
                                        if(a_p==a)
                                            verif=0;
                        }



                        if(verif==1)
                            cout<<sp->get_nume()<<"\n";

                    }

                }

            }

        }
    }
    while(ok);
    for(auto&it:vect_clienti)
        delete it;
    for(auto&it:vect_spectacole)
        delete it;

    return 0;
}
