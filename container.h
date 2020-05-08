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
    void entryTable();
public:
    Container(QWidget* parent = nullptr);

    ~Container();
};
#endif // CONTAINER_H
