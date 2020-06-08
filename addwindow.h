#ifndef ADDFORM_H
#define ADDFORM_H

#include <QObject>
#include <QDialog>
#include <QtCore>
#include <QtWidgets>
#include "container.h"
#include "prodotto.h"
#include "listwidget.h"
#include "proddetails.h"
#include "addwindow.h"

class AddWindow : public QDialog
{
    Q_OBJECT
private:
    Prodotto* c;
    ListWidget* varList;
    ProdDetails* varDet;
public:
    AddWindow(QWidget* parent = nullptr);
};

#endif // ADDFORM_H
