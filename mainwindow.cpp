#include <mainwindow.h>

MainWindow::MainWindow(QWidget* parent): QDialog(parent), c(new Container<Prodotto>()), varDet(new ProdDetails)
{
    setWindowTitle("Prodotti Deluxe Parrucchieri");
    QVBoxLayout *mainBody = new QVBoxLayout(this);

    QMenuBar *menuBar = new QMenuBar();
    QMenu *menu = menuBar->addMenu(tr("&File"));

    QAction *actSave = new QAction(tr("&Save"));
    QAction *actLoad = new QAction(tr("&Load"));
    /*
    connect(actSave, &QAction::triggered, ...)
    connect(actLoad, &QAction::triggered, ...
    */
    menu->addAction(actSave);
    menu->addAction(actLoad);

    mainBody->addWidget(menuBar);

    QHBoxLayout *body = new QHBoxLayout(); // layout
    mainBody->addLayout(body);
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

    QPushButton* remove = new QPushButton("remove");
    //popolo la list widget
    for (auto it = c->begin(); it; ++it)
        varList->addEntry(it);
    //fine test

    varList->setStyleSheet(tr("QListWidget::item{border-bottom:1px solid black;}"));
    connect(varList, &ListWidget::itemSelectionChanged, [this,remove] () {
        auto items = varList->selectedItems();
        if (items.length() != 1)
            varDet->clear();
        else
            varDet->showDet(*static_cast<ListWidgetItem*>(items[0])->getProdotto());

        if(varList->selectedItems().length() == 0 || varList->selectedItems().length()>1){
            remove->setEnabled(false);
        }else{
            remove->setEnabled(true);
        }
    });
    QPushButton* add = new QPushButton("Nuovo Prodotto");
    connect(add, &QPushButton::clicked, [this] (bool) {
        AddWindow(this,varList,c).exec();
    });



    connect(remove, &QPushButton::clicked, [this] (bool) {
        varList->rmSelected(true);
    });



    QVBoxLayout* vLay1 = new QVBoxLayout();//layout per form e bottone "applica modifiche"
    QHBoxLayout* hLay1 = new QHBoxLayout();//layout per bottoni

    QLabel* title = new QLabel("Dettagli Prodotto:");

    title->setAlignment(Qt::AlignCenter);

    QPushButton* modifiche = new QPushButton;
    modifiche->setText("Apply");

    QPushButton* reset = new QPushButton;
    reset->setText("Reset");
    connect(modifiche, &QPushButton::clicked, varDet, &ProdDetails::apply);
    connect(reset, &QPushButton::clicked, varDet, [this] (bool){
                auto items = varList->selectedItems();
                if (items.length() != 1){
                    QMessageBox::about(this->parentWidget(),"Errore","attenzione nessun Oggetto selezionato");
                }else{
                    varDet->reset();
                }
            });

    left->addWidget(add);
    left->addWidget(varList);
    left->addWidget(remove);

    body->addLayout(left,33);

    vLay1->addWidget(title);
    vLay1->addStretch(1);
    vLay1->addLayout(varDet);
    vLay1->addStretch(8);

    hLay1->addWidget(modifiche);
    hLay1->addWidget(reset);

    vLay1->addLayout(hLay1);

    body->addLayout(vLay1,66);
}
