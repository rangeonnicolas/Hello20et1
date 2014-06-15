#ifndef INSCR_H
#define INSCR_H

#include "UV.h"

#include <QString>

using namespace UV_credits_types;

namespace INSCRIPTIONS{

    enum Note {A, B, C, D, E, FX, F, RES, ABS, EC, AF};
    Note StringToNote (const QString s);

    enum Saison { Automne, Printemps };

    Saison StringToSaison(const QString s);


    class Semestre {
        Saison saison;
        unsigned int annee;
    public:
        Semestre(Saison s, unsigned int a):saison(s),annee(a){ /*if (annee<1972||annee>2099) throw exception("annee non valide");*/ }
        Semestre(){}
        Saison getSaison() const { return saison; }
        unsigned int getAnnee() const { return annee; }
        void setSaison(const Saison& s){saison=s;}
        void setAnnee(const unsigned int& a){annee=a;}
    };

    class Inscription{
            Semestre semestre;
            Note resultat;
            const UV* uv;
        public:
            Inscription (const UV& u, const Semestre& s, Note res=AF):uv(&u), semestre(s), resultat(res){}
            Inscription (){}
            Inscription (UV* uv, Note res):uv(uv),resultat(res){}
            const UV& getUV()const {return *uv;}
            Semestre getSemestre() const{return semestre;}
            Note getResultat() const {return resultat;}
            void setResultat(const Note& newres){resultat=newres;}
            void setSemestre (const Semestre& s){semestre=s;}
            void setUv(const UV* u){uv=u;}
        };


    class CursusNullPtrException{
    public:
           CursusNullPtrException(const QString& message):
               info(message){}
           QString getInfo() const { return info; }
    private:
           QString info;
    };
}


#endif
