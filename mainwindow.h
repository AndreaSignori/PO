#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QDialog>
#include <QtCore>
#include <QtWidgets>
#include "io_container.h"
#include "prodotto.h"
#include "listwidget.h"
#include "proddetails.h"
#include "addwindow.h"
#include "defaultlist.h"

class MainWindow: public QDialog
{
    Q_OBJECT

private:
    Container<Prodotto> *c;
    ListWidget* varList;
    ProdDetails* varDet;
public:
    MainWindow(QWidget* parent = nullptr);
private slots:
    void salva();
    void carica();
    void update();
};

#endif // MAINWINDOW_H
