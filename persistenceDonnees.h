#ifndef PERSISTENCEDONNEES_H
#define PERSISTENCEDONNEES_H

#include "interfacePersistenceDonnees.h"
#include "dataBaseA.h"

namespace DATABASE{
    class connectionDB{
        DATABASE::InterfacePersistence* db;
    public:
        connectionDB(int source);
        ~connectionDB();
        void resetConnection(int source);
        void refreshUVManager()const;
    };
}


#endif // PERSISTENCEDONNEES_H
