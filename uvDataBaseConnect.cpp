

#include "uvDataBaseConnect.h"

using namespace DATABASE;

    UvDbConn::UvDbConn(QApplication* app):app(app),browser("uv",this){

        this->setWindowTitle(QObject::tr("ADMINISTRATION : Edition de la Base de Données des UV / Portées / Types de Crédits"));

        this->setCentralWidget(&browser);

/*        fileMenu = this->menuBar()->addMenu(QObject::tr("&File"));
        fileMenu->addAction(QObject::tr("Add &Connection..."), &browser, SLOT(addConnection()));
        fileMenu->addSeparator();*/

/*        helpMenu = this->menuBar()->addMenu(QObject::tr("&Help"));
        helpMenu->addAction(QObject::tr("About"), &browser, SLOT(about()));
        helpMenu->addAction(QObject::tr("About Qt"), qApp, SLOT(aboutQt()));
*/
        QObject::connect(&browser, SIGNAL(statusMessage(QString)),
                         this->statusBar(), SLOT(showMessage(QString)));



    }

    void UvDbConn::addConnectionsFromCommandline(const QStringList &args, Browser *browser)
    {
        for (int i = 1; i < args.count(); ++i) {
            QUrl url(args.at(i), QUrl::TolerantMode);
            if (!url.isValid()) {
                qWarning("Invalid URL: %s", qPrintable(args.at(i)));
                continue;
            }
            QSqlError err = browser->addConnection(url.scheme(), url.path().mid(1), url.host(),
                                                   url.userName(), url.password(), url.port(-1));
            if (err.type() != QSqlError::NoError)
                qDebug() << "Unable to open connection:" << err;
        }
    }

    void UvDbConn::connect(){
        addConnectionsFromCommandline(app->arguments(), &browser);
        //mainWin.show();
        if (QSqlDatabase::connectionNames().isEmpty())
            QMetaObject::invokeMethod(&browser, "addConnection", Qt::QueuedConnection);

    }

    void UvDbConn::showEditor(const QString& nomTable){
        browser.showTable(nomTable);
        this->show();
    }




