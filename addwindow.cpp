#include "addwindow.h"
#include <iostream>
using namespace std;

AddWindow::AddWindow(QWidget *parent): QDialog(parent), varDet(new ProdDetails)
{
    setWindowTitle("Inserisci un nuovo prodotto");
    QStringList type;
}
