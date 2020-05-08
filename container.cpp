#include "prodotto.h"
#include "container.h"

Container::Container(QWidget* parent ) : QWidget(parent){
    table = new QTableWidget(this);
    entryTable();

}

void Container::entryTable(){
    int i = 0;
    for(auto it = v.begin(); it != v.end(); ++it){

    }
}
