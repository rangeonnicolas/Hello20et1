#ifndef EDITERUV_H
#define EDITERUV_H

#include <QDialog>
#include "UV.h"
using namespace UV_credits_types;

namespace Ui {
class EditerUv;
}

class EditerUv : public QDialog
{
    Q_OBJECT

public:
    explicit EditerUv( UV& u, QWidget *parent = 0);
    ~EditerUv();

private:
    Ui::EditerUv *ui;
};

#endif // EDITERUV_H
