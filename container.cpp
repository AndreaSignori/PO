#include "../ProgettoP2/PO/container.h"


Container::Container(QWidget *parent): QWidget(parent)
{
    dial = new QDialog(parent);
    table = new QTableWidget(parent);
    table->setColumnCount(6);

    entryTable();
    baseDial();
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);

    QHBoxLayout* hlay = new QHBoxLayout(this);
    hlay->addWidget(table);
    hlay->addWidget(dial);
    setLayout(hlay);
}

void Container::entryTable(){
    int i = 0;
    /*for(auto it = v.begin(); it != v.end(); ++it){
        QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString((*it)->GetCodice()));
        table->setItem(i,0,item);
    }*/
    QTableWidgetItem* item = new QTableWidgetItem("ciao");
    QTableWidgetItem* item1 = new QTableWidgetItem("ciao1");
    table->insertRow(0);
    table->setItem(0,0,item);
    table->setItem(0,1,item1);


}

void Container::baseDial()
{
    QLabel* la = new QLabel("Test",this);
    QLineEdit* le = new QLineEdit("nice",this);
    QVBoxLayout* vlay = new QVBoxLayout(this);

    vlay->addWidget(la);
    vlay->addWidget(le);
    vlay->setAlignment(Qt::AlignTop);
    dial->setLayout(vlay);

}


