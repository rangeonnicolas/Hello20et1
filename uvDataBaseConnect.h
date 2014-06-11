#ifndef UVDATABASECONNECT_H
#define UVDATABASECONNECT_H

#include "browser.h"
#include <QtCore>
#include <QtWidgets>
#include <QtSql>
#include <QDialog>

//mettre en singleton
namespace DATABASE{

    class UvDbConn: public QMainWindow{
        //QMainWindow mainWin;
        QApplication* app;
        Browser browser;
        QMenu *fileMenu;
        QMenu *helpMenu;
        void addConnectionsFromCommandline(const QStringList &args, Browser *browser);
    public:
        UvDbConn(QApplication* app);
        void connect();
    };


}


#endif // UVDATABASECONNECT_H
