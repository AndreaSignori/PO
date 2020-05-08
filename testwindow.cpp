#include <QtWidgets>
#include <QtCore>
#include <QMenuBar>
#include <QTabWidget>
#include "../ProgettoP2/PO/testwindow.h"

Windows::Windows(QWidget *parent) : QWidget(parent){
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
    QTableWidget* table = new QTableWidget(10,10,temp);
    table->setAutoScroll(true);
    table->QAbstractItemView::SelectRows;
    QTableWidgetItem* item1 = new QTableWidgetItem("Ciao",0);
    table->setItem(0,0,item1);
    layH->addWidget(table);
    //inserimento del form laterale per dati
    layH->addWidget(createForm());

    temp->setLayout(layH);
    return temp;
}

QWidget* Windows::createForm(){
    QWidget* temp = new QWidget(nullptr);
    QVBoxLayout* layF = new QVBoxLayout(temp);

    QTextEdit* item1 = new QTextEdit("Ciao",temp);


    layF->addWidget(item1);


    temp->setLayout(layF);

    return temp;
}
void Windows::popUP(){
    QMessageBox::information(0, QString("Information"), QString("You've pressed the button Act"), QMessageBox::Ok);
}
