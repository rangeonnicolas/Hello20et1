#include "completion.h"



QList<Inscription> AlgoCompletionSimple::copieDossier(const Dossier* d){
    QList<Inscription> liste=d->getInscr();

    return liste;

}
QMap<UV, int>& AlgoCompletionSimple::triUVs(const Dossier* d, const Demande* dem){
    //1=exigences;  2=preferences;  3=neutre;  4=rejets
    QMap<UV, int> mapUV;
    int special;
    UVManager& mana=UVManager::getInstance();
    UVManager::Iterator it=mana.getIterator();
    while(!it.isDone()){
        special=0;
        /*if(!dem->getExigences().contains(it.current())){
                if(!dem->getPreferences().contains(it.current())){
                    if(!dem->getRejets().contains(it.current())){
                        mapUV.insert(0,it.current(),3);
                    }
                    else
                        mapUV.insert(mapUV.end(),rej.at(k),4);
                }
                else
                    mapUV.insert(0,pre.at(i),2);
        }
        else
            mapUV.insert(0,ex.at(j),1);
        it.next();
    }*/

        for(int l=0;l<dem->getExigences().length();l++){
            if(it.current().getCode()==dem->getExigences().at(l)->getCode())
                special=1;
            else {
                for(int m=0;m<dem->getPreferences().length(); m++){
                    if(it.current().getCode()==dem->getPreferences().at(m)->getCode())
                        special=1;
                    else{
                        for(int n=0;n<dem->getRejets().length(); n++){
                            if(it.current().getCode()==dem->getRejets().at(n)->getCode())
                                special=1;
                        }
                    }
                }
            }

         }
        if (special==0)
           // mapUV[it.current().getCode()]=3;
            //mapUV.insert(0,it.current(),3);

        it.next();
    }
    //ajouter les preferences au début
    QList<UV*> pre=dem->getPreferences();
    for(int i=0; i<pre.length();i++){
       // mapUV.insert(0,pre.at(i),2);
    }
    //ajouter les exigences au début
    QList<UV*> ex=dem->getExigences();
    for(int j=0; j<ex.length();j++){
       // mapUV.insert(0,ex.at(j),1);
    }
    //ajouter les rejets à la fin
    QList<UV*> rej=dem->getRejets();
    for(int k=0; k<rej.length();k++){
       // mapUV.insert(mapUV.end(),rej.at(k),4);
    }

    return mapUV;
}



void AlgoCompletionSimple::createSolution(){}






void Demande::getSemestresEtranger(){}
void Demande::setExigences(){}
void Demande::setPreferences(){}
void Demande::setRejets(){}
void Demande::setSemestresEtranger(){}

