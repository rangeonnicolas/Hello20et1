#ifndef FENEDITDOSS_H
#define FENEDITDOSS_H

#include <QDialog>
#include <QtGui>
#include <QtXml>
#include <QWidget>

#include "dossier.h"
#include "CursusSelector.h"
#include "fencompletion.h"

using namespace INSCRIPTIONS;

namespace Ui {
class fenEditDoss;
}

class fenEditDoss : public QDialog
{
    Q_OBJECT



private:
    Ui::fenEditDoss *ui;
    //variables locales permettant d'enregistrer les modifications (car si appuie sur annuler il ne faut pas que ce soit enregistré dans dossier)
    Dossier* d;
    QString login;
    GRAPHICALEDITORS::CURSUSSelector* SOUSfenetre;
    QList<Inscription> listInscription;
    QList<Equivalence> listE;
    QList<Cursus> listC;
    Cursus* rootCursus;
public:
    explicit fenEditDoss(Dossier* doss, Cursus* rootCursus, QWidget *parent = 0);
    ~fenEditDoss();
    void setLogin(QString log){login=log;}
    void setInscription(Inscription i){listInscription.push_back(i);}
    void setEqui(Equivalence e){listE.push_back(e);}
    void setCursus();
public slots:
       void validerDossier();
        void setOuverture();
        void enregistrerLogin();
        void ajouterEtape3();
        void ajouterEtape4();
        void openCurs();
        void lEtudiantAAjouteUnCursusetu();
        void complet();
private slots:

};

#endif // FENEDITDOSS_H
