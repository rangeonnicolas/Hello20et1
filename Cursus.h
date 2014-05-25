#ifndef CURSUS_H
#define CURSUS_H

#include "temp_FAUSSES-CLASSES.h" //TODO NICO : supprimer cette ligne à la fin
using namespace FOOO; //TODO NICO : supprimer cette ligne à la fin
using namespace UV_credits_types;

namespace CURSUS{

   class ValidationRule{

    public:
        inline bool is_completed(QList<Inscription> *ti) const {return (this->completion_percentage(ti) >= 100) ;};
        //virtual bool is_completed(QList<Inscription> *ti) const=0;
        virtual float completion_percentage(QList<Inscription> *ti) const=0;
    };

   class XUVParmi: public ValidationRule { //TODO NICO:verifier l'héritage publique
        unsigned int nb;
        QList<UV*> UVlist;
    public:
        XUVParmi(unsigned int x, QList<UV*> list):nb(x),UVlist(list){};
        float completion_percentage(QList<Inscription> *ti) const;
    };

   class XCreditsParmi: public ValidationRule { //TODO NICO:verifier l'héritage publique
        unsigned int nb;
        QList<CreditType*> typeList;
        const Portee& portee;
    public:
        XCreditsParmi(unsigned int x, QList<CreditType*> typeList,const Portee& portee):nb(x),typeList(typeList),portee(portee){};
        float completion_percentage(QList<Inscription> *ti) const;
    };

    class FonctionOU: public ValidationRule { //TODO NICO:verifier l'héritage publique
        QList <ValidationRule> list;
    public:
        FonctionOU(){};
        float completion_percentage(QList<Inscription> *ti) const;
        inline void addRule(ValidationRule r){ list.append};
    };

}

#endif // CURSUS_H
