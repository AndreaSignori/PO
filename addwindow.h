#ifndef ADDFORM_H
#define ADDFORM_H

#include <QObject>
#include <QDialog>
#include <QtCore>
#include <QtWidgets>
#include "container.h"
#include "prodotto.h"
#include "proddetails.h"
#include "listwidget.h"

class AddWindow : public QDialog
{
    Q_OBJECT

private:
    Prodotto* c;
    QLabel* title;
    QComboBox* lista;
    ProdDetails* varDet;
public:
    AddWindow(QWidget* parent = nullptr);

    void ChangeForm();
};

#endif // ADDFORM_H
