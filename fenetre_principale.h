#ifndef FENETRE_PRINCIPALE_H
#define FENETRE_PRINCIPALE_H


#include<QApplication>
#include<QMainWindow>
#include<QInputDialog>
#include<QString>

#include "dossier.h"
#include "uvDataBaseConnect.h"



class fenetrePrincipale :public QMainWindow{
    Q_OBJECT
    question3::Cursus* rootCursus;//Arborescence de tous les cursus possibles éditable par l'administration (!il ne s'agit pas du cursus d'un étudiant en particulier!)
    //TODO NICO: renomer le nom du namespace question3
    QApplication* app;
    DATABASE::UvDbConn* uvdb;
public :
explicit fenetrePrincipale(QWidget * parent = 0,QApplication* app = 0);
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
