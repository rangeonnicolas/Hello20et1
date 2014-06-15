#ifndef DATABASEB_H
#define DATABASEB_H

#include "dossier.h"

using namespace INSCRIPTIONS;

class UnpersistentDataBaseB{
public:
    static Cursus* getSavedAdministrationCursusTree();
};

#endif // DATABASEB_H
