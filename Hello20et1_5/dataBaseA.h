#ifndef DATABASEA_H
#define DATABASEA_H

#include "UV.h"

using namespace UV_credits_types;
//using namespace question3;

class dataBaseA{
public:
    QList<Credits> returnCreditsOfAnUV(string codeUV, string portee) const;
};


#endif // DATABASEA_H
