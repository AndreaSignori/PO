#include <mainwindow.h>

MainWindow::MainWindow(QWidget* parent): QDialog(parent), c(new Container<Prodotto>()), varDet(new ProdDetails)
{
    setWindowTitle("Prodotti Deluxe Parrucchieri");
    QHBoxLayout *body = new QHBoxLayout(this); // layout
    resize(600, 500);


    QVBoxLayout *left = new QVBoxLayout;
    //QHBoxLayout *topBtns = new QHBoxLayout;
    //QHBoxLayout *bottomBtns = new QHBoxLayout;

    //Test con valori immessi
    ProdChimico* p = new ProdChimico();
    Tinte* t =  new Tinte();
    Shampoo* s = new Shampoo();
    ShamColor* u =  new ShamColor();
    p->SetCodice("0");
    p->SetNome("ProdChimico");
    t->SetCodice("1");
    t->SetNome("Tinta");
    s->SetCodice("2");
    s->SetNome("Shampoo");
    u->SetCodice("3");
    u->SetNome("ShamColor");
    c->push_front(p);
    c->push_front(t);
    c->push_front(s);
    c->push_front(u);
    varList = new ListWidget(c);

    //popolo la list widget
    for (auto it = c->begin(); it; ++it)
        varList->addEntry(it);
    //fine test

    connect(varList, &ListWidget::itemSelectionChanged, [this] () {
        auto items = varList->selectedItems();
        if (items.length() != 1)
            varDet->clear();
        else
            varDet->showDet(*static_cast<ListWidgetItem*>(items[0])->getProdotto());
    });
    QPushButton* pb1 = new QPushButton("+");
    connect(pb1, &QPushButton::clicked, [this] (bool) { AddForm(this).exec(); });

    left->addWidget(pb1);
    left->addWidget(varList);
    body->addLayout(left,33);

    QVBoxLayout* vLay1 = new QVBoxLayout();//layout per form e bottone "applica modifiche"
    QHBoxLayout* hLay1 = new QHBoxLayout();//layout per bottoni

    vLay1->addLayout(varDet);
    vLay1->addStretch(1);
    QPushButton* modifiche = new QPushButton;
    modifiche->setText("Apply");

    connect(modifiche, &QPushButton::clicked, varDet, &ProdDetails::apply);

    hLay1->addWidget(modifiche);
    vLay1->addLayout(hLay1);
    body->addLayout(vLay1,66);
}
