#include "inscription.h"


using namespace INSCRIPTIONS;
using namespace UV_credits_types;

Saison INSCRIPTIONS::StringToSaison(const QString str){
    if (str=="A") return Automne;
    else
    if (str=="P") return Printemps;
    else {
        throw UTProfilerException(QString("erreur, StringToSaison, saison ")+str+" inexistante");
    }
}

Note INSCRIPTIONS::StringToNote (const QString str){
    if (str=="A") return A;
    else
    if (str=="B") return B;
    else
    if (str=="C") return C;
    else
    if (str=="D") return D;
    else
    if (str=="E") return E;
    else
    if (str=="FX") return FX;
    else
    if (str=="F") return F;
    else
    if (str=="EC") return EC;
    else
    if (str=="AF") return AF;
    else {
        throw UTProfilerException(QString("erreur, StringToNote, note ")+str+" inexistante");
    }

}
