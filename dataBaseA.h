#ifndef DATABASEA_H
#define DATABASEA_H

#include "UV.h"
#include "interfacePersistenceDonnees.h"

using namespace UV_credits_types;


namespace DATABASE{
    class UnpersistentDataBaseA: public DATABASE::InterfacePersistence{
    public:
        QList<UV*>* getAllUVs() const;
        void saveAllUV() const{};
        QList<CreditType*>* getAllCreditTypes() const{return 0;};
        void saveAllCreditTypes() const{};
        QList<Portee*>* getAllPortees() const{return 0;};
        void saveAllPortee() const{};
        QList<Credits*>* returnCreditsOfAnUV(string codeUV, string portee) const;
    };

}

#endif // DATABASEA_H
