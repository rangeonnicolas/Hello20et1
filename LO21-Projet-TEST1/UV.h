#ifndef UV_H
#define UV_H

#include<string>
#include<qlist.h>
#include<iostream>

using namespace std;

namespace UV_credits_types{

    class UV{
        string code;
        string titre;
    public:
        string getCode() const;
        string getTitre() const;
        void setCode(const string& c);
        void setTitre(const string& t);
        UV(const string& c,const string& t);
        // TODO NICO: mettre les fonctions en inline et mettre les affectations
    };


    class CreditType{
        string libelle;
    public:
        inline CreditType(const string& l):libelle(l){                 };
        inline string getLibelle() const             { return libelle ;};
        inline void   setLibelle(const string &s)    { libelle = s    ;};
    };

    class CreditTypeManager{
        QList<CreditType> list_CT;
    public :
        inline void addType (const string& t){ list_CT.append(t) ;};
        inline void displayAll()             { for(int i=0;i<list_CT.length();i++) std::cout<<list_CT.at(i).getLibelle()<<"\n" ;};
        // TODO NICO : displayAll: mettre le flux de sortie en paramètre
    };

    class Credits{
        CreditType type;
        unsigned int nb_credits;
    public:
        string getType();
    };
}

#endif // UV_H
