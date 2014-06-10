#ifndef CURSUSEDITOR_H
#define CURSUSEDITOR_H

#include <QTreeView>
#include <QPushButton>
#include <QLabel>
#include <QListView>
#include <QHBoxLayout>
#include "Cursus.h"

using namespace CURSUS;

namespace GRAPHICALEDITORS{

    class CURSUSEditor : public QWidget{
        Q_OBJECT
        QList<Cursus*> list;

        QTreeView*   cursusSelector ;
        QLabel*      cursusLabel;
        QLabel*      cursusLabel_2;
        QPushButton* cursusAjouter ;
        QPushButton* cursusSupprimer ;

        QListView*   profilSelector ;
        QLabel*      profilLabel;
        QLabel*      profilLabel_2;
        QPushButton* profilAjouter ;
        QPushButton* profilSupprimer ;

        QListView*   regleSelector ;
        QLabel*      regleLabel;
        QLabel*      regleLabel_2;
        QPushButton* regleAjouter ;
        QPushButton* regleSupprimer ;

        QPushButton* ok ;

        QHBoxLayout* coucheH;
        QVBoxLayout* coucheV1;
        QVBoxLayout* coucheV2;
        QVBoxLayout* coucheV3;

    public:
        explicit CURSUSEditor(QList<Cursus*> cl, QWidget *parent = 0);
    signals:
    public slots:
    private slots:

    };



}

#endif // CURSUSEDITOR_H
