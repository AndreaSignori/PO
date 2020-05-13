#ifndef CONTAINER_H
#define CONTAINER_H
#include "prodotto.h"
#include <QObject>
#include <vector>

class Container
{
private:
    std::vector <Prodotto*> v;


public:
    Container();
    bool isEmpty() const;
    void modVett(int index, QObjectList* it);
    Prodotto* getProd(int index);
    ~Container() {}
};
#endif // CONTAINER_H
