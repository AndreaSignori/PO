#include "addform.h"
#include <iostream>
using namespace std;

AddForm::AddForm(QWidget *parent): QFormLayout(parent),prod(nullptr), name(new QLineEdit()), cod(new QLineEdit()), casaProd(new QLineEdit()), prezzo(new QLineEdit()), sconto(new QLineEdit()),quantita(new QLineEdit()),g1(new QGroupBox()),tC(new QComboBox()),tS(new QComboBox()),numT(new QLineEdit()),tT(new QComboBox())
{
    addRow(tr("&Codice: "),cod);
    addRow(tr("&Nome: "),name);
    addRow(tr("&Casa Produttrice: "),casaProd);
    addRow(tr("&Prezzo: "),prezzo);
    addRow(tr("&Sconto: "),sconto);
}
