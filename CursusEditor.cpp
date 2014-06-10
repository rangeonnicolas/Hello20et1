#include "CursusEditor.h"

using namespace GRAPHICALEDITORS;

CURSUSEditor::CURSUSEditor(QList<Cursus*> cl, QWidget *parent):QWidget(parent),list(cl){

    this->setWindowTitle( QString("ADMINISTRATION : Edition des Cursus") );

    // creation des labels
    cursusLabel = new QLabel("CURSUS (Sélectionner pour voir le(s) Profil(s) associés)",this);
    profilLabel = new QLabel("PROFILS du Cursus sélectionné",this);
    regleLabel  = new QLabel("REGLES DE VALIDATION du Profil sélectionné",this);
    cursusLabel_2 = new QLabel(" \nCondition de validation d'un CURSUS :\n - Valider le(s) PROFILS associés ET\n - Valider tous les SOUS-CURSUS",this);
    profilLabel_2 = new QLabel(" \nCondition de validation d'un CURSUS :\n - Valider toutes les REGLES DE VALIDATION associées\n ",this);
    regleLabel_2  = new QLabel(" \n \n \n ",this);

    // création des composants éditables
    cursusSelector = new QTreeView(this);
    profilSelector = new QListView(this);
    regleSelector  = new QListView(this);

    cursusAjouter   = new QPushButton("Ajouter un Sous Cursus", this);
    cursusSupprimer = new QPushButton("Supprimer", this);
    profilAjouter   = new QPushButton("+", this);
    profilSupprimer = new QPushButton("-", this);
    regleAjouter    = new QPushButton("+", this);
    regleSupprimer  = new QPushButton("-", this);

    // diposition des couches
    coucheV1 = new QVBoxLayout;
    coucheV1->addWidget(cursusLabel);
    coucheV1->addWidget(cursusSelector);
    coucheV1->addWidget(cursusAjouter);
    coucheV1->addWidget(cursusSupprimer);
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
}

