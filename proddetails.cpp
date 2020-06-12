#include "proddetails.h"
#include <iostream>
using namespace std;

ProdDetails::ProdDetails(QWidget *parent): QFormLayout(parent),prod(nullptr), name(new QLineEdit()), cod(new QLineEdit()), casaProd(new QLineEdit()), img64(new QLabel()), prezzo(new QDoubleSpinBox()), sconto(new QSpinBox()),quantita(new QSpinBox()),g1(new QGroupBox()),tC(new QComboBox()),tS(new QComboBox()),numT(new QLineEdit()),tT(new QComboBox())
{
    //genero la grafica dei dettagli del prodotto che sarà visibile nella parte sinistra della GUI

    img64->setText(tr("nessun file selezionato"));
    test->addWidget(img64);
    searchImg = new QPushButton(tr("browse"));
    searchImg->setEnabled(false);
    //bottone inserimento immagine
    connect(searchImg,&QPushButton::clicked,[this](){
        QString path = QFileDialog::getOpenFileName(this->parentWidget(), "Select Image", "/home", "Image (*.jpeg *.jpg *.png)");
        if ( path.endsWith("jpg") || path.endsWith("png") || path.endsWith("jpeg") ) {
            this->path = path;
            QPixmap img(this->path);
            img64->setPixmap(img.scaled(80,80));
        }
    });

    test->addWidget(searchImg);
    addRow(tr("Immagine: "),test);

    addRow(tr("&Codice: "),cod);
    addRow(tr("&Nome: "),name);
    addRow(tr("&Casa Produttrice: "),casaProd);

    prezzo->setMaximum(900000);
    prezzo->setMinimum(0);
    prezzo->setDecimals(2);
    prezzo->setSuffix("€");

    addRow(tr("&Prezzo: "),prezzo);

    sconto->setMaximum(100);
    sconto->setMinimum(0);
    sconto->setSuffix("%");

    addRow(tr("&Sconto: "),sconto);
}
//funzione che imposta i campi del prodotto selezionato sulla Gui
void ProdDetails::showDet(Prodotto &prod)
{
    //funzione per pulire i campi nel caso si sia cambiato prodotto
    clear();
    this->prod = &prod;
    //imposto i nuovi parametri dei campi del nuovo prodotto
    cod->setText(QString::fromStdString(prod.GetCodice()));
    name->setText(QString::fromStdString(prod.GetNome()));
    casaProd->setText(QString::fromStdString(prod.GetCasaProd()));
    prezzo->setValue(prod.GetPrezzoInt());
    sconto->setValue(prod.GetDiscount());
    searchImg->setEnabled(true);
    /* uso la variabile "path" per ricordare il percorso dell'immagine e genero un QPixmap con "path"
     * faccio un controllo per vedere se esiste l'immagine così evito di avere warning di visualizzazione
     */
    path = QString::fromStdString(prod.GetImg());
    if(!QPixmap(path).isNull())
    img64->setPixmap(QPixmap(path).scaled(80,80));

    /* vari controlli per identificare il tipo a run time del Prodotto
     * per generare i campi necessari per ogni tipologia del Prodotto
     */
    if(typeid(prod).name()==typeid(ProdChimico).name() ||
            typeid(prod).name()==typeid(Shampoo).name() ||
            typeid(prod).name()==typeid(Tinte).name() ||
            typeid(prod).name()==typeid(ShamColor).name()){
        //faccio dynamic cast per avere i metodi del tipo dinamico
        auto temp = dynamic_cast<ProdChimico*>(*prod);

        //inserisco i parametri delle determinate classi del tipo dinamico
        quantita = new QSpinBox();
        quantita->setMaximum(5000);
        quantita->setMinimum(0);
        quantita->setSuffix(" mL");
        quantita->setValue(temp->GetQuantita());

        g1 = new QGroupBox();
        QHBoxLayout* hg1 = new QHBoxLayout();
        si = new QRadioButton(tr("&si"));
        no = new QRadioButton(tr("&no"));

        if(temp->GetTossico()){
            si->setChecked(true);
        }else{
            no->setChecked(true);
        }
        hg1->addWidget(si);
        hg1->addWidget(no);
        g1->setLayout(hg1);

        addRow(tr("&Quantita in mil: "), quantita);
        addRow(tr("&E' tossico: "),g1);

        //fine inserimento ripeto per ogni classe

    }

    if(typeid(prod).name()==typeid(Tinte).name() ||
            typeid(prod).name()==typeid(ShamColor).name()){
        auto temp = dynamic_cast<Tinte*>(*prod);

        tT = new QComboBox();
        tT->setObjectName("tT");
        numT = new QLineEdit();
        numT->setObjectName("numT");
        //creazione combobox per selezione tinta
        QStringList listTinte =  QStringList();
        for(int i=0; i<2;i++)
            listTinte << temp->getArrayTt()+(6*i);
        tT->addItems(listTinte);
        //setto l'indice corrente della combobox corrispondente al Tipo dell'oggetto
        const char* c = temp->getTipoTinta();
        int index = tT->findText(c);
        if(index != -1){
            tT->setCurrentIndex(index);
        }
        //fine comboBox
        //setto il numero Tinta
        numT->setText(QString::fromStdString(temp->getNumero()));

        addRow(tr("&Numero Tinta: "),numT);
        addRow(tr("&Tipo Tinta: "),tT);
    }

    if(typeid(prod).name()==typeid(Shampoo).name() ||
            typeid(prod).name()==typeid(ShamColor).name()){
        auto temp = dynamic_cast<Shampoo*>(*prod);

        tC = new QComboBox();
        tC->setObjectName("tC");
        tS = new QComboBox();
        tS->setObjectName("tS");

        QStringList listCapelli =  QStringList();
        QStringList listShampoo =  QStringList();

        for(int i=0; i<5;i++)
            listCapelli<< temp->getArrayTC()+(9*i);
        for(int i=0; i<6;i++)
            listShampoo<< temp->getArrayTS()+(15*i);

        tC->addItems(listCapelli);
        tS->addItems(listShampoo);
        //setto l'indice corrente della combobox corrispondente al Tipo dell'oggetto
        const char* cap = temp->getTipoCapelli();
        const char* sha = temp->getTipoShampoo();

        int indexCap = tC->findText(cap);
        int indexSha = tS->findText(sha);

        if(indexCap != -1 && indexSha != -1){
            tC->setCurrentIndex(indexCap);
            tS->setCurrentIndex(indexSha);
        }

        addRow(tr("&Tipo Capelli"),tC);
        addRow(tr("&Tipo Shampoo"),tS);
    }
}
//funzione di pulizia dei campi
void ProdDetails::clear()
{
    cod->clear();
    name->clear();
    casaProd->clear();
    prezzo->setValue(0.0);
    sconto->setValue(0);
    img64->setText("vuoto");
    path.clear();
    searchImg->setEnabled(false);
    /* vari controlli per identificare quale prodotto sto pulendo ed eliminare solo
     * i campi necessari. Senza questo controllo si avrebbero vari warning a terminale
     * per tentata rimozione di campi inesistenti
     */
    if(this->prod){
        if(typeid(*prod).name() == typeid(ProdChimico).name() ||
                typeid(*prod).name() == typeid(Tinte).name() ||
                typeid(*prod).name() == typeid(Shampoo).name() ||
                typeid(*prod).name() == typeid(ShamColor).name()){
            removeRow(g1);

            removeRow(quantita);
        }

        if(typeid(*prod).name() == typeid(Tinte).name() ||
                typeid(*prod).name() == typeid(ShamColor).name()){
            removeRow(tT);

            removeRow(numT);
        }

        if(typeid(*prod).name() == typeid(Shampoo).name() ||
                typeid(*prod).name() == typeid(ShamColor).name()){
            removeRow(tC);

            removeRow(tS);

        }
    }
    this->prod = nullptr;
}
//funzione per applicare le modifiche al prodotto
void ProdDetails::apply()
{
    //controllo nel caso il prodotto non sia selezionato
    if(!this->prod){
        QMessageBox::critical(this->parentWidget(),tr("Errore"),tr("Hai tentato modifiche ad un Prodotto inesistente!!!!"));
    }else{
        //controllo che ci sia almeno il nome e codice
        if(!this->cod->text().isEmpty() && !this->name->text().isEmpty()){
            this->prod->SetCodice(cod->text().toStdString());
            this->prod->SetNome(name->text().toStdString());
            this->prod->SetCasaProd(casaProd->text().toStdString());
            this->prod->SetPrezzo(prezzo->value());
            this->prod->SetDiscount(sconto->value());
            this->prod->SetImg64(this->path.toStdString());

            //vari controlli per individuare quali campi esistono in base al tipo run time del Prodotto
            if(typeid(*(this->prod)).name()==typeid(ProdChimico).name() ||
                    typeid(*(this->prod)).name()==typeid(Tinte).name() ||
                    typeid(*(this->prod)).name()==typeid(Shampoo).name() ||
                    typeid(*(this->prod)).name()==typeid(ShamColor).name()){
                //casto dinamicamente per ogni controllo per avere i metodi necessari a inserire i parametri
                auto temp = dynamic_cast<ProdChimico*>(this->prod);
                temp->SetQuantita(quantita->value());
                temp->SetTossico((si->isChecked())?true:false);
            }

            if(typeid(*(this->prod)).name()==typeid(Tinte).name() ||
                    typeid(*(this->prod)).name()==typeid(ShamColor).name()){
                auto temp = dynamic_cast<Tinte*>(this->prod);
                temp->setNumero(numT->text().toStdString());
                temp->setTt(tT->currentIndex());
            }

            if(typeid(*(this->prod)).name()==typeid(Shampoo).name() ||
                    typeid(*(this->prod)).name()==typeid(ShamColor).name()){
                auto temp = dynamic_cast<Shampoo*>(this->prod);
                temp->setTC(tC->currentIndex());
                temp->setTS(tS->currentIndex());
            }

        }
        else{
            //messaggio di notifica nel caso si lasci nome o codice vuoti
            QMessageBox::critical(this->parentWidget(),tr("Attenzione"),tr("Non hai inserito un codice o nome al prodotto"));
        }
        }

}

//simile al pulsante di pulizia ma questo non elimina i campi come su clear
 void ProdDetails::reset()
{
    cod->clear();
    name->clear();
    casaProd->clear();
    prezzo->setValue(0.0);
    sconto->setValue(0);
    path.clear();
    img64->clear();
    img64->setText("Vuoto");

    if(typeid(*(this->prod)).name() == typeid(ProdChimico).name()){
        quantita->setValue(0);
        si->setChecked(false);
        no->setChecked(true);
    }
    if(typeid(*(this->prod)).name() == typeid(Tinte).name()){
        tT->setCurrentIndex(0);
        numT->clear();
    }
    if(typeid(*(this->prod)).name() == typeid(Shampoo).name()){
        tC->setCurrentIndex(0);
        tS->setCurrentIndex(0);
    }
    if(typeid(*(this->prod)).name() == typeid(ShamColor).name()){
        tT->setCurrentIndex(0);
        numT->clear();
        tC->setCurrentIndex(0);
        tS->setCurrentIndex(0);
    }
    QString title("Reset Parmetri"),
            text("Ricordati di premere Apply se vuoi confermare il reset");

    QMessageBox::about(this->parentWidget(),title,text);


}

