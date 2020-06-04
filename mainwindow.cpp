#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent): QDialog(parent), c(new Container<Prodotto>())
{
    setWindowTitle("Prodotti Deluxe Parrucchieri");
    //QHBoxLayout *body = new QHBoxLayout(this); // layout
    resize(600, 500);


    //QVBoxLayout *left = new QVBoxLayout;
    //QHBoxLayout *topBtns = new QHBoxLayout;
    //QHBoxLayout *bottomBtns = new QHBoxLayout;

    varList = new ListWidget(c);

}
