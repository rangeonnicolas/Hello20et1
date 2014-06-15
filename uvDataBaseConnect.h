#ifndef UVDATABASECONNECT_H
#define UVDATABASECONNECT_H

#include "browser.h"
#include <QtCore>
#include <QtWidgets>
#include <QtSql>
#include <QDialog>

namespace DATABASE{

    class UvDbConn: public QMainWindow{
        QApplication* app;
        Browser browser;
        void addConnectionsFromCommandline(const QStringList &args, Browser *browser);
    public:
        UvDbConn(QApplication* app);
        void connect();
        void showEditor(const QString& nomTable);
    };


}


#endif // UVDATABASECONNECT_H
