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

class Completion{

public:
    Completion();
    virtual void algo()=0;
};

class AlgoCompletionSimple: public Completion{
    QMap<UV*, int> mapTriee;
    QList<Inscription> sol;//var pour stocker copie puis sol
public:
    void copieDossier(Dossier& d);
    QMap<UV*, int> triUVs(QList<UV*> ex, QList<UV*> pref, QList<UV*> rej);
    void algo(){/*implementation*/}
};

class Demande
{
    QList<UV*> exigences;
    QList<UV*> preferences;
    QList<UV*> rejets;
    QList<SemestreEtranger> semestres_etranger;
    Completion* m_completion;


public:
    Demande():exigences(NULL), preferences(0), rejets(0), semestres_etranger(0){}
    void getExigences();
    void getPreferences();
    void getRejets();
    void getSemestresEtranger();
    void setExigences();
    void setPreferences();
    void setRejets();
    void setSemestresEtranger();
    void setCompletion(){m_completion->algo();}//methode qui appelle la completion
};



#endif // COMPLETION_H
