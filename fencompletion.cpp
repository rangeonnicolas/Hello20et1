#include "fencompletion.h"
#include "ui_fencompletion.h"
#include "completion.h"
#include "dossier.h"

fenCompletion::fenCompletion(QWidget *parent) : QDialog(parent), ui(new Ui::fenCompletion)
{
    ui->setupUi(this);
    setWindowTitle("Fenetre Completion");
    Demande* dem=new Demande();
    dem->setCompletion(new AlgoCompletionSimple);
    dem->chercherSolution();
    //affichage de la mapSolution
    Dossier& doss=Dossier::getInstance();
    QMap<unsigned int,QList<Inscription> > mapSol=doss.getMapSol();

    QList<Inscription> sol= mapSol.last();
    for(int i=0;i<sol.length();i++){
        //QMessageBox::information(this,"inscrip","inscription"+i+" : "+sol.at(i).getUV()+" , "+sol.at(i).getSemestre());
        //std::cout<<sol.at(i).getUV()<<" : "<<sol.at(i).getSemestre();
    }

}

fenCompletion::~fenCompletion()
{
    delete ui;
}
