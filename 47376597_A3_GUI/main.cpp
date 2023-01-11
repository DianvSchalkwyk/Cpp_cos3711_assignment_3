#include "mainclient.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainClient mc;
    mc.show();

    QPixmap pixmap(":/COS3711_A3/Resources/Images/COS3711-Logistics.png");
    QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
    splash.show();
    QTimer::singleShot(3000, &mc,      &QWidget::show);
    QTimer::singleShot(3000, &splash , &QWidget::close);

    return a.exec();
}
