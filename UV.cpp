#include "UV.h"
//#include <cstring>
#include<string>

using namespace std;
using namespace UV_credits_types;

    string UV::getCode() const{
        return code;
    };

    string UV::getTitre() const{
        return titre;
    };

    void UV::setCode(const string& c){
        code = c;
    };

    void UV::setTitre(const string& t){
         titre = t;
    };

    UV::UV(const string& c,const string& t){
        code = c;
        titre = t;
    };


// j'ajoute un commentaire ici

