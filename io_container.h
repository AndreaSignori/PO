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
    /*
     *
     * La classe IO_Container è fondamentale al corretto funzionamento del programma in quanto
     * è suo scopo gestile l'input e output del container su file, essa infatti utilizza i metodi
     * della classe DAO (dataccobj) per popolare il container nel caso di un caricamento da file o
     * di trasformare i dati di un Container di prodotti in stringhe che verranno utilizzate per
     * popolare il file JSon
     *
     */
    static QJsonObject fromProdToJson(const typename Container<Prodotto>::iterator& i);
    static Prodotto* fromJsonToProd(const QJsonObject& file);
    static QJsonObject fromContToJson(Container<Prodotto> *c);
    static void fromJsonToCont(const QJsonObject& file,Container<Prodotto> *c);
};

#endif // IO_CONTAINER_H
