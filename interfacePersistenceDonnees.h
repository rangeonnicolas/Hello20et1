#ifndef INTERFACEPERSISTENCEDONNEES_H
#define INTERFACEPERSISTENCEDONNEES_H

#include <QList>
#include "UV.h"

using namespace UV_credits_types;

namespace DATABASE{

    class InterfacePersistence{

    public:
        virtual QList<UV*>* getAllUVs() const=0;
        virtual void saveAllUV() const=0;
        virtual QList<CreditType*>* getAllCreditTypes() const=0;
        virtual void saveAllCreditTypes() const=0;
        virtual QList<Portee*>* getAllPortees() const=0;
        virtual void saveAllPortee() const=0;
        virtual QList<Credits*>* returnCreditsOfAnUV(string codeUV, string portee) const=0;
    };

}

#endif // INTERFACEPERSISTENCEDONNEES_H
