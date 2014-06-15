#include "completion.h"
using namespace INSCRIPTIONS;



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


QList<Inscription>& AlgoCompletionSimple::enregNouvInsc(QList<Inscription> solTemp, QString code){
    Inscription insc;
    Semestre semTemp;


    //prendre dans vrai dossier, le semestre le plus elevé
    Saison saisonMax=Printemps;
    unsigned int anneeMax=0;
    for(int j=0;j<solTemp.length();j++){
        if(solTemp.at(j).getSemestre().getAnnee()>anneeMax){
            anneeMax=solTemp.at(j).getSemestre().getAnnee();
            if(solTemp.at(j).getSemestre().getSaison()==Automne)
                saisonMax=Automne;
        }
    }


    //tester tous les semestres à partir de celui-là
    unsigned int bonSemestre=0;
    while(bonSemestre==0){
        //faire semestre +1
        if (saisonMax==Printemps)
            saisonMax=Automne;
        else{
            anneeMax++;
            saisonMax=Printemps;
        }
        semTemp.setSaison(saisonMax);
        semTemp.setAnnee(anneeMax);

        //comptabiliser tous les UVs du semestre
        unsigned int nbUvs=0;
        for(int k=0;k<solTemp.length();k++){
            //comptabiliser les uvs
            if((solTemp.at(k).getSemestre().getAnnee()==semTemp.getAnnee())&&(solTemp.at(k).getSemestre().getSaison()==semTemp.getSaison())){
                nbUvs++;
            }
        }

        //si place ->bonSemestre=1
        if(nbUvs<7)
            bonSemestre=1;

    }


    //remplir l'objet inscription
    insc.setResultat(AF);
    const UV* ptr;
    UVManager& manag=UVManager::getInstance();
    ptr=manag.getPtrUV(code);
    insc.setUv(ptr);
    insc.setSemestre(semTemp);
    //ajouter à solTemp
    solTemp.append(insc);


return solTemp;
}

void AlgoCompletionSimple::createSolution(const Dossier *d){
    QList<Inscription> solTemp=sol;
    QMessageBox::information(0, "compl","code courrant:"+ mapTriee.begin().value());
    //iterateur pour parcourir la map
    QMap<int, QString>::Iterator itMap=mapTriee.begin();



    //QString codeCurrent=itMap.value();


    Inscription insc;
    int fin=0;
    float pourcentageMax=0;
    QString UvAFaire;
    QMap<int, QString>::Iterator itUV;
    while((d->getCursusEtu()->completion_percentage(&solTemp))<100){
          while(itMap.value()!=mapTriee.end().value()){
              if((itMap.key())==1){
                     QMessageBox::warning(0,"hui","ih");
                      solTemp=enregNouvInsc(solTemp,itMap.value());
              }
          }
    }

    while(((d->getCursusEtu()->completion_percentage(&solTemp))<100/*toutes les règles sont validées*/)&&(fin=0)){

        pourcentageMax=0;
        itUV=mapTriee.begin();
        fin=1;
        //Trouver l'uv qui fait le plus augmenter le pourcentage
        while(itUV.value()!=mapTriee.end().value()){
            QList<Inscription> solTempTemp=solTemp;
            UVManager& manag=UVManager::getInstance();
            const UV* ptr;
            ptr=manag.getPtrUV(itUV.value());
            insc.setUv(ptr);
            solTempTemp.append(insc);
            if((d->getCursusEtu()->completion_percentage(&solTempTemp))>pourcentageMax){
                UvAFaire=itUV.value();
                fin=0;
            }
        }
        std::cout<<"le dossier est complété à "<<d->getCursusEtu()->completion_percentage(&solTemp)<< "Luv qui augmente le plus de pourcentage de completion est : "<<UvAFaire.toStdString();
        solTemp=enregNouvInsc(solTemp,UvAFaire);
        std::cout<<"Le dossier est maintenant complété à "<<d->getCursusEtu()->completion_percentage(&solTemp);

    }

    if((d->getCursusEtu()->completion_percentage(&solTemp))<100/*toutes les règles ne sont validées*/){
        QMessageBox::warning(0, "Completion Dossier", "Votre dossier n'admet pas de solution, veuillez changer vos exigences et/ou preferences et/ou rejets");
    }
    else{
        unsigned int i=d->getMapSol().lastKey();
        //d->setMapSolutions(++i,solTemp);
    }
}






void Demande::getSemestresEtranger(){}
void Demande::setExigences(){}
void Demande::setPreferences(){}
void Demande::setRejets(){}
void Demande::setSemestresEtranger(){}

