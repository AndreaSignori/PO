#include "addwindow.h"

AddWindow::AddWindow(QWidget *parent): QDialog(parent), lista(new QComboBox), title(new QLabel), varDet(new ProdDetails)
{
    QVBoxLayout *body = new QVBoxLayout(this);
    QHBoxLayout *selezione = new QHBoxLayout;
    QHBoxLayout *variabileform = new QHBoxLayout;
    setWindowTitle("Inserisci un nuovo prodotto");
    resize(600, 500);

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
    body->addLayout(variabileform);

}

void AddWindow::ChangeForm(){
    Prodotto* newprod;
    varDet->clear();
    if(lista->currentIndex()==0)
        newprod = new ProdChimico();
    else if(lista->currentIndex()==1)
        newprod = new Shampoo();
    else if(lista->currentIndex()==2)
        newprod = new Tinte();
    else if(lista->currentIndex()==3)
        newprod = new ShamColor();
    varDet->showDet(*newprod);
}
