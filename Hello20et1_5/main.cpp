


#include "feneditdoss.h"
#include "fenetre_principale.h"
#include "UV.h"
#include "dossier.h"
#include "dataBaseA.h"
#include "CursusEditor.h"
#include "CursusSelector.h"
#include "dataBaseB.h"

#include <QApplication>
#include <QString>

int main(int argc, char *argv[]) {
QApplication app(argc, argv);

fenetrePrincipale fenetre;
fenetre.show();
return app.exec();
}
