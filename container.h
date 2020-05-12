#ifndef CONTAINER_H
#define CONTAINER_H
#include "prodotto.h"
#include <QWidget>
#include <QtWidgets>
#include <QtCore>
#include <QTableWidget>
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
    Container(QWidget* parent = nullptr);

    ~Container() {}
};
#endif // CONTAINER_H
