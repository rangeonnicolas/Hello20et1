#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <QDialog>
#include "UV.h"
#include "editeruv.h"

using namespace UV_credits_types;

namespace Ui {
    class catalogue;
}

class catalogue : public QDialog
{
    Q_OBJECT

public:
    explicit catalogue(UV& uv,QWidget *parent = 0);
    ~catalogue();

private:
    Ui::catalogue *ui;
};


#endif // CATALOGUE_H
