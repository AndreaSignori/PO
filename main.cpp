#include <QCoreApplication>
#include <QApplication>
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <mainwindow.h>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow main;
    main.show();
    return a.exec();
/*
    QCoreApplication a(argc, argv);
    */
}
