#ifndef FENETRE_PRINCIPALE_H
#define FENETRE_PRINCIPALE_H


#include<QApplication>
#include<QMainWindow>
#include<QInputDialog>
#include<QString>

#include "dossier.h"
#include "class_q1.h"


class fenetrePrincipale :public QMainWindow{
    Q_OBJECT
public :
explicit fenetrePrincipale(QWidget * parent = 0);
signals:

public slots:
    void chargerUV();
    void chargerDossier();
    void creerDossier();
    void ajouterUV();
    void supprimerUV();
    void visuCur();
    void editCur();
    void ajoutCur();
    void supprCur();
    void ouvrir();
    void nouveau();
};

#endif // FENETRE_PRINCIPALE_H
