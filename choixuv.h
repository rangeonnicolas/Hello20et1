#ifndef CHOIXUV_H
#define CHOIXUV_H

#include <QDialog>

namespace Ui {
class choixUV;
}

class choixUV : public QDialog
{
    Q_OBJECT

public:
    explicit choixUV(QWidget *parent = 0);
    ~choixUV();
    void activerOK(QString str="");

private:
    Ui::choixUV *ui;
};

#endif // CHOIXUV_H
