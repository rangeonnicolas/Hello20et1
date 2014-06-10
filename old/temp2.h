#ifndef TEMP2_H
#define TEMP2_H

#include "Cursus.h"
using namespace CURSUS;

class dataBase{
public:
    QList<Credits> returnCreditsOfAnUV(string codeUV, string portee) const;
    Cursus* getSavedAdministrationCursusTree() const;
};


#endif // TEMP2_H
