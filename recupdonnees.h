#ifndef RECUPDONNEES_H
#define RECUPDONNEES_H

#include <QDialog>

namespace Ui {
class recupDonnees;
}

class recupDonnees : public QDialog
{
    Q_OBJECT

public:
    explicit recupDonnees(unsigned int* d, QWidget *parent = 0);
    ~recupDonnees();

private:
    Ui::recupDonnees *ui;
    unsigned int* donn;

public slots:
    void recupererDonnees();
    void activerOK();

};

#endif // RECUPDONNEES_H
