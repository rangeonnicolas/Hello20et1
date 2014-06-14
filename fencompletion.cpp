#include "fencompletion.h"
#include "ui_fencompletion.h"
#include "completion.h"

fenCompletion::fenCompletion(QWidget *parent) : QDialog(parent), ui(new Ui::fenCompletion)
{
    ui->setupUi(this);
    setWindowTitle("Fenetre Completion");
    Demande* dem=new Demande();
    dem->setCompletion(new AlgoCompletionSimple);
    dem->chercherSolution();

}

fenCompletion::~fenCompletion()
{
    delete ui;
}
