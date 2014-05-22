#ifndef CURSUS_H
#define CURSUS_H

#include "temp_FAUSSES-CLASSES.h" //TODO NICO : supprimer cette ligne à la fin
using namespace FOOO; //TODO NICO : supprimer cette ligne à la fin

namespace CURSUS{

   class ValidationRule{

    public:
        virtual bool iscompleted(QList<FOOO::Inscription> ti) const =0;
        virtual float completion_percentage(QList<FOOO::Inscription> ti) const=0;
    };

   class public:ValidationRule{ //TODO NICO:verifier l'héritage publique

    public:
        virtual bool iscompleted(QList<FOOO::Inscription> ti) const =0;
        virtual float completion_percentage(QList<FOOO::Inscription> ti) const=0;
    };


}

#endif // CURSUS_H
