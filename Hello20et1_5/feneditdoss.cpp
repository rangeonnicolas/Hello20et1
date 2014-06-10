


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

         //connect(Ui::fenEditDoss::boutonOK, SIGNAL(clicked()),this,SLOT(validerDossier()));


    }

void fenEditDoss::validerDossier(){
    //enregistrer les modifications dans l'objet dossier

}

fenEditDoss::~fenEditDoss()
    {
        delete ui;
    }


