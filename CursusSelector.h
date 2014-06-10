#ifndef CURSELECTOR_H
#define CURSELECTOR_H

#include "dossier.h"
#include "UV.h"

#include <QTreeView>
#include <QPushButton>
#include <QLabel>
#include <QListView>
#include <QMessageBox>
#include <QHBoxLayout>



namespace GRAPHICALEDITORS{

    using namespace question3;

    class CURSUSAdder : public QWidget{
        Q_OBJECT

        QListView*   SOUScursusSelector ;
        QLabel*      SOUScursusLabel;

        //QPushButton* ok ;
        //QPushButton* annuler ;

        QVBoxLayout* couche;

        QStandardItemModel*  SOUScursusSelectorModel ;

        Cursus* currentCursus;
        Cursus_Etudiant* studentCursus;

        CURSUSAdder* UNDERadder;

    public:
        explicit CURSUSAdder(Cursus* current,Cursus_Etudiant* studentCursus, QWidget *parent = 0);
    private:
    signals:
        void sorryIAmClosing();
    public slots:
        void closeWindow();
    private slots:
        void clicCursusSelection(const QModelIndex&);
    };


    class CURSUSSelector : public QWidget{
        Q_OBJECT

        QTreeView*   cursusSelector ;
        QLabel*      cursusLabel;
        QPushButton* cursusAjouter ;
        QPushButton* cursusSupprimer ;

        QPushButton* ok ;

        QVBoxLayout* couche;

        QStandardItemModel*  cursusSelectorModel ;

        Cursus*          rootCursus;
        Cursus_Etudiant* studentCursus;
        Cursus_Etudiant* selectedCursus;

        CURSUSAdder* adder;

    public:
        explicit CURSUSSelector(Cursus* root, QWidget *parent = 0);
    private:
        //void initView();
        //void refresh();
    signals:
    public slots:
        void editionFinished();
    private slots:
        void openAdderWindow();
        void clicCursusSelection(const QModelIndex&);
    };






}

#endif // CURSELECTOR_H
