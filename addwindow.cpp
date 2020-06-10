#include "addwindow.h"

AddWindow::AddWindow(QWidget *parent, ListWidget* l,Container<Prodotto>* pr): QDialog(parent), l(l), pr(pr), menu(new QComboBox()), p(nullptr), pd(new ProdDetails())
{
    QVBoxLayout *body = new QVBoxLayout(this);
    QHBoxLayout *selezione = new QHBoxLayout();
    setWindowTitle("Inserisci un nuovo prodotto");
    resize(500, 400);

    menu->addItem("Prodotto Chimico");
    menu->addItem("Shampoo");
    menu->addItem("Tinta");
    menu->addItem("Shampoo Colorante");

    connect(menu, &QComboBox::currentTextChanged,[this] () {
        this->ChangeForm();
        });

    selezione->addWidget(new QLabel("Seleziona il tipo di prodotto da inserire:"));
    selezione->addWidget(menu);

    body->addLayout(selezione);
    body->addLayout(pd);

    QDialogButtonBox* conferma = new QDialogButtonBox;
    conferma->setOrientation(Qt::Horizontal);
    conferma->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

    connect(conferma, &QDialogButtonBox::rejected, this, &AddWindow::close);
    connect(conferma, &QDialogButtonBox::accepted, [this](){
            this->pd->apply();
            if(this->p->GetCodice()!="" && this->p->GetNome() != ""){
                this->pr->push_back(this->p);
                this->l->addEntry(this->pr->end());
                this->close();
            }
    });

    body->addWidget(conferma);
    ChangeForm();
}

void AddWindow::ChangeForm(){
    pd->clear();
    if(menu->currentIndex()==0)
        p = new ProdChimico();
    else if(menu->currentIndex()==1)
        p = new Shampoo();
    else if(menu->currentIndex()==2)
        p = new Tinte();
    else if(menu->currentIndex()==3)
        p = new ShamColor();
    pd->showDet(*p);
}
