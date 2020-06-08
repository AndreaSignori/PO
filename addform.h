#ifndef ADDFORM_H
#define ADDFORM_H

#include <QtWidgets>
#include <prodotto.h>
#include <typeinfo>

class AddForm : public QFormLayout
{
private:
    Prodotto* prod;

    QLineEdit* name, *cod, *casaProd, *prezzo, *sconto, *img64;
    QLineEdit* quantita; QRadioButton *si, *no;QGroupBox* g1;
    QComboBox* tC, *tS;
    QLineEdit* numT;QComboBox* tT;
public:
    AddForm(QWidget* parent = nullptr);
};

#endif // ADDFORM_H
