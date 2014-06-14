#ifndef DATABASEPOSTGRES_H
#define DATABASEPOSTGRES_H

#include "interfacePersistenceDonnees.h"

namespace DATABASE{

    class dataBasePostgres: public InterfacePersistence{
        QSqlDatabase* db;
    public:
        dataBasePostgres(QSqlDatabase* db):db(db){};
        QList<UV*>* getAllUVs() const;
        void saveAllUV() const;
        QList<CreditType*>* getAllCreditTypes() const;
        void saveAllCreditTypes() const;
        QList<Portee*>* getAllPortees() const;
        void saveAllPortee() const;
        QList<Credits*>* returnCreditsOfAnUV(string codeUV, string portee) const;
    };

}


#endif // DATABASEPOSTGRES_H
