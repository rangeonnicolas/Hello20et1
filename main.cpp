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
#include "interfacePersistenceDonnees.h"

#include <QApplication>
#include <QString>



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);



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


    fenetrePrincipale fenetre(0,&app);
    fenetre.show();
    return app.exec();
}
