#include "proddetails.h"
#include <iostream>
using namespace std;

ProdDetails::ProdDetails(QWidget *parent): QFormLayout(parent),prod(nullptr), name(new QLineEdit()), cod(new QLineEdit()), casaProd(new QLineEdit()), prezzo(new QLineEdit()), sconto(new QLineEdit()),quantita(new QLineEdit()),g1(new QGroupBox()),tC(new QComboBox()),tS(new QComboBox()),numT(new QLineEdit()),tT(new QComboBox())
{
    addRow(tr("&Codice: "),cod);
    addRow(tr("&Nome: "),name);
    addRow(tr("&Casa Produttrice: "),casaProd);
    addRow(tr("&Prezzo: "),prezzo);
    addRow(tr("&Sconto: "),sconto);

}

void ProdDetails::showDet(Prodotto &prod)
{
    clear();
    this->prod = &prod;
    cod->setText(QString::fromStdString(prod.GetCodice()));
    name->setText(QString::fromStdString(prod.GetNome()));
    casaProd->setText(QString::fromStdString(prod.GetCasaProd()));
    prezzo->setText(QString::number(prod.GetPrezzoInt()));
    sconto->setText(QString::number(prod.GetDiscount()));

    if(typeid(prod).name()==typeid(ProdChimico).name()){
        //faccio dynamic cast per avere i metodi del tipo dinamico
        auto temp = dynamic_cast<ProdChimico*>(*prod);

        //inserisco i parametri delle determinate classi del tipo dinamico

        quantita = new QLineEdit();
        quantita->setObjectName("quantita");
        quantita->setText(QString::number(temp->GetQuantita()));

        g1 = new QGroupBox();
        g1->setObjectName("g1");
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
    if(typeid(prod).name()==typeid(Tinte).name()){
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

        addRow(tr("&Nummero Tinta: "),numT);
        addRow(tr("&Tipo Tinta: "),tT);
    }
    if(typeid(prod).name()==typeid(Shampoo).name()){
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
    if(typeid(prod).name()==typeid(ShamColor).name()){
        auto temp = dynamic_cast<ShamColor*>(*prod);
        //parte Tinte

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

        //fine Tinte

        //parte SHAMPOO

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
        //fine Shampoo
    }


}

void ProdDetails::clear()
{
    cod->clear();
    name->clear();
    casaProd->clear();
    prezzo->clear();
    sconto->clear();

    //a causa di un remove forzato di ogni oggetto sulla console
    //verrà visualizzato un warning che l'elemento non esiste
    //e che quindi non può essere rimosso
    removeRow(g1);

    removeRow(quantita);

    removeRow(tT);

    removeRow(numT);

    removeRow(tC);

    removeRow(tS);

}

void ProdDetails::apply()
{
    this->prod->SetCodice(cod->text().toStdString());
    this->prod->SetNome(name->text().toStdString());
    this->prod->SetCasaProd(casaProd->text().toStdString());
    this->prod->SetPrezzo(prezzo->text().toFloat());
    this->prod->SetDiscount(sconto->text().toInt());

    if(typeid(*(this->prod)).name()==typeid(ProdChimico).name()){
        auto temp = dynamic_cast<ProdChimico*>(this->prod);
        temp->SetQuantita(quantita->text().toInt());
        temp->SetTossico((si->isChecked())?true:false);
    }
    if(typeid(*(this->prod)).name()==typeid(Tinte).name()){
        auto temp = dynamic_cast<Tinte*>(this->prod);
        temp->setNumero(numT->text().toStdString());
        temp->setTt(tT->currentIndex());
    }
    if(typeid(*(this->prod)).name()==typeid(Shampoo).name()){
        auto temp = dynamic_cast<Shampoo*>(this->prod);
        temp->setTC(tC->currentIndex());
        temp->setTS(tS->currentIndex());
    }
    if(typeid(*(this->prod)).name()==typeid(ShamColor).name()){
        auto temp = dynamic_cast<ShamColor*>(this->prod);
        temp->setNumero(numT->text().toStdString());
        temp->setTt(tT->currentIndex());
        temp->setTC(tC->currentIndex());
        temp->setTS(tS->currentIndex());
    }

}

 void ProdDetails::reset()
{
    cod->clear();
    name->clear();
    casaProd->clear();
    prezzo->clear();
    sconto->clear();

    if(typeid(*(this->prod)).name() == typeid(ProdChimico).name()){
        quantita->clear();
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
