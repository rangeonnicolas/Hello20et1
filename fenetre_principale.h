#ifndef FENETRE_PRINCIPALE_H
#define FENETRE_PRINCIPALE_H


#include<QApplication>
#include<QMainWindow>
#include<QInputDialog>
#include<QString>

#include "inscription.h"
#include "dossier.h"
#include "dossierXMLreader.h"
#include "uvDataBaseConnect.h"

class fenetrePrincipale :public QMainWindow{
    Q_OBJECT
    INSCRIPTIONS::Cursus* rootCursus;//Arborescence de tous les cursus possibles éditable par l'administration (!il ne s'agit pas du cursus d'un étudiant en particulier!)
    QApplication* app;
    DATABASE::UvDbConn* uvdb;
public :
    static unsigned int* donnees; //1=DB  2=dur
explicit fenetrePrincipale(QWidget * parent = 0,QApplication* app = 0);
signals:

public slots:
    void chargerUV();
    void chargerCatalogue();
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
    void complet();
};

#endif // FENETRE_PRINCIPALE_H
