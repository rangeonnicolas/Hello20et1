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
        inline string getCode()  const {return code;};
        inline string getTitre() const {return titre;};
        inline void setCode(const string& c) { code =c;};
        inline void setTitre(const string& t){ titre=t;};
        inline UV(const string& c,const string& t):code(c),titre(t){};
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
        const CreditType* type; //TODO NICO: remettre tous les const dans l'UML
        unsigned int nb_credits;
    public:
        inline Credits(CreditType* t,unsigned int nb):type(t),nb_credits(nb){};
        inline const CreditType* getType() const {return type;      };
        inline unsigned int getNbCredits() const {return nb_credits;};
        inline void setType(CreditType* t)       {type=t           ;};
        inline void setNbCredits(unsigned int nb){nb_credits=nb    ;};
    };

    class Portee{
        const char* libelle;
    public:
        inline Portee(const char* l):libelle(l){};
        inline string getLibelle() const {return libelle;};
        inline void setLibelle(const char* l) {libelle=l     ;};
    };

    class PorteeManager{
        QList<Portee> list_P;
    public:
        inline void addPortee (const char* l){ list_P.append(Portee(l)) ;};
        inline void displayAll(){ for(int i=0;i<list_P.length();i++) std::cout<<list_P.at(i).getLibelle()<<"\n" ;};
    };
}

#endif // UV_H
