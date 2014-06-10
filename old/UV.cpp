#ifndef UV_CPP
#define UV_CPP

#include "UV.h"

#include<string>

using namespace std;
using namespace UV_credits_types;



const CreditType* UV_credits_types::CreditTypeManager::getFromType(const QString& libelle) const{
	for(int i=0;i<list_CT.length();i++){
        if(strcmp(list_CT.at(i).getLibelle().toStdString().c_str() , libelle.toStdString().c_str()) == 0){
            return (const CreditType*) &list_CT.at(i);
		}
	}
    std::cout<<"\n\n!!!!!!!!!!!!!!!portee non trouvee!!!!!!!!!!!!!!!\n\n";//TODO nico: lever exception ici
    return 0;
}

const Portee* UV_credits_types::PorteeManager::getFromPortee(const QString &libelle) const{
	for(int i=0;i<list_P.length();i++){
        if(strcmp(list_P.at(i).getLibelle().toStdString().c_str() , libelle.toStdString().c_str()) == 0){
            return (const Portee*) &list_P.at(i);
		}
	}
    std::cout<<"\n\n!!!!!!!!!!!!!!!portee non trouvee!!!!!!!!!!!!!!!\n\n";//TODO nico: lever exception ici
    return 0;
}

#endif
