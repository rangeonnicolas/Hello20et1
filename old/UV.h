#ifndef UV_H
#define UV_H

#include<string>
#include<qlist.h>
#include<iostream>
#include<QString>

using namespace std;

namespace UV_credits_types{

    class UV{
        QString code;
        QString titre;
    public:
        inline QString getCode() const {return code;}
        inline QString getTitre() const {return titre;}
        inline void setCode(const QString& c) { code =c;}
        inline void setTitre(const QString& t){ titre=t;}
        inline UV(const QString& c,const QString& t):code(c),titre(t){}
    };



    class CreditType{
        QString libelle;
    public:
        inline CreditType(const QString& l):libelle(l){ }
        inline QString getLibelle() const { return libelle ;}
        inline void setLibelle(const QString &s) { libelle = s ;}
    };


    class CreditTypeManager{
        QList<CreditType> list_CT;
    public :
        inline void addType (const QString& t){ list_CT.append(t) ;}
        const CreditType* getFromType(const QString& libelle) const;
        //inline void displayAll() { for(int i=0;i<list_CT.length();i++) std::cout<<list_CT.at(i).getLibelle()<<"\n" ;};
        // TODO NICO : displayAll: mettre le flux de sortie en paramètre
    };


    class Credits{
        const CreditType* type; //TODO NICO: remettre tous les const dans l'UML
        unsigned int nb_credits;
    public:
        inline Credits(CreditType* t,unsigned int nb):type(t),nb_credits(nb){}
        inline Credits():type(0), nb_credits(0){}
        inline const CreditType* getType() const {return type; }
        inline unsigned int getNbCredits() const {return nb_credits;}
        inline void setType(CreditType* t) {type=t ;}
        inline void setNbCredits(unsigned int nb){nb_credits=nb ;}
    };
    class Portee{
        QString libelle;
    public:
        inline Portee(const QString l):libelle(l){}
        inline Portee():libelle(""){}
        inline QString getLibelle() const {return libelle;}
        inline void setLibelle(const QString l) {libelle=l ;}

    };

    class PorteeManager{
        QList<Portee> list_P;
    public:
        inline void addPortee (const QString l){ list_P.append(Portee(l)) ;}
        const Portee* getFromPortee(const QString &libelle) const;
        //inline void displayAll(){ for(int i=0;i<list_P.length();i++) std::cout<<list_P.at(i).getLibelle()<<"\n" ;}
    };
}

#endif // UV_H




/*
#ifndef UV_H
#define UV_H

#include<string>
#include<qlist.h>
#include<iostream>



namespace UV_credits_types{

    using namespace std;

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
        const CreditType* getFromType(const string& libelle) const;
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
        inline string getLibelle() const {  return libelle;};
        inline void setLibelle(const char* l) { libelle=l ;};
    };

    class PorteeManager{
        QList<Portee> list_P;
    public:
        inline void addPortee (const char* l){ list_P.append(Portee(l)) ;};
        const Portee* getFromPortee(const string &libelle) const;
        inline void displayAll(){ for(int i=0;i<list_P.length();i++) std::cout<<list_P.at(i).getLibelle()<<"\n" ;};
    };
}

#endif // UV_H
*/
