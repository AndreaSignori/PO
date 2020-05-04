#ifndef CONTAINER_H
#define CONTAINER_H
#include "prodotto.h"
class Container
{
private:
    Prodotto *ptr;
public:
    Container(Prodotto *punt = nullptr){};

    ~Container();
};
#endif // CONTAINER_H
