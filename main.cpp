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

    fenetrePrincipale fenetre(0,&app);
    fenetre.show();
    return app.exec();
}
