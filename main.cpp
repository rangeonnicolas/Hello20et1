#include "UV.h"
#include "inscription.h"
#include "dossier.h"
#include "dossierXMLreader.h"
#include "fenetre_principale.h"
#include "feneditdoss.h"
#include "dataBaseA.h"
#include "CursusEditor.h"
#include "CursusSelector.h"
#include "dataBaseB.h"
#include "browser.h"
#include "uvDataBaseConnect.h"
#include "interfacePersistenceDonnees.h"
#include "persistenceDonnees.h"
#include "dataBasePostgres.h"
#include "recupdonnees.h"

#include <QApplication>
#include <QString>

using namespace DATABASE;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    unsigned int donnees=2;
    connectionDB db(donnees);

    recupDonnees* fenetre= new recupDonnees(&donnees,0);
    fenetre->show();

//    try{
//        //partie pour remplir un UVManager fictif pour moi puisque je n'ai pas la base
//        UVManager& m=UVManager::getInstance();
//        QString code ="NF16";
//        QString titre="Algo";


//        m.ajouterUV(code,titre,true,true);

//        code ="SR03";
//        titre="sr03";
//        m.ajouterUV(code,titre,false,true);

//        code="TX";
//        titre="Tdfsd Xgfs";
//        m.ajouterUV(code,titre,true,true);

//    }catch(UTProfilerException e){
//        QMessageBox::warning(0,"Attention",e.getInfo());
//    }

    fenetrePrincipale fenetre2(0,&app);
    fenetre2.show();

    return app.exec();
}
