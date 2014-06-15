#ifndef CHOIXUV_H
#define CHOIXUV_H

#include <QDialog>
#include "catalogue.h"

namespace Ui {
class choixUV;
}

class choixUV : public QDialog
{
    Q_OBJECT

public:
    explicit choixUV(QWidget *parent = 0);
    ~choixUV();



private:
    Ui::choixUV *ui;
    QString uvSelectionnee;

public slots:

    void activerOK(QString s);
    //void recupererUv();
    void valider();
};

#endif // CHOIXUV_H
