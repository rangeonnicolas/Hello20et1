#include "persistenceDonnees.h"

#include <QMessageBox>

using namespace DATABASE;

connectionDB::connectionDB(int source){
    if(source==1){
        db= new UnpersistentDataBaseA();
    }else{
        db= new UnpersistentDataBaseA();
    }
    refreshUVManager();
}

void connectionDB::resetConnection(int source){
    delete db;
    if(source==1){
        db= new UnpersistentDataBaseA();
    }else{
        db= new UnpersistentDataBaseA();
    }
    refreshUVManager();
}

connectionDB::~connectionDB(){
    delete db;
}

void connectionDB::refreshUVManager()const{
    QString code ="NF16";
    QString titre="Algo";
    bool autom=true;
    bool print=true;

    UVManager& uvm =UVManager::getInstance();
    QList<UV*>* allUV = db->getAllUVs();
    for(int i=0;i<allUV->length();i++){
        code=allUV->at(i)->getCode();
        titre=allUV->at(i)->getTitre();
        autom=allUV->at(i)->ouvertureAutomne();
        print=allUV->at(i)->ouverturePrintemps();
        try{
            uvm.ajouterUV(code,titre,autom,print);
        }catch(UTProfilerException e){
            QMessageBox::warning(0,"Attention",e.getInfo());
        }
    }
}

