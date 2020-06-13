#ifndef IO_CONTAINER_H
#define IO_CONTAINER_H
#include <type_traits>
#include "container.h"
#include "prodotto.h"
#include "dataaccobj.h"
#include "myexception.h"


class IO_Container : public DataAccObj
{
public:
    static QJsonObject fromProdToJson(const typename Container<Prodotto>::iterator& i);
    static Prodotto* fromJsonToProd(const QJsonObject& file);
    static QJsonObject fromContToJson(Container<Prodotto> *c);
    static void fromJsonToCont(const QJsonObject& file,Container<Prodotto> *c);
};

#endif // IO_CONTAINER_H
