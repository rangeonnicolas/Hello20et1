#include "fenetre_principale.h"
#include "feneditdoss.h"
#include "dossierXMLreader.h"
#include "CursusEditor.h"
#include "dataBaseB.h"
#include "choixuv.h"
#include "fencompletion.h"
#include "uvDataBaseConnect.h"

#include<QMenuBar>
#include<QFileDialog>
#include<QString>
#include<QMessageBox>
#include<QXmlStreamReader>

using namespace INSCRIPTIONS;

fenetrePrincipale::fenetrePrincipale(QWidget*parent,QApplication* app):QMainWindow(parent),rootCursus(UnpersistentDataBaseB::getSavedAdministrationCursusTree()),app(app),uvdb(new DATABASE::UvDbConn(app)){
    setWindowTitle("Fenetre principale");
    QMenu*mFichier = menuBar()->addMenu("&Fichier");
    QAction*Quitter=mFichier->addAction("&Quitter");

    QMenu*mUVs = menuBar()->addMenu("&UVs");
    QAction*ConsulterUV=mUVs->addAction("&Consulter/Editer");
    mUVs->addSeparator();
    QAction*AjouterUV=mUVs->addAction("&Ajout/Suppression UV");
    QAction*EditerPort=mUVs->addAction("&Editer Portée");
    QAction*EditerTypeCred=mUVs->addAction("&Editer Types Crédits");

    QMenu*mCursus = menuBar()->addMenu("&Cursus");

    QAction*EditerCursus=mCursus->addAction("&Editer");


    QMenu*mDossier = menuBar()->addMenu("&Dossier");
    QAction*Ouvrir=mDossier->addAction("&Ouvrir");
    QAction*Nouveau=mDossier->addAction("&Nouveau");


    // connections
    connect(Quitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ConsulterUV, SIGNAL(triggered()),this,SLOT(chargerCatalogue()));

    connect(AjouterUV, SIGNAL(triggered()),this,SLOT(ajouterUV()));
    connect(EditerPort, SIGNAL(triggered()),this,SLOT(EditerPortee()));
    connect(EditerTypeCred, SIGNAL(triggered()),this,SLOT(EditerTypeCredits()));

    connect(EditerCursus, SIGNAL(triggered()),this,SLOT(editCur()));

    connect(Ouvrir, SIGNAL(triggered()),this,SLOT(ouvrir()));
    connect(Nouveau, SIGNAL(triggered()),this,SLOT(nouveau()));


}


void fenetrePrincipale::chargerCatalogue(){
    choixUV* fenetre= new choixUV(this);
    setCentralWidget(fenetre);
}
void fenetrePrincipale::chargerDossier(){}
void fenetrePrincipale::creerDossier(){}
void fenetrePrincipale::ajouterUV(){}
void fenetrePrincipale::EditerPortee(){}
void fenetrePrincipale::EditerTypeCredits(){}


void fenetrePrincipale::chargerUV(){
    uvdb->connect();
    uvdb->show();
}

void fenetrePrincipale::editCur(){
    using namespace GRAPHICALEDITORS;

    CURSUSEditor* fenetre=new CURSUSEditor(rootCursus, this);
    setCentralWidget(fenetre);

}


void fenetrePrincipale::ouvrir(){
    //chargement du dossier
    try
    {
        QString path="../Ressources/";
        Dossier& doss=Dossier::getInstance();
        //QMessageBox::warning(this,"chargement fichier xml", "getInstance fait");
        QString chemin = QFileDialog::getOpenFileName();
        doss.setFile(chemin);
       // QMessageBox::warning(this,"chargement fichier xml", "ouverture du fichier fait"+chemin);

        XmlStreamReader reader(&doss,rootCursus);
        reader.readFile(chemin);
        QMessageBox::warning(this,"fonction load()", "fin readFile");
        //ouverture de la fenetre d'edition de dossier
        fenEditDoss* fenetre= new fenEditDoss(&doss,rootCursus,this);
        setCentralWidget(fenetre);
    } catch(UTProfilerException e){
        QMessageBox::warning(this, "Chargement Dossier", "Erreur lors du chargement du dossier (non valide ?)");
      }


}
void fenetrePrincipale::nouveau(){
    Dossier& doss=Dossier::getInstance();
    fenEditDoss* fenetre= new fenEditDoss(&doss,rootCursus,this);
    setCentralWidget(fenetre);

}


