#ifndef UV_CPP
#define UV_CPP

#include "UV.h"
#include "interfacePersistenceDonnees.h"
#include "dataBaseA.h"
#include "dataBaseB.h"

#include<string>

using namespace std;
using namespace UV_credits_types;
using namespace DATABASE;



const CreditType* UV_credits_types::CreditTypeManager::getFromType(const QString& libelle) const{
    for(int i=0;i<list_CT.length();i++){
           if(strcmp(list_CT.at(i)->getLibelle().toStdString().c_str() , libelle.toStdString().c_str()) == 0){
               return (const CreditType*) list_CT.at(i);
            }
    }
    return 0;
}

const Portee* UV_credits_types::PorteeManager::getFromPortee(const QString &libelle) const{
    for(int i=0;i<list_P.length();i++){
           if(strcmp(list_P.at(i)->getLibelle().toStdString().c_str() , libelle.toStdString().c_str()) == 0){
               return (const Portee*) list_P.at(i);
        }
    }
    return 0;
}


UVManager::UVManager():uvs(0),nbUV(0),nbMaxUV(0),file(""),modification(false){
}

void UVManager::load(const QString& f){
}

void UVManager::save(const QString& f){

}

UVManager::~UVManager(){
    if (file!="") save(file);
    for(unsigned int i=0; i<nbUV; i++) delete uvs[i];
    delete[] uvs;
}

void UVManager::addItem(UV* uv){
    if (nbUV==nbMaxUV){
        UV** newtab=new UV*[nbMaxUV+10];
        for(unsigned int i=0; i<nbUV; i++) newtab[i]=uvs[i];
        nbMaxUV+=10;
        UV** old=uvs;
        uvs=newtab;
        delete[] old;
    }
    uvs[nbUV++]=uv;
}

void UVManager::ajouterUV(const QString& c, const QString& t/*, unsigned int nbc, Categorie cat*/, bool a, bool p){
    if (trouverUV(c)) {
        throw UTProfilerException(QString("erreur, UVManager, UV ")+c+QString("déja existante"));
    }else{
        UV* newuv=new UV(c,t/*,nbc,cat*/,a,p);
        addItem(newuv);
        modification=true;
    }
}

UV* UVManager::trouverUV(const QString& c)const{
    for(unsigned int i=0; i<nbUV; i++)
        if (c==uvs[i]->getCode()) return uvs[i];
    return 0;
}



UV& UVManager::getUV(const QString& code){
    UV* uv=trouverUV(code);
    if (!uv) throw UTProfilerException("erreur, UVManager, UV inexistante",__FILE__,__LINE__);
    return *uv;
}

const UV* UVManager::getPtrUV(const QString& code)const{
    UV* uv=trouverUV(code);
    if (!uv) throw UTProfilerException("erreur, UVManager, UV inexistante",__FILE__,__LINE__);
    return uv;
}

const UV& UVManager::getUV(const QString& code)const{
    return const_cast<UVManager*>(this)->getUV(code);
}

UVManager::Handler UVManager::handler=Handler();

UVManager& UVManager::getInstance(){
    if (!handler.instance) handler.instance = new UVManager; /* instance créée une seule fois lors de la première utilisation*/
    return *handler.instance;
}

void UVManager::libererInstance(){
    if (handler.instance) { delete handler.instance; handler.instance=0; }
}


#endif
