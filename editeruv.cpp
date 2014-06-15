#include "editeruv.h"
#include "ui_editeruv.h"

using namespace UV_credits_types;
EditerUv::EditerUv(UV& u, QWidget *parent) :QDialog(parent), ui(new Ui::EditerUv)
{
    ui->setupUi(this);
}

EditerUv::~EditerUv()
{
    delete ui;
}
