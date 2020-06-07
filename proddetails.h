#ifndef PRODDETAILS_H
#define PRODDETAILS_H

#include <QtWidgets>
#include <prodotto.h>
#include <typeinfo>

class ProdDetails : public QFormLayout
{
private:
    Prodotto* prod;

    QLineEdit* name, *cod, *casaProd, *prezzo, *sconto, *img64;
    QLineEdit* quantita; QRadioButton *si, *no;QGroupBox* g1;
    QComboBox* tC, *tS;
    QLineEdit* numT;QComboBox* tT;

public:

    ProdDetails(QWidget* parent = nullptr);

    void showDet(Prodotto &prod);
    void clear();

public slots:
    void apply();
    void reset();
};

#endif // PRODDETAILS_H
