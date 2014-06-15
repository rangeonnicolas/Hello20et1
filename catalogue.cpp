#include "catalogue.h"
#include "ui_catalogue.h"

catalogue::catalogue(UV& uv, QWidget *parent) : QDialog(parent), ui(new Ui::catalogue)
{
    ui->setupUi(this);
    ui->codeVal->setText(uv.getCode());
    ui->titreVal->setText(uv.getTitre());
    //completer le reste du formulaire

    ui->automneBox->setChecked(false);
    ui->printempsBox->setChecked(false);

    if(uv.ouvertureAutomne()){
        ui->automneBox->setChecked(true);
    }
    if(uv.ouverturePrintemps()){
        ui->printempsBox->setChecked(true);
    }

}

catalogue::~catalogue()
{
    delete ui;
}



