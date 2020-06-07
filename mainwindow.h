#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QDialog>
#include <QtCore>
#include <QtWidgets>
#include "container.h"
#include "prodotto.h"
#include "listwidget.h"
#include "proddetails.h"
#include "addform.h"

class MainWindow: public QDialog
{
    Q_OBJECT

private:
    Container<Prodotto> *c;
    ListWidget* varList;
    ProdDetails* varDet;
public:
    MainWindow(QWidget* parent = nullptr);
};

#endif // MAINWINDOW_H
