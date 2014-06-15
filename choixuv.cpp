#include "choixuv.h"
#include "ui_choixuv.h"
#include "catalogue.h"
#include "UV.h"
#include <QMessageBox>
using namespace UV_credits_types;

choixUV::choixUV(QWidget *parent) : QDialog(parent), ui(new Ui::choixUV){
    ui->setupUi(this);
    ui->pushButton_OK->setEnabled(false);

    //remplissage de la combobox
    UVManager& m=UVManager::getInstance();
    UVManager::Iterator ite=m.getIterator();
    while(!(ite.isDone())){
        ui->comboBox_UV->addItem(ite.current().getCode());
        ite.next();
    }

    connect(ui->comboBox_UV,SIGNAL(currentIndexChanged(QString)),this,SLOT(activerOK(QString)));
   // connect(ui->pushButton_OK,SIGNAL(clicked()),this,SLOT(recupererUV()));
    connect(ui->pushButton_OK,SIGNAL(clicked()),this,SLOT(valider()));
}

choixUV::~choixUV()
{
    delete ui;
}

//fonction pour que le bouton ok soit reactivé
void choixUV::activerOK(QString s){
    ui->pushButton_OK->setEnabled(true);
}

/*
//fonction pour récupérer l'uv selectionnée
void choixUV::recupererUv(){
    uvSelectionnee=ui->comboBox_UV->currentText();
}
*/
void choixUV::valider(){
    //recuperer uv choisi dans combobox
    QString code=ui->comboBox_UV->currentText();

    //ouvrir fenetre catalogue avec le pointeur correspondant en argument
    catalogue* fenetreCat= new catalogue(UVManager::getInstance().getUV(code),this);
    //getUV(cherche l'uv et renvoie une reference de l'UV
    fenetreCat->show();

}
