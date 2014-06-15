#ifndef CURSSE_CPP
#define CURSSE_CPP

#include "CursusSelector.h"
#include "feneditdoss.h"

#include <QDirModel>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QHeaderView>

using namespace GRAPHICALEDITORS;

CURSUSSelector:: CURSUSSelector(Cursus* root,fenEditDoss* parentFenetre, QWidget *parent):QWidget(parent),rootCursus(root),parentFenetre(parentFenetre){

    this->setWindowTitle( QString("ETUDIANT : Sélection des Cursus") );

    // creation des labels
    cursusLabel = new QLabel("Cursus auquels vous êtes inscrits:",this);

    // création des composants éditables
    cursusSelector = new QTreeView(this);

    cursusAjouter   = new QPushButton("Ajouter un Sous Cursus", this);
    cursusSupprimer = new QPushButton("Supprimer", this);
    ok              = new QPushButton("Confirmer", this);
    
    // diposition des couches
    couche = new QVBoxLayout;
    couche->addWidget(cursusLabel);
    couche->addWidget(cursusSelector);
    couche->addWidget(cursusAjouter);
    couche->addWidget(cursusSupprimer);
    couche->addWidget(ok);

    setLayout(couche);

    studentCursus = new Cursus_Etudiant(rootCursus);
    selectedCursus= studentCursus;
    cursusSelectorModel = new QStandardItemModel; 

    // mise en place de l'arbre des cursus (QTreeView de droite)
    QStandardItem *itemCurs = new QStandardItem_Cursus_Etudiant(studentCursus->getName(),studentCursus);

    cursusSelectorModel->appendRow(itemCurs);

    cursusSelector->header()->hide();
    cursusSelector->setModel(cursusSelectorModel);

    connect(ok            , SIGNAL(clicked()),                   parentFenetre, SLOT(lEtudiantAAjouteUnCursusetu()));
    connect(ok            , SIGNAL(clicked()),                   this         , SLOT(jeDoisMeFermer()));
    connect(cursusAjouter , SIGNAL(clicked()),                   this         , SLOT(openAdderWindow()));
    connect(cursusSelector, SIGNAL(clicked(const QModelIndex&)), this         , SLOT(clicCursusSelection(const QModelIndex&)));

}

void CURSUSSelector::clicCursusSelection(const QModelIndex& index){
    QStandardItem_Cursus_Etudiant* temp = (QStandardItem_Cursus_Etudiant*)cursusSelectorModel->itemFromIndex(index);
    selectedCursus = temp->getCursus();

};

void CURSUSSelector::openAdderWindow(){
    adder = new CURSUSAdder(selectedCursus->getCursusReference(),selectedCursus,0);
    connect(adder, SIGNAL(sorryIAmClosing()), this, SLOT(editionFinished()));
    adder->show();
};

void CURSUSSelector::editionFinished(){
    QStandardItem *itemCurs = new QStandardItem_Cursus(studentCursus->getName(),studentCursus);
    cursusSelectorModel->clear();
    try{
        studentCursus->copyIntoQtCursusView(itemCurs);
    }catch(CursusNullPtrException e){
        QMessageBox::warning(0," ",e.getInfo().toStdString().c_str());
    }
    cursusSelectorModel->appendRow(itemCurs);
    cursusSelector->expandAll();
};











CURSUSAdder::CURSUSAdder(Cursus* current ,Cursus_Etudiant* studentCursus,QWidget *parent):QWidget(parent),currentCursus(current),studentCursus(studentCursus){

    this->setWindowTitle( QString("Ajouter un Cursus") );

    // creation des labels
    SOUScursusLabel = new QLabel("Choisir votre cursus",this);

    // création des composants éditables
    SOUScursusSelector = new QListView(this);
    
    // diposition des couches
    couche = new QVBoxLayout;
    couche->addWidget(SOUScursusLabel);
    couche->addWidget(SOUScursusSelector);

    setLayout(couche);

    SOUScursusSelectorModel = new QStandardItemModel;

    QList<Cursus*> list = currentCursus->getSOUSCursusList();
    for(int i =0; i<list.length() ;i++){
        bool studentHasAlready=false;
        const char* name = list.at(i)->getName();
        for(int j = 0; j<studentCursus->getSOUSCursusList().length() ; j++){
            if(!strcmp(studentCursus->getSOUSCursusList().at(j)->getName(),name)){
                studentHasAlready=true;
            }
        }
        if(!studentHasAlready){
            QStandardItem *item = new QStandardItem_Cursus(name,list.at(i));
            SOUScursusSelectorModel->appendRow(item);
        }
    }

    connect(SOUScursusSelector, SIGNAL(clicked(const QModelIndex&)), this, SLOT(clicCursusSelection(const QModelIndex&)));
 
    SOUScursusSelector->setModel(SOUScursusSelectorModel);

}

void CURSUSAdder::clicCursusSelection(const QModelIndex& index){
    QStandardItem_Cursus* temp = (QStandardItem_Cursus*)SOUScursusSelectorModel->itemFromIndex(index);

    Cursus* selectedCursus = temp->getCursus();
    Cursus_Etudiant* SOUSstudentCursus;
    studentCursus->addSousCursus(SOUSstudentCursus=new Cursus_Etudiant(selectedCursus));

    QList<Cursus*> list = selectedCursus->getSOUSCursusList();
    if(list.length()==0){
        this->sorryIAmClosing();
        this->close();
    }else{
        UNDERadder = new CURSUSAdder(selectedCursus,SOUSstudentCursus,0);
        connect(UNDERadder, SIGNAL(sorryIAmClosing()), this, SLOT(closeWindow()));
        UNDERadder->show();
    }
};

void CURSUSAdder::closeWindow(){
    this->sorryIAmClosing();
    this->close();
}
#endif
