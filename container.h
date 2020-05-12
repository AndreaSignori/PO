#ifndef CONTAINER_H
#define CONTAINER_H
#include "prodotto.h"

#include <vector>

class Container
{
private:
    std::vector <Prodotto*> v;


public:
    Container();
    bool isEmpty() const;
    ~Container() {}
};
#endif // CONTAINER_H
