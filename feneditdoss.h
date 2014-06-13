#ifndef FENEDITDOSS_H
#define FENEDITDOSS_H

#include <QDialog>
#include <QtGui>
#include <QtXml>
#include <QWidget>

#include "dossier.h"

using namespace question3;

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
    QList<Inscription> listInscription;
    QList<Equivalence> listE;
    QList<Cursus> listC;
public:
    explicit fenEditDoss(Dossier* doss, QWidget *parent = 0);
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
       // void openCurs();
private slots:

};

#endif // FENEDITDOSS_H
