#include "addwindow.h"
#include <QComboBox>
#include <iostream>
using namespace std;

AddWindow::AddWindow(QWidget *parent): QDialog(parent), lista(new QComboBox)
{
    setWindowTitle("Inserisci un nuovo prodotto");
    resize(600, 500);

    lista.addItem("Prodotto Chimico");
    lista.addItem("Shampoo");
    lista.addItem("Tinta");
    lista.addItem("Shampoo Colorante");
}
