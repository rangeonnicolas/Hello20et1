#include "completion.h"



QList<Inscription> AlgoCompletionSimple::copieDossier(const Dossier* d){
    QList<Inscription> liste=d->getInscr();

    return liste;

}
QMap<int, QString>& AlgoCompletionSimple::triUVs(const Dossier* d, const Demande* dem){
    //1=exigences;  2=preferences;  3=neutre;  4=rejets
    QMap<int, QString> mapUV;
     QString codeCurrent;
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
            if(it.current().getCode()==dem->getExigences().at(l)->getCode()){
                special=1;
                codeCurrent=it.current().getCode();
                mapUV[1]=codeCurrent;
            }
            else {
                for(int m=0;m<dem->getPreferences().length(); m++){
                    if(it.current().getCode()==dem->getPreferences().at(m)->getCode()){
                       special=1;
                       codeCurrent=it.current().getCode();
                       mapUV[2]=codeCurrent;
                    }


                    else{
                        for(int n=0;n<dem->getRejets().length(); n++){
                            if(it.current().getCode()==dem->getRejets().at(n)->getCode()){
                                special=1;
                                codeCurrent=it.current().getCode();
                                mapUV[4]=codeCurrent;
                            }
                        }
                    }
                }
            }

         }
        if (special==0)
             codeCurrent=it.current().getCode();
             mapUV[3]=codeCurrent;
            //mapUV.insert(0,it.current(),3);

        it.next();
    }
    /*
    //ajouter les preferences au début
    QList<UV*> pre=dem->getPreferences();
    for(int i=0; i<pre.length();i++){
        codeCurrent=it.current().getCode();
        mapUV[2]=codeCurrent;
    }
    //ajouter les exigences au début
    QList<UV*> ex=dem->getExigences();
    for(int j=0; j<ex.length();j++){
        codeCurrent=it.current().getCode();
        mapUV[1]=codeCurrent;

    }
    //ajouter les rejets à la fin
    QList<UV*> rej=dem->getRejets();
    for(int k=0; k<rej.length();k++){
        codeCurrent=it.current().getCode();
        mapUV[4]=codeCurrent;
    }
*/
    return mapUV;
}



void AlgoCompletionSimple::createSolution(const Dossier *d){
    int i=0;//1 dans l'algo
    //recupere l'année en cours
    time_t now = time(NULL);
    struct tm * tm = localtime(&now);
    anneeCurrent= tm_year;
    QList<Inscription> solTemp=sol;
    QMessageBox::information(0, "compl","code courrant:"+ mapTriee.begin().value());
    //iterateur pour parcourir la map
    QMap<int, QString>::Iterator itMap=mapTriee.begin();
    //pairCurrent=mapTriee.Iterator

    //QString codeCurrent=itMap.value();
    while((!(d->getCursusEtu()->is_completed(&solTemp)/*toutes les règles sont validées*/))&&((itMap.value()!=mapTriee.end().value()))){
        if((itMap.key()==1/*UV obligatoire*/)||(/*UV ameliore dossier*/)){
            //créer une inscription à l'uv
            Inscription insc;

            //trouver ou l'inserer en vérifiant un semestre=max35 cred et 7 uvs

            //remplir l'objet inscription
            //ajouter à solTemp
        }
        i++;
    }
    if(/*toutes les règles ne sont validées*/){
        QMessageBox::warning(this, "Completion Dossier", "Votre dossier n'admet pas de solution, veuillez changer vos exigences et/ou preferences et/ou rejets")
    }
}






void Demande::getSemestresEtranger(){}
void Demande::setExigences(){}
void Demande::setPreferences(){}
void Demande::setRejets(){}
void Demande::setSemestresEtranger(){}

