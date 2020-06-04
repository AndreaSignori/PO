#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QDialog>
#include <QtCore>
#include <QtWidgets>
#include "container.h"
#include <prodotto.h>
#include <listwidget.h>

class MainWindow: public QDialog
{
    Q_OBJECT

private:
    Container<Prodotto> *c;
    ListWidget* varList;
public:
    MainWindow(QWidget* parent = nullptr);
};


//mainWindow Vecchia di prima Versione
/*
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
*/
#endif // MAINWINDOW_H
