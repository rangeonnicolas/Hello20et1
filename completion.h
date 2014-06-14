#ifndef COMPLETION_H
#define COMPLETION_H

#include <QList>
#include <QMap>
#include "UV.h"

using namespace UV_credits_types;

class SemestreEtranger{
    Semestre semestre;
    unsigned int creditsMin;
    unsigned int creditsMax;

public:
    SemestreEtranger(Semestre s, unsigned int credMin, unsigned int credMax):semestre(s), creditsMin(credMin), creditsMax(credMAx)

};


class Demande
{
    QList<UV*> exigences;
    QList<UV*> preferences;
    QList<UV*> rejets;
    QList<SemestreEtranger> semestres_etranger;

public:
    Demande();
    void getExigences();
    void getPreferences();
    void getRejets();
    void getSemestresEtranger();
    void setExigences();
    void setPreferences();
    void setRejets();
    void setSemestresEtranger();
};

class AlgoCompletion1{
    QMap<UV*, int> mapTriee;
    QList<Inscription> sol;//var pour stocker copie puis sol
public:
    void copieDossier(Dossier& d);
    QMap<UV*, int> triUVs(QList<UV*> ex, QList<UV*> pref, QList<UV*> rej);
};

#endif // COMPLETION_H
