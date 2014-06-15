#include "feneditdoss.h"
#include "ui_feneditdoss.h"
#include "dossier.h"
#include "CursusEditor.h"

#include <QMainWindow>
#include <QObject>
using namespace INSCRIPTIONS;

fenEditDoss::fenEditDoss(Dossier *doss, Cursus* rootCursus, QWidget *parent) : QDialog(parent), ui(new Ui::fenEditDoss),SOUSfenetre(new GRAPHICALEDITORS::CURSUSSelector(rootCursus,this)),rootCursus(rootCursus)
    {
        ui->setupUi(this);
        setWindowTitle("Fenetre Edition Dossier");

        d=doss;

        //remplir les widgets
        //remplissage de la combobox
        UVManager& m=UVManager::getInstance();
        UVManager::Iterator ite=m.getIterator();
        while(!(ite.isDone())){
            ui->comboBox_code->addItem(ite.current().getCode());
            ite.next();
        }

        //signal pour que qd utilisateur selectionne une uv le choix entre automne et printemps corresponde avec ce qui est possible
        connect(ui->comboBox_code,SIGNAL(currentIndexChanged(QString)),this,SLOT(setOuverture()));

        // au clic de valider de l'etape1
        connect(ui->pushButton_Valider,SIGNAL(clicked()),this,SLOT(enregistrerLogin()));

        // auc clic de choisir de l'etape 2
        connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(openCurs()));

        //au clic de ajouter de l'étape 3 on enregistre l'inscription dans une liste d'inscription créée localement et on affiche le code dans la view à droite
        connect(ui->pushButton_ajouterEtape3,SIGNAL(clicked()),this,SLOT(ajouterEtape3()));

        // au clic de ajouter de l'étape 4 on enregistre dans liste locale
        connect(ui->pushButton_ajouter4,SIGNAL(clicked()),this,SLOT(ajouterEtape4()));

        //au clic qur le bouton ok, les listes locales et l'arbre de cursus sont enregistrées dans le dossier
        connect(ui->boutonOK, SIGNAL(clicked()),this,SLOT(validerDossier()));

    }




void fenEditDoss::setOuverture(){
    ui->radioButton_automne->setCheckable(false);
    ui->radioButton_printemps->setCheckable(false);
    QString code = ui->comboBox_code->currentText();
    UV& uv=UVManager::getInstance().getUV(code);
    if(uv.ouvertureAutomne()){
        ui->radioButton_automne->setCheckable(true);
    }
    if(uv.ouverturePrintemps()){
        ui->radioButton_printemps->setCheckable(true);
    }
}


void fenEditDoss::validerDossier(){
    //au clic qur le bouton ok, les listes locales et l'arbre de cursus sont enregistrées dans le dossier
    d->setInscr(listInscription);
    d->setEqui(listE);

    //fermer la fenetre
    close();
}

void fenEditDoss::openCurs(){
    SOUSfenetre->show();
}

void fenEditDoss::ajouterEtape3(){

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

    i.setUv(&(UVManager::getInstance().getUV(ui->comboBox_code->currentText())));

    setInscription(i);

    //affiche
    ui->listUvsAjoutes->addItem(ui->comboBox_code->currentText());
}

void fenEditDoss::ajouterEtape4(){
    Equivalence e;
    Credits c;
    c.setNbCredits(ui->spinBox_nb->value());
    //c.setType(StringToCategorie(ui->comboBox_cat->currentText()));
    e.setCredits(c);
    Portee p;
    p.setLibelle(ui->comboBox_portee->currentText());
    e.setPortee(p);

    setEqui(e);

    //affiche
    ui->listUvsAjoutes->addItem("équivalence : "+ui->comboBox_2->currentText()+ui->spinBox_nb->value()+" crédits");

}

void fenEditDoss::enregistrerLogin(){
    fenEditDoss::setLogin(ui->lineEdit->text());
}

fenEditDoss::~fenEditDoss()
    {
        delete ui;
    }

void fenEditDoss::lEtudiantAAjouteUnCursusetu(){
    d->add_cursus(SOUSfenetre->getCursusSaisiParLEtudiant());
    QMessageBox::information(0,"Notification",QString("L'UTC vous remercie de tout coeur de vous être inscrits à des cursus! \nVoici l'intégralité des conditions de validation de vos Cursus (accrochez-vous!):\n\n")+QString(d->getCursusEtu()->toString(0).c_str())+QString("\n\n\n...Etes-vous toujour sûr de vouloir vous inscrire à tous ces cursus...?!"));
}



