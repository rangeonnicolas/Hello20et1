#include "feneditdoss.h"
#include "ui_feneditdoss.h"
#include "dossier.h"
#include <QMainWindow>
using namespace question3;

fenEditDoss::fenEditDoss(Dossier *doss, QWidget *parent) : QDialog(parent), ui(new Ui::fenEditDoss)
    {
        ui->setupUi(this);
        setWindowTitle("Fenetre Edition Dossier");


    }


fenEditDoss::~fenEditDoss()
    {
        delete ui;
    }
