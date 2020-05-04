#include "mainwindow.h"
#include <QApplication>
#include "testwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Windows w;
    w.show();

    return a.exec();
}

