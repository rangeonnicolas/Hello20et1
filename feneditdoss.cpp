


#include "feneditdoss.h"
#include "ui_feneditdoss.h"
#include "dossier.h"

#include <QMainWindow>
#include <QObject>
using namespace question3;

fenEditDoss::fenEditDoss(Dossier *doss, QWidget *parent) : QDialog(parent), ui(new Ui::fenEditDoss)
    {
        ui->setupUi(this);
        setWindowTitle("Fenetre Edition Dossier");

        //variables locales permettant d'enregistrer les modifications (car si appuie sur annuler il ne faut pas que ce soit enregistré dans dossier)
        QString login;
        QList<Inscription> listInscription;
        QList<Equivalence> listE;
        QList<Cursus> listC;

        // au clic de valider de l'etape1
        connect(ui->pushButton_Valider,SIGNAL(clicked()),this,SLOT(enregistrerLogin(login)));
        // auc clic de choisir de l'etape 2
       // connect(ui->pushButton_choisir,SIGNAL(clicked()),this,SLOT(openCurs()));
        //au clic de ajouter de l'étape 3 on enregistre l'inscription dans une liste d'inscription créée localement et on affiche le code dans la view à droite
        connect(ui->pushButton_ajouterEtape3,SIGNAL(clicked()),this,SLOT(ajouterEtape3(listInscription)));

        // au clic de ajouter de l'étape 4 on enregistre dans liste locale
        connect(ui->pushButton_ajouter4,SIGNAL(clicked()),this,SLOT(ajouterEtape4(listE)));

        //au clic qur le bouton ok, les listes locales et l'arbre de cursus sont enregistrées dans le dossier
        // connect(ui->boutonOK, SIGNAL(clicked()),this,SLOT(validerDossier(doss,listInscription, listE, listC)));

    }

/*
void fenEditDoss::validerDossier(Dossier* doss, QList<Inscription>& listI, QList<Equivalence>& listE, QList<Cursus>& listC){
    //au clic qur le bouton ok, les listes locales et l'arbre de cursus sont enregistrées dans le dossier
    doss->setInscr(listI);
    doss->setEqui(listE);
    doss->setCursus(listC);
}
*/
/*void fenEditDoss::openCurs(){
    GRAPHICALEDITORS::CURSUSEditor* fenetre= new GRAPHICALEDITORS::CURSUSEditor(this);
    setCentralWidget(fenetre);
}*/

void fenEditDoss::ajouterEtape3(QList<Inscription> &listI){
    //au clic de ajouter de l'étape 2 on enregistre l'inscription dans une liste d'inscription créée localement et on affiche le code dans la view à droite
    Inscription i;
    Semestre s;
    if(ui->radioButton_automne->isChecked())
        s.setSaison(Automne);
    else
        if(ui->radioButton_printemps->isChecked())
            s.setSaison(Printemps);
    s.setAnnee(ui->annee->value());
    i.setSemestre(s);

    i.setResultat(StringToNote(ui->comboBoxRes->currentText()));

    //i.setUv(); uv est un pointeur
    //retrouver cette uv dans uvs de UVManager
    /*while(uvs[iterator]->code!=ui->comboBox_code->currentText())
        iterator++;
    i.setUv(uvs[iterator]);
*/
    listI.push_back(i);


    //affiche
   // ui->listUvsAjoutes->addItem(uvs[iterator]->code);
}

void fenEditDoss::ajouterEtape4(QList<Equivalence>& listE){
    Equivalence e;
    Credits c;
    c.setNbCredits(ui->spinBox_nb->value());
    //c.setType(StringToCategorie(ui->comboBox_cat->currentText()));
    e.setCredits(c);
    Portee p;
    p.setLibelle(ui->comboBox_portee->currentText());
    e.setPortee(p);

    listE.push_back(e);
}

void fenEditDoss::enregistrerLogin(QString log){
    log=ui->lineEdit->text();
}

fenEditDoss::~fenEditDoss()
    {
        delete ui;
    }


