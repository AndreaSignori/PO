#include <mainwindow.h>

MainWindow::MainWindow(QWidget* parent): QDialog(parent), c(new Container<Prodotto>())
{
    setWindowTitle("Prodotti Deluxe Parrucchieri");
    QHBoxLayout *body = new QHBoxLayout(this); // layout
    resize(600, 500);


    QVBoxLayout *left = new QVBoxLayout;
    //QHBoxLayout *topBtns = new QHBoxLayout;
    //QHBoxLayout *bottomBtns = new QHBoxLayout;
    Tinte* t =  new Tinte();
    ShamColor* u =  new ShamColor();
    t->SetCodice("1000");
    t->SetNome("Madonna");
    u->SetCodice("12456");
    u->SetNome("oh Cazzo");
    c->push_front(t);
    c->push_front(u);
    varList = new ListWidget(c);
    varList->addEntry(c->begin());
    left->addWidget(varList);
    body->addLayout(left,33);

}
