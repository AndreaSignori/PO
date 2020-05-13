#ifndef PRODCHIMICO_H
#define PRODCHIMICO_H
#include "prodotto.h"

class ProdChimico : virtual public Prodotto
{
private:
    int quantitaml;
    bool tossico;

public:
    ProdChimico () {}
    ~ProdChimico () {}

    int GetQuantita();
    bool GetTossico() const;

    void SetTossico(bool toxic);
    void SetQuantita(int quantita);
};
#endif // PRODCHIMICO_H
