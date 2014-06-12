#include "fenetre_principale.h"
#include "feneditdoss.h"
#include "CursusEditor.h"
#include "dataBaseB.h"
#include "choixuv.h"


#include "uvDataBaseConnect.h"


#include<QMenuBar>
#include<QFileDialog>
#include<QString>
#include<QMessageBox>

fenetrePrincipale::fenetrePrincipale(QWidget*parent,QApplication* app):QMainWindow(parent),rootCursus(dataBaseB::getSavedAdministrationCursusTree()),app(app),uvdb(new DATABASE::UvDbConn(app)){
    setWindowTitle("Fenetre principale");
    QMenu*mFichier = menuBar()->addMenu("&Fichier");
    QAction*Quitter=mFichier->addAction("&Quitter");

    QMenu*mUVs = menuBar()->addMenu("&UVs");
    QAction*ConsulterUV=mUVs->addAction("&Consulter/Editer");
    mUVs->addSeparator();
    QAction*AjouterUV=mUVs->addAction("&Ajout UV");
    QAction*SupprimerUV=mUVs->addAction("&Supprimer UV");

    QMenu*mCursus = menuBar()->addMenu("&Cursus");
    QAction*VisualiserCursus=mCursus->addAction("&Visualiser");
    mUVs->addSeparator();
    QAction*EditerCursus=mCursus->addAction("&Editer");
    QAction*AjouterCursus=mCursus->addAction("&Ajouter");
    QAction*SupprimerCursus=mCursus->addAction("&Supprimer");

    QMenu*mDossier = menuBar()->addMenu("&Dossier");
    QAction*Ouvrir=mDossier->addAction("&Ouvrir");
    QAction*Nouveau=mDossier->addAction("&Nouveau");





    // connections
    connect(Quitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ConsulterUV, SIGNAL(triggered()),this,SLOT(chargerCatalogue()));

    connect(AjouterUV, SIGNAL(triggered()),this,SLOT(ajouterUV()));
    connect(SupprimerUV, SIGNAL(triggered()),this,SLOT(supprimerUV()));
    connect(VisualiserCursus, SIGNAL(triggered()),this,SLOT(visuCur()));
    connect(EditerCursus, SIGNAL(triggered()),this,SLOT(editCur()));
    connect(AjouterCursus, SIGNAL(triggered()),this,SLOT(ajoutCur()));
    connect(SupprimerCursus, SIGNAL(triggered()),this,SLOT(supprCur()));
    connect(Ouvrir, SIGNAL(triggered()),this,SLOT(ouvrir()));
    connect(Nouveau, SIGNAL(triggered()),this,SLOT(nouveau()));






}//fin constructeur de fenetrePrincipale





//fonctions de la classe fonctionPrincipale


//fonctions de la classe fenetrePrincipale
void fenetrePrincipale::chargerCatalogue(){
    choixUV* fenetre= new choixUV(this);
    setCentralWidget(fenetre);
};
void fenetrePrincipale::chargerDossier(){};
void fenetrePrincipale::creerDossier(){};
void fenetrePrincipale::ajouterUV(){};
void fenetrePrincipale::supprimerUV(){};
void fenetrePrincipale::visuCur(){};

void fenetrePrincipale::chargerUV(){
    uvdb->connect();
    uvdb->show();
}

void fenetrePrincipale::editCur(){
    using namespace GRAPHICALEDITORS;

    CURSUSEditor* fenetre=new CURSUSEditor(rootCursus, this);
    setCentralWidget(fenetre);

}
void fenetrePrincipale::ajoutCur(){}
void fenetrePrincipale::supprCur(){}

using namespace question3;
//using namespace Ui;


void fenetrePrincipale::ouvrir(){
    //chargement du dossier
    try
    {
        QString path="../Ressources/";
        Dossier& doss=Dossier::getInstance();
        //QMessageBox::warning(this,"chargement fichier xml", "getInstance fait");
        QString chemin = QFileDialog::getOpenFileName();
        doss.setFile(chemin);
        //QMessageBox::warning(this,"chargement fichier xml", "ouverture du fichier fait"+chemin);

        //QMessageBox::warning(this,"fonction load()", "fonction load() faite");
        XmlStreamReader reader(&doss);
        reader.readFile(chemin);
        //ouverture de la fenetre d'edition de dossier
        fenEditDoss* fenetre= new fenEditDoss(&doss,this);
        setCentralWidget(fenetre);
    } catch(UTProfilerException e){
        QMessageBox::warning(this, "Chargement Dossier", "Erreur lors du chargement du dossier (non valide ?)");
      }


}
void fenetrePrincipale::nouveau(){
    Dossier& doss=Dossier::getInstance();
    fenEditDoss* fenetre= new fenEditDoss(&doss,this);
    setCentralWidget(fenetre);

}
