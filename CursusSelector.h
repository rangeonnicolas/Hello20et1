#ifndef CURSELECTOR_H
#define CURSELECTOR_H

#include "dossier.h"
#include "UV.h"
//#include "feneditdoss.h"

#include <QTreeView>
#include <QPushButton>
#include <QLabel>
#include <QListView>
#include <QMessageBox>
#include <QHBoxLayout>

class fenEditDoss;// c'est juste pour spécifier au compilateur que plus tard, il y aura une classe qui sera définie qui portera le nom de fenEditDoss. Si on l'enlère il y a un probleme dans l'ordre des include :)

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

        fenEditDoss* parentFenetre;

    public:
        explicit CURSUSSelector(Cursus* root,fenEditDoss* parentFenetre, QWidget *parent = 0);
        ~CURSUSSelector(){
            //ne pas détruire le cursus renvoyé car il est renvoyé justement!
        };
        Cursus_Etudiant* getCursusSaisiParLEtudiant(){return studentCursus;};
    private:
        //void initView();
        //void refresh();
    signals:
    public slots:
        void editionFinished();
    private slots:
        void openAdderWindow();
        void clicCursusSelection(const QModelIndex&);
        void jeDoisMeFermer(){this->close();};
    };






}

#endif // CURSELECTOR_H
