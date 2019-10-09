#ifndef CAM_H
#define CAM_H

#include <QMainWindow>

namespace Ui {
class Cam;
}

class Cam : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cam(QWidget *parent = nullptr);
    ~Cam();

private:
    Ui::Cam *ui;
};

#endif // CAM_H
