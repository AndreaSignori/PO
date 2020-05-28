#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <string>

class Prodotto
{
private:
    std::string codice;
    std::string nome;
    float prezzo;
    int discount = 0;
    std::string casaprod;
    std::string img64;
public:
    Prodotto();
    Prodotto(int x);
    virtual ~Prodotto() = 0;

    
    std::string GetCodice() const;
    std::string GetNome() const;
    float GetPrezzoInt() const;
    int GetDiscount() const;
    std::string GetCasaProd() const;
    std::string getImg() const;


    void SetCodice(std::string newcodice);
    void SetNome(std::string newnome);
    void SetPrezzo(float newprezzo);
    void SetDiscount(int newdiscount);
    void SetCasaProd(std::string casaprod);

    float GetPrezzoEffettivo() const;
};
#endif // PRODOTTO_H

class ProdChimico : virtual public Prodotto
{
private:
    int quantitaml;
    bool tossico;

public:
    ProdChimico() {}
    ~ProdChimico() {}

    int GetQuantita() const;
    bool GetTossico() const;

    void SetTossico(bool toxic);
    void SetQuantita(int quantita);
};

class Attrezzatura : virtual public Prodotto
{
private:

public:
    Attrezzatura() {}

    ~Attrezzatura() {}
};

class Shampoo : virtual public ProdChimico
{
private:
    enum TipoCapelli { GENERALE, RICCI, LISCI, COLORATI, ROVITANTI };
    static char const tipocapelli_nome[9][4];
    enum TipoShampoo { VOLUMIZZANTE, ANTICADUTA, SEBOREGOLATORE, ANTIFORFORA, COLORANTE };
    static char const tiposhampoo_nome[20][4];
public:
    Shampoo() {}
    ~Shampoo() {}

    /*Set e Get*/
    TipoCapelli getTipoCapelli() const;
    virtual TipoShampoo getTipoShampoo() const;

    void setTipoCapelli(const TipoCapelli& type);
    void setTipoShampoo(const TipoShampoo& type);
};

class Tinte : virtual public ProdChimico
{
private:

public:
    Tinte() {}

    ~Tinte() {}
};

class ShamColor : public Tinte, public Shampoo
{
private:

public:
    ShamColor() {}

    ~ShamColor() {}
};

class Strumento : public Attrezzatura
{
private:

public:
    Strumento() {};

    ~Strumento() {};
};

class Accessorio : public Attrezzatura
{
private:

public:
    Accessorio() {}

    ~Accessorio() {}
};
