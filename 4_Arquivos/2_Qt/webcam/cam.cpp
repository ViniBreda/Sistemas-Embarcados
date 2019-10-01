#include "cam.h"
#include "ui_cam.h"

Cam::Cam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cam)
{
    ui->setupUi(this);
}

Cam::~Cam()
{
    delete ui;
}
