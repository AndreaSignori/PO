#ifndef IO_CONTAINER_H
#define IO_CONTAINER_H
#include <type_traits>
#include "container.h"
#include "prodotto.h"
#include "dataaccobj.h"
#include "myexception.h"


class IO_Container : virtual public Container<Prodotto>, public DataAccObj
{
public:
    QJsonObject fromProdToJson(const typename Container<Prodotto>::iterator& i) const;
    void fromJsonToProd(const QJsonObject& file);
    using Container<Prodotto>::Container;
    QJsonObject fromContToJson() const;
    void fromJsonToCont(const QJsonObject& file);
};

#endif // IO_CONTAINER_H
