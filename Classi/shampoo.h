#ifndef SHAMPOO_H
#define SHAMPOO_H
#include "prodchimico.h"

class Shampoo : virtual public ProdChimico
{
private:
    enum TipoCapelli { GENERALE, RICCI, LISCI, COLORATI, ROVITANTI};
    static char const tipocapelli_nome[9][4];
    enum TipoShampoo { VOLUMIZZANTE, ANTICADUTA, SEBOREGOLATORE, ANTIFORFORA, COLORANTE};
    static char const tiposhampoo_nome[20][4];
public:
    Shampoo() {}
    ~Shampoo() {}
    
    /*Set e Get*/
    TipoCapelli getTipoCapelli() const;
    TipoShampoo getTipoShampoo() const;

    void setTipoCapelli(const TipoCapelli& type);
    void setTipoShampoo(const TipoShampoo& type);
};
#endif // SHAMPOO_H
