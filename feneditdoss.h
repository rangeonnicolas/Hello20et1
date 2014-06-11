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

public:
    explicit fenEditDoss(Dossier* doss, QWidget *parent = 0);
    ~fenEditDoss();

private:
    Ui::fenEditDoss *ui;

public slots:
    //  void validerDossier(Dossier *doss, QList<Inscription>& listI, QList<Equivalence>& listE, QList<Cursus>& listC);
        void enregistrerLogin(QString log);
        void ajouterEtape3(QList<Inscription>& listI);
        void ajouterEtape4(QList<Equivalence>& listE);
       // void openCurs();
private slots:

};

#endif // FENEDITDOSS_H
