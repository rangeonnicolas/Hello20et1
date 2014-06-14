#ifndef COMPLETION_H
#define COMPLETION_H

#include <QList>
#include <QMap>
#include "UV.h"
#include "dossier.h"

using namespace UV_credits_types;
using namespace question3;

class SemestreEtranger{
    Semestre semestre;
    unsigned int creditsMin;
    unsigned int creditsMax;

public:
    SemestreEtranger(Semestre s, unsigned int credMin, unsigned int credMax):semestre(s), creditsMin(credMin), creditsMax(credMax){}

};
class Demande;

class Completion{

public:
    virtual void algo(Demande* dem)=0;
};

class AlgoCompletionSimple: public Completion{
    QMap<UV, int> mapTriee;
    QList<Inscription> sol;//var pour stocker copie puis sol

public:

    QList<Inscription> copieDossier(const Dossier *d);
    QMap<UV, int>& triUVs(const Dossier *d, const Demande *dem);
    void createSolution();
    void algo(Demande* dem){
        Demande* demande=dem;
        /*implementation*/
        Dossier& dossier=Dossier::getInstance();
        sol=copieDossier(&dossier);

        mapTriee=triUVs(&dossier, demande);
        createSolution();
    }
};

class Demande
{
    QList<UV*> exigences;
    QList<UV*> preferences;
    QList<UV*> rejets;
    QList<SemestreEtranger> semestres_etranger;
    Completion* m_completion;


public:
    Demande(){}
    QList<UV*> getExigences()const{return exigences;}
    QList<UV*> getPreferences()const{return preferences;}
    QList<UV*> getRejets()const{return rejets;}
    void getSemestresEtranger();
    void setExigences();
    void setPreferences();
    void setRejets();
    void setSemestresEtranger();
    void setCompletion(Completion* c){m_completion=c;}
    void chercherSolution(){m_completion->algo(this);}//methode qui appelle la completion
};



#endif // COMPLETION_H
