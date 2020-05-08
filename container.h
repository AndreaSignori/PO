#ifndef CONTAINER_H
#define CONTAINER_H
#include "prodotto.h"
#include <QWidget>
#include <QtWidgets>

class Container : public QWidget
{
private:
    Prodotto *ptr;

public:
    Container(Prodotto *punt = nullptr, QWidget* parent = nullptr);

    ~Container();
};
#endif // CONTAINER_H
