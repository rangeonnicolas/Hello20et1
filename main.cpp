#include "feneditdoss.h"
#include "fenetre_principale.h"
#include "UV.h"
#include "dossier.h"
#include "dataBaseA.h"
#include "CursusEditor.h"
#include "CursusSelector.h"
#include "dataBaseB.h"
#include "browser.h"
#include "uvDataBaseConnect.h"
<<<<<<< HEAD
=======
#include "interfacePersistenceDonnees.h"
#include "dataBasePostgres.h"
>>>>>>> bb58f659bd1dac491fbcf23685bc583aa6685b7d
#include "recupdonnees.h"

#include <QApplication>
#include <QString>



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

<<<<<<< HEAD
=======

//    DATABASE::UvDbConn db(&app);
//    db.connect();
//    QMessageBox::information(0,"","1");
//    db.showEditor("assoc");
//    QMessageBox::information(0,"","2");
//    db.showEditor("portee");
//    QMessageBox::information(0,"","3");
//    db.showEditor("uv");

>>>>>>> bb58f659bd1dac491fbcf23685bc583aa6685b7d
    unsigned int donnees=1;

    //faire fenetre pour savoir quelle mode de récuperation des données on souhaite
            recupDonnees* fenetre= new recupDonnees(&donnees,0);
            fenetre->show();
        //créer variable pour enregistrer ce choix
           //si on choisit postgres:
           /*
            UvDbConn BD(&app);
            BD.connect();*/


    //    UVManager& uvm = UVManager::getInstance();
    //    for(UVManager::Iterator it = uvm.getIterator();!it.isDone(); it.next())
    //        std::cout<<it.current().getCode().toStdString();


    //partie pour remplir un UVManager fictif pour moi puisque je n'ai pas la base
    UVManager& m=UVManager::getInstance();
    QString code ="NF16";
    QString titre="Algo";

    m.ajouterUV(code,titre,true,true);

    code ="SR03";
    titre="sr03";
    m.ajouterUV(code,titre,false,true);

    code="TX";
    titre="Tdfsd Xgfs";
    m.ajouterUV(code,titre,true,true);

<<<<<<< HEAD

    fenetrePrincipale fenetre2(0,&app);
    fenetre2.show();
=======
    fenetrePrincipale fenetre2(0,&app);
    fenetre2.show();

>>>>>>> bb58f659bd1dac491fbcf23685bc583aa6685b7d
    return app.exec();
}
