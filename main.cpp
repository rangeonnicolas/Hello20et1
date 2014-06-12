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

#include <QApplication>
#include <QString>
//#include <QtCore>
//#include <QtWidgets>
//#include <QtSql>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    fenetrePrincipale fenetre(0,&app);
    fenetre.show();
    return app.exec();
}
