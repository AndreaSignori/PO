#include <QtWidgets>
#include <QtCore>
#include <QMenuBar>
#include <QTabWidget>
#include "../ProgettoP2/PO/testwindow.h"

Windows::Windows(QWidget *parent) : QWidget(parent){
    cont = new Container();
    bBox = new QDialogButtonBox();
    createWindow();

}

void Windows::createWindow(){
    resize(800,600);
    lay = new QVBoxLayout(this);
    createMenuBar();
    createTabWidget();
    setLayout(lay);
}
void Windows::createMenuBar(){
    QMenuBar* mbar = new QMenuBar(this);

    //creazione voci menu
    QMenu* m1 = new QMenu("File",this);
    QMenu* m2 = new QMenu("Opion",this);
    QMenu* m3 = new QMenu("?",this);

    //creazione Azioni per voci menu
    //file
    QAction* a1 = new QAction("Open",this);
    QAction* a2 = new QAction("Save as",this);
    //Option
    QAction* a3 = new QAction("Tool",this);
    QAction* a4 = new QAction("Debug",this);
    //?
    QAction* a5 = new QAction("Info",this);
    //inserimento dei valori
    m1->addAction(a1);
    m1->addAction(a2);
    m2->addAction(a3);
    m2->addAction(a4);
    m3->addAction(a5);

    mbar->addMenu(m1);
    mbar->addMenu(m2);
    mbar->addMenu(m3);

    lay->addWidget(mbar);
}

void Windows::createTabWidget(){
    QTabWidget* tabwid = new QTabWidget(this);

    tabwid->addTab(createTab(), "Prodotti");
    //tabwid->addTab();
    //tabwid->addTab();


    lay->addWidget(tabwid);
}

QWidget* Windows::createTab(){
    QWidget* temp = new QWidget(nullptr);
    //codice di prova per la table
    QHBoxLayout* layH = new QHBoxLayout(temp);
    table = new QTableWidget(0,5,temp);

    setUpTable();

    layH->addWidget(table);
    //inserimento del form laterale per dati
    layH->addWidget(createForm());

    temp->setLayout(layH);
    return temp;
}

QWidget* Windows::createForm(){
    QWidget* temp = new QWidget();

    QVBoxLayout* mainTempLay = new QVBoxLayout(temp);

    layF = new QFormLayout();

    for(int i = 0; i < table->columnCount(); i++ )
    {
        //layF->addWidget(new QLabel(table->horizontalHeaderItem(i)->text()+":"));
        if(table->item(table->currentRow(),i)){
            layF->addRow(new QLabel(table->horizontalHeaderItem(i)->text()),new QLineEdit(table->item(table->currentRow(),i)->text()));
        }else{
            layF->addRow(new QLabel(table->horizontalHeaderItem(i)->text()),new QLineEdit(" ",this));
        }

    }
    //QTextEdit* item1 = new QTextEdit(,temp);

    QSizePolicy pForm(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pForm.setHorizontalStretch(2);
    temp->setSizePolicy(pForm);

    bBox->addButton(tr("Modifica"),
                         QDialogButtonBox::ApplyRole);
    bBox->addButton(tr("Elimina"),
                         QDialogButtonBox::RejectRole);
    bBox->addButton(tr("Inserisci"),QDialogButtonBox::AcceptRole);

    connect(bBox, SIGNAL(QDialogButtonBox::clicked(QDialogButtonBox::ApplyRole)),
            this, SLOT(accept()));
    /*connect(bBox, SIGNAL(rejected()),
            this, SLOT(reject()));
    connect(bBox->button(QDialogButtonBox::Reset),
            SIGNAL(clicked()), this, SLOT(reset()));
*/
    mainTempLay->addLayout(layF);
    mainTempLay->addWidget(bBox);
    temp->setLayout(mainTempLay);

    return temp;
}

void Windows::setUpTable()
{
    table->setAutoScroll(true);
    table->QAbstractItemView::SelectRows;
    table->setSelectionBehavior(QAbstractItemView::SelectRows );

    //header della tabella

    table->setHorizontalHeaderItem(0,new QTableWidgetItem(tr("Codice")));
    table->setHorizontalHeaderItem(1,new QTableWidgetItem(tr("Nome")));
    table->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("Prezzo")));
    table->setHorizontalHeaderItem(3,new QTableWidgetItem(tr("Sconto")));
    table->setHorizontalHeaderItem(4,new QTableWidgetItem(tr("Casa Prod.")));

    //inserimento delle righe nella tabella

    if(cont->isEmpty()){
        table->insertRow(table->rowCount());
        table->selectRow(0);

    }else
    {

    }

    QSizePolicy* pTable = new QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pTable->setHorizontalStretch(3);
    table->setSizePolicy(*pTable);



}
void Windows::popUP(){
    QMessageBox::information(0, QString("Information"), QString("You've pressed the button Act"), QMessageBox::Ok);
}

void Windows::accept()
{
    for(auto *it = layF->children().begin(); it != layF->children().end(); it++){
        if(dynamic_cast<QLineEdit*> (*it)){

        }
    }
}
