#ifndef ADDFORM_H
#define ADDFORM_H

#include <QObject>
#include <QDialog>
#include <QtCore>
#include <QtWidgets>
#include <typeinfo>
#include "container.h"
#include "prodotto.h"
#include "proddetails.h"
#include "listwidget.h"

class AddWindow : public QDialog
{
    Q_OBJECT

private:
    ListWidget* l;
    Container<Prodotto>* pr;
    QComboBox* menu;
    Prodotto* p;
    ProdDetails* pd;
    bool check = false;
public:
    AddWindow(QWidget* parent = nullptr ,ListWidget* l = nullptr,Container<Prodotto>* pr = nullptr);

    void ChangeForm();
};

#endif // ADDFORM_H
