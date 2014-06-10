#ifndef CURSED_CPP
#define CURSED_CPP

#include "CursusEditor.h"

#include <QDirModel>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QHeaderView>

using namespace GRAPHICALEDITORS;

CURSUSEditor::CURSUSEditor(Cursus* root ,QWidget *parent):QWidget(parent),rootCursus(root){

    this->setWindowTitle( QString("ADMINISTRATION : Edition des Cursus") );

    // creation des labels
    cursusLabel = new QLabel("CURSUS (Sélectionner pour voir le(s) Profil(s) associés)",this);
    profilLabel = new QLabel("PROFILS du Cursus sélectionné",this);
    regleLabel  = new QLabel("REGLES DE VALIDATION du Profil sélectionné",this);
    cursusLabel_2 = new QLabel(" \nCondition de validation d'un CURSUS :                                                              .\n - Valider le(s) PROFILS associés ET\n - Valider tous les SOUS-CURSUS",this);
    profilLabel_2 = new QLabel(" \nCondition de validation d'un PROFIL :\n - Valider toutes les REGLES DE VALIDATION associées\n ",this);
    regleLabel_2  = new QLabel(" \n \n \n                                                                                                                                                                                                                   ",this);

    // création des composants éditables
    cursusSelector = new QTreeView(this);
    profilSelector = new QListView(this);
    regleSelector  = new QTreeView(this);

    cursusAjouter         = new QPushButton("Ajouter un Sous Cursus", this);
    cursusSupprimer       = new QPushButton("Supprimer", this);
    cursusAjouterExistant = new QPushButton("Ajouter Cursus déjà existant à un autre endroit de l'arborescence", this);
    profilAjouter         = new QPushButton("+", this);
    profilSupprimer       = new QPushButton("-", this);
    regleAjouter          = new QPushButton("+", this);
    regleSupprimer        = new QPushButton("-", this);



    
/*    cursusSelector->setWindowTitle(QObject::tr("Dir View"));
    cursusSelector->resize(640, 480);
    cursusSelector->show();
*/
    // diposition des couches
    coucheV1 = new QVBoxLayout;
    coucheV1->addWidget(cursusLabel);
    coucheV1->addWidget(cursusSelector);
    coucheV1->addWidget(cursusAjouter);
    coucheV1->addWidget(cursusSupprimer);
    coucheV1->addWidget(cursusAjouterExistant);
    coucheV1->addWidget(cursusLabel_2);

    coucheV2 = new QVBoxLayout;
    coucheV2->addWidget(profilLabel);
    coucheV2->addWidget(profilSelector);
    coucheV2->addWidget(profilAjouter);
    coucheV2->addWidget(profilSupprimer);
    coucheV2->addWidget(profilLabel_2);

    coucheV3 = new QVBoxLayout;
    coucheV3->addWidget(regleLabel);
    coucheV3->addWidget(regleSelector);
    coucheV3->addWidget(regleAjouter);
    coucheV3->addWidget(regleSupprimer);
    coucheV3->addWidget(regleLabel_2);

    coucheH = new QHBoxLayout;
    coucheH->addLayout(coucheV1);
    coucheH->addLayout(coucheV2);
    coucheH->addLayout(coucheV3);

    setLayout(coucheH);

    initView();

}

void CURSUSEditor::initView(){

    cursusSelectorModel = new QStandardItemModel; 
    profilSelectorModel = new QStandardItemModel;
    regleSelectorModel = new QStandardItemModel;

    selectedCursus = rootCursus;
    selectedProfile = selectedCursus->getProfileList().at(0);

    // mise en place de l'arbre des cursus (QTreeView de droite)
    QStandardItem *itemCurs = new QStandardItem_Cursus(rootCursus->getName(),rootCursus);
    rootCursus->copyIntoQtCursusView(itemCurs);
    cursusSelectorModel->appendRow(itemCurs);

    connect(cursusSelector, SIGNAL(clicked(const QModelIndex&)), this, SLOT(clicCursusSelection(const QModelIndex&)));
    connect(profilSelector, SIGNAL(clicked(const QModelIndex&)), this, SLOT(clicProfilSelection(const QModelIndex&)));
    //connect(regleSelector , SIGNAL(clicked(const QModelIndex&)), this, SLOT(clicRegleSelection(const QModelIndex&)));

    regleSelector ->header()->hide();
    cursusSelector->header()->hide();
    cursusSelector->setModel(cursusSelectorModel);
    profilSelector->setModel(profilSelectorModel);
    regleSelector ->setModel(regleSelectorModel);

    selectedCursus->copyIntoQtProfilView(profilSelectorModel,1);//

    refresh();

}

void CURSUSEditor::refresh(){

    selectedProfile->copyIntoQtRuleView(regleSelectorModel);
 
}

void CURSUSEditor::clicCursusSelection(const QModelIndex& index){
    QStandardItem_Cursus* current = (QStandardItem_Cursus*)cursusSelectorModel->itemFromIndex(index);

    selectedCursus = current->getCursus();
    selectedProfile = selectedCursus->getProfileList().at(0);

    profilSelectorModel->clear();
    regleSelectorModel->clear();

    selectedCursus->copyIntoQtProfilView(profilSelectorModel,1);//

    refresh();
};

void CURSUSEditor::clicProfilSelection(const QModelIndex& index){
    QStandardItem_Profil* current = (QStandardItem_Profil*)profilSelectorModel->itemFromIndex(index);

    selectedProfile = current->getProfil();

    regleSelectorModel->clear();

    refresh();
};

#endif
