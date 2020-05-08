#include "../ProgettoP2/PO/container.h"
#include <QWidget>

Container::Container(QWidget *parent): QWidget(parent)
{
    table = new QTableWidget(parent);
    table->setColumnCount(6);
    entryTable();
}

void Container::entryTable(){
    int i = 0;
    for(auto it = v.begin(); it != v.end(); ++it){
        QTableWidgetItem* item = new QTableWidgetItem((*it)->GetCodice());
        table->setItem(i,0,item);
    }
}


