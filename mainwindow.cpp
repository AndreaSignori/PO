#include <mainwindow.h>
#include <iostream>
MainWindow::MainWindow(QWidget* parent): QDialog(parent), c(new Container<Prodotto>()), varDet(new ProdDetails)
{
    setWindowTitle("Prodotti Deluxe Parrucchieri");
    QVBoxLayout *mainBody = new QVBoxLayout(this);

    QMenuBar *menuBar = new QMenuBar();
    QMenu *menu = menuBar->addMenu(tr("&File"));

    QAction *actSave = new QAction(tr("&Salva"));
    QAction *actLoad = new QAction(tr("&Carica"));

    //connesione Azioni salva e carica
    connect(actSave,&QAction::triggered,this, &MainWindow::salva);
    connect(actLoad, &QAction::triggered, this, [this](){varDet->clear();carica();update();});

    menu->addAction(actSave);
    menu->addAction(actLoad);

    mainBody->addWidget(menuBar);

    QHBoxLayout *body = new QHBoxLayout(); // layout
    mainBody->addLayout(body);
    resize(800, 600);


    QVBoxLayout *left = new QVBoxLayout;

    //Test con valori immessi
    carica();
    varList = new ListWidget(c);

    //tasto "remove" rimuove la riga selezionata nella lista
    QPushButton* remove = new QPushButton("Elimina Prodotto");
    //popolo la list widget
    for (auto it = c->begin(); it; ++it)
        varList->addEntry(it);
    //fine test

    //aggiunto un bordo nero sul fondo di ogni riga della Lista per definire la suddivisione degli Oggetti nella Lista
    varList->setStyleSheet(tr("QListWidget::item{border-bottom:1px solid black;}"));
    varList->setFlow(QListView::TopToBottom);
    varList->setResizeMode(QListView::Adjust);
    /* alla pressione della Lista di Oggetti selezionando una riga vado a mostrare i parametri della riga
     * stessa a lato oppure se vengono selezionati più valori mostro campi vuoti e blocco il pulsante di
     * rimozione per evitare problemi di rimozione di oggetti inesistenti
     */
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
    //bottone aggiunta nuovo Prodotto(Oggetto)
    QPushButton* add = new QPushButton("Aggiungi Prodotto");
    //creo un segnale alla sua pressione che apre una nuova finestra di dialogo
    connect(add, &QPushButton::clicked, [this] (bool) {
        AddWindow(this,varList,c).exec();
    });

    //creo un segnale alla pressione di remove per eliminare la riga selezionata dall'utente
    connect(remove, &QPushButton::clicked, [this] (bool) {
        varList->rmSelected(true,varDet);

    });

    QVBoxLayout* vLay1 = new QVBoxLayout();//layout per form e bottone "applica modifiche"
    QHBoxLayout* hLay1 = new QHBoxLayout();//layout per bottoni

    QLabel* title = new QLabel("Dettagli Prodotto:");

    title->setAlignment(Qt::AlignCenter);

    //pulsante per accettare le modifiche effettuate ad un Prodotto
    QPushButton* modifiche = new QPushButton;
    modifiche->setText("Applica");

    /* pulsante che imposta tutti i campi del prodotto selezionato a parametri di default
     * è necessario premere il tasto Apply per accettare le modifiche
     */
    QPushButton* reset = new QPushButton;
    reset->setText("Reset");
    //segnale per tasto Apply
    connect(modifiche, &QPushButton::clicked, varDet, [this](bool){
        varDet->apply();
        update();
    });
    //segnale per tasto Reset
    /* la pressione del pulsante genera una finestra di dialogo nel caso siano selezionati più Prodotti
     * contemporaneamente, nel caso vada a buon fine si avranno i campi del Prodotto a valori vuoti
     * o di default e una finestra di dialogo ricorderà il fatto di fover premere apply per accettare
     * le modifiche
     */
    connect(reset, &QPushButton::clicked, varDet, [this] (bool){
                auto items = varList->selectedItems();
                if (items.length() != 1){
                    QMessageBox::about(this->parentWidget(),"Errore","attenzione nessun Oggetto selezionato");
                }else{
                    varDet->reset();
                }
            });

    //aggiungo i vari widget/layout per formare la grafica
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

void MainWindow::salva()    {
    if (QMessageBox::question(this, "Salva", "Vuoi salvare la lista prodotti?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes) {
        try {
            DataAccObj::setFile(IO_Container::fromContToJson(&*c));
            QMessageBox::question(this, "Salvataggio completato", "La lista prodotti e' stata salvata correttamente", QMessageBox::Ok);
        } catch (MyException e) {
            qDebug() << e.what() << '\n';
        }
    }
}

void MainWindow::carica() {
    c->free();
    try {
        IO_Container::fromJsonToCont(DataAccObj::getFile(),c);
    } catch (MyException e) {
        qDebug() << e.what() << '\n';
        if(QMessageBox::question(this, "Errore", "Non e' stato possibile caricare una lista prodotti, vuoi caricare la lista di default?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)   {
            IO_Container::fromJsonToCont(DataAccObj::fromStringToJson(defaultlist::json),c);
        }
    }
}

void MainWindow::update()
{
    varList->clear();
    for(auto it = c->begin(); it ; ++it){
        varList->addEntry(it);
    }
}
