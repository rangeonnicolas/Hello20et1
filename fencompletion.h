#ifndef FENCOMPLETION_H
#define FENCOMPLETION_H

#include <QDialog>

namespace Ui {
class fenCompletion;
}

class fenCompletion : public QDialog
{
    Q_OBJECT

public:
    explicit fenCompletion(QWidget *parent = 0);
    ~fenCompletion();

private:
    Ui::fenCompletion *ui;
};

#endif // FENCOMPLETION_H
