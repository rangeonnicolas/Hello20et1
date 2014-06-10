#ifndef CURSSE_CPP
#define CURSSE_CPP

#include "CursusSelector.h"

#include <QDirModel>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QHeaderView>

using namespace GRAPHICALEDITORS;

CURSUSSelector::CURSUSSelector(Cursus* root ,QWidget *parent):QWidget(parent),rootCursus(root){

    this->setWindowTitle( QString("ETUDIANT : Sélection des Cursus") );

    // creation des labels
    cursusLabel = new QLabel("Cursus auquels vous êtes inscrits:",this);

    // création des composants éditables
    cursusSelector = new QTreeView(this);

    cursusAjouter   = new QPushButton("Ajouter un Sous Cursus", this);
    cursusSupprimer = new QPushButton("Supprimer", this);
    
    // diposition des couches
    couche = new QVBoxLayout;
    couche->addWidget(cursusLabel);
    couche->addWidget(cursusSelector);
    couche->addWidget(cursusAjouter);
    couche->addWidget(cursusSupprimer);

    setLayout(couche);

    studentCursus = new Cursus_Etudiant(rootCursus);
    selectedCursus= studentCursus;
    cursusSelectorModel = new QStandardItemModel; 

    // mise en place de l'arbre des cursus (QTreeView de droite)
    QStandardItem *itemCurs = new QStandardItem_Cursus_Etudiant(studentCursus->getName(),studentCursus);
    //rootCursus->copyIntoQtCursusView(itemCurs);
    cursusSelectorModel->appendRow(itemCurs);

    //connect(cursusSelector, SIGNAL(clicked(const QModelIndex&)), this, SLOT(clicCursusSelection(const QModelIndex&)));
    //connect(profilSelector, SIGNAL(clicked(const QModelIndex&)), this, SLOT(clicProfilSelection(const QModelIndex&)));
    //connect(regleSelector , SIGNAL(clicked(const QModelIndex&)), this, SLOT(clicRegleSelection(const QModelIndex&)));

    cursusSelector->header()->hide();
    cursusSelector->setModel(cursusSelectorModel);

    connect(cursusAjouter , SIGNAL(clicked()),                   this, SLOT(openAdderWindow()));
    connect(cursusSelector, SIGNAL(clicked(const QModelIndex&)), this, SLOT(clicCursusSelection(const QModelIndex&)));
 
 //    selectedCursus->copyIntoQtProfilView(profilSelectorModel,1);//


}

void CURSUSSelector::clicCursusSelection(const QModelIndex& index){
    QStandardItem_Cursus_Etudiant* temp = (QStandardItem_Cursus_Etudiant*)cursusSelectorModel->itemFromIndex(index);
    selectedCursus = temp->getCursus();

};

void CURSUSSelector::openAdderWindow(){
    //std::cout<<selectedCursus->getSOUSCursusList().at(0)->getName();
    adder = new CURSUSAdder(selectedCursus->getCursusReference(),selectedCursus,0);
    connect(adder, SIGNAL(sorryIAmClosing()), this, SLOT(editionFinished()));
    adder->show();
};

void CURSUSSelector::editionFinished(){
    QStandardItem *itemCurs = new QStandardItem_Cursus(studentCursus->getName(),studentCursus);
    cursusSelectorModel->clear();
    studentCursus->copyIntoQtCursusView(itemCurs);
    cursusSelectorModel->appendRow(itemCurs);
    cursusSelector->expandAll();
};











CURSUSAdder::CURSUSAdder(Cursus* current ,Cursus_Etudiant* studentCursus,QWidget *parent):QWidget(parent),currentCursus(current),studentCursus(studentCursus){

    this->setWindowTitle( QString("Ajouter un Cursus") );

    // creation des labels
    SOUScursusLabel = new QLabel("Choisir votre cursus",this);

    // création des composants éditables
    SOUScursusSelector = new QListView(this);

    //ok = new QPushButton("Ajouter", this);
    //annuler = new QPushButton("Annuler", this);
    
    // diposition des couches
    couche = new QVBoxLayout;
    couche->addWidget(SOUScursusLabel);
    couche->addWidget(SOUScursusSelector);
    //couche->addWidget(ok);
    //couche->addWidget(annuler);

    setLayout(couche);

    SOUScursusSelectorModel = new QStandardItemModel;

    QList<Cursus*> list = currentCursus->getSOUSCursusList();
    for(int i =0; i<list.length() ;i++){
        //std::cout<<"\nboucle";
        bool studentHasAlready=false;
        const char* name = list.at(i)->getName();
        for(int j = 0; j<studentCursus->getSOUSCursusList().length() ; j++){
            std::cout<<"\nname="<<name<<" cursusQueLEtudiantADeja="<<studentCursus->getSOUSCursusList().at(j)->getName();
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
 
    //SOUScursusSelector->header()->hide();
    SOUScursusSelector->setModel(SOUScursusSelectorModel);


//    selectedCursus->copyIntoQtProfilView(profilSelectorModel,1);//


}

void CURSUSAdder::clicCursusSelection(const QModelIndex& index){
    QStandardItem_Cursus* temp = (QStandardItem_Cursus*)SOUScursusSelectorModel->itemFromIndex(index);

    Cursus* selectedCursus = temp->getCursus();
    Cursus_Etudiant* SOUSstudentCursus;
    studentCursus->addSousCursus(SOUSstudentCursus=new Cursus_Etudiant(selectedCursus));
    //studentCursus->addSousCursus(SOUSstudentCursus=selectedCursus->cloneRootElement());

    QList<Cursus*> list = selectedCursus->getSOUSCursusList();
    if(list.length()==0){
        this->sorryIAmClosing();
        this->close();
    }else{
        UNDERadder = new CURSUSAdder(selectedCursus,SOUSstudentCursus,0);
        connect(UNDERadder, SIGNAL(sorryIAmClosing()), this, SLOT(closeWindow()));
        UNDERadder->show();
    }

/*    selectedProfile = selectedCursus->getProfileList().at(0);

    profilSelectorModel->clear();
    regleSelectorModel->clear();

    selectedCursus->copyIntoQtProfilView(profilSelectorModel,1);//

    refresh();*/
};

void CURSUSAdder::closeWindow(){
    this->sorryIAmClosing();
    this->close();
}
#endif
