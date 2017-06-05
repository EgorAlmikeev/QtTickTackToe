#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
//#include <unistd.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    QPixmap pixmap(":/images/splash.png");
//    QSplashScreen splash_screen(pixmap);

//    splash_screen.show();

//    sleep(2);
    w.show();
//    splash_screen.finish(&w);
    return a.exec();
}
