#ifndef CONTAINER_H
#define CONTAINER_H
#include "prodotto.h"
#include <QWidget>
#include <QtWidgets>
#include <vector>

class Container : public QWidget
{
private:
    std::vector <Prodotto*> v;
    QTableWidget* table;
    QDialog* dial;
    void entryTable();
    void baseDial();
public:
    Container(QWidget* parent = 0);

    ~Container() {};
};
#endif // CONTAINER_H
