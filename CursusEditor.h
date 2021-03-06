#ifndef CURSUSEDITOR_H
#define CURSUSEDITOR_H

#include "dossier.h"
#include "UV.h"

#include <QTreeView>
#include <QPushButton>
#include <QLabel>
#include <QListView>
#include <QMessageBox>
#include <QHBoxLayout>




namespace GRAPHICALEDITORS{

    using namespace INSCRIPTIONS;

    class CURSUSEditor : public QDialog{
        Q_OBJECT
        //QList<Cursus*> list;

        QTreeView*   cursusSelector ;
        QLabel*      cursusLabel;
        QLabel*      cursusLabel_2;
        QPushButton* cursusAjouter ;
        QPushButton* cursusSupprimer ;
        QPushButton* cursusAjouterExistant ;

        QListView*   profilSelector ;
        QLabel*      profilLabel;
        QLabel*      profilLabel_2;
        QPushButton* profilAjouter ;
        QPushButton* profilSupprimer ;

        QTreeView*   regleSelector ;
        QLabel*      regleLabel;
        QLabel*      regleLabel_2;
        QPushButton* regleAjouter ;
        QPushButton* regleSupprimer ;

        QPushButton* ok ;

        QHBoxLayout* coucheH;
        QVBoxLayout* coucheV1;
        QVBoxLayout* coucheV2;
        QVBoxLayout* coucheV3;

        QStandardItemModel*  cursusSelectorModel ;
        QStandardItemModel*  profilSelectorModel ;
        QStandardItemModel*  regleSelectorModel ;

        Cursus*         rootCursus;
        Cursus*         selectedCursus;
        Profil*         selectedProfile;
        ValidationRule* selectedRule;

    public:
        explicit CURSUSEditor(Cursus* root, QWidget *parent = 0);
        //explicit CURSUSEditor(QList<Cursus*> cl, Cursus* root, QWidget *parent = 0);
    private:
        void initView();
        void refresh();
    signals:
    public slots:

    private slots:
        void clicCursusSelection(const QModelIndex&);
        void clicProfilSelection(const QModelIndex&);
    };



}

#endif // CURSUSEDITOR_H
