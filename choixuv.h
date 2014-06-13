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
    void activerOK();
    void recupererUv();
    void valider();

private:
    Ui::choixUV *ui;
    QString uvSelectionnee;
};

#endif // CHOIXUV_H
