#include "choixuv.h"
#include "ui_choixuv.h"

choixUV::choixUV(QWidget *parent) : QDialog(parent), ui(new Ui::choixUV){
    ui->setupUi(this);
    ui->pushButton_OK->setEnabled(false);
    connect(ui->comboBox_UV ,SIGNAL(currentTextChanged(QString)),this ,SLOT(activerOK(QString)));
}

choixUV::~choixUV()
{
    delete ui;
}

//fonction pour que lo bouton ok soit reactivé
void choixUV::activerOK(QString){
    ui->pushButton_OK->setEnabled(true);
}


