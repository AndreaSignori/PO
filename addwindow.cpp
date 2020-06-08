#include "addwindow.h"

AddWindow::AddWindow(QWidget *parent, Prodotto *c): QDialog(parent), lista(new QComboBox), title(new QLabel), varDet(new ProdDetails), slot(c)
{
    QVBoxLayout *body = new QVBoxLayout(this);
    QHBoxLayout *selezione = new QHBoxLayout;
    QHBoxLayout *variabileform = new QHBoxLayout;
    QHBoxLayout *buttons = new QHBoxLayout;
    setWindowTitle("Inserisci un nuovo prodotto");
    resize(500, 400);

    title->setText("Seleziona il tipo di prodotto da inserire:");
    lista->addItem("Prodotto Chimico");
    lista->addItem("Shampoo");
    lista->addItem("Tinta");
    lista->addItem("Shampoo Colorante");

    selezione->addWidget(title);
    selezione->addWidget(lista);


    body->addLayout(selezione);

    connect(
        lista, &QComboBox::currentTextChanged,
                [this] () {
        this->ChangeForm();
    }
    );
    variabileform->addLayout(varDet);

    QPushButton* aggiungi = new QPushButton;
    QPushButton* reset = new QPushButton;

    aggiungi->setText("Apply");
    reset->setText("Reset");

    connect(aggiungi, &QPushButton::clicked, varDet, &ProdDetails::apply);

    buttons->addWidget(reset);
    buttons->addWidget(aggiungi);

    body->addLayout(variabileform);
    body->addLayout(buttons);
}

void AddWindow::ChangeForm(){
    varDet->clear();
    if(lista->currentIndex()==0)
        slot = new ProdChimico();
    else if(lista->currentIndex()==1)
        slot = new Shampoo();
    else if(lista->currentIndex()==2)
        slot = new Tinte();
    else if(lista->currentIndex()==3)
        slot = new ShamColor();
    varDet->showDet(*slot);
}
