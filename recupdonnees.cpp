#include "recupdonnees.h"
#include "ui_recupdonnees.h"
#include "fenetre_principale.h"

recupDonnees::recupDonnees(unsigned int *d, QWidget *parent) :QDialog(parent),ui(new Ui::recupDonnees)
{
    ui->setupUi(this);
    ui->pushButton_OK->setEnabled(false);
    donn=d;
    connect(ui->radioButton_DB,SIGNAL(clicked()),this,SLOT(activerOK()));
    connect(ui->radioButton_dur,SIGNAL(clicked()),this,SLOT(activerOK()));

    connect(ui->pushButton_OK,SIGNAL(clicked()),this,SLOT(recupererDonnees()));

}

recupDonnees::~recupDonnees()
{

    delete ui;
}

void recupDonnees::activerOK(){
    ui->pushButton_OK->setEnabled(true);
}

void recupDonnees::recupererDonnees(){

    if (ui->radioButton_DB->isChecked())
        *donn=1;
    else
        *donn=2;
    close();
}

