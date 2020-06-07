#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <myexception.h>
#include <string>

class Prodotto
{
private:
    std::string codice, nome, casaProd, img64;
    float prezzo;
    int discount;
public:
    Prodotto(std::string c = "", std::string n = "", std::string cP = "",std::string img = "", float p = 0.0 , int dis = 0);

    virtual ~Prodotto() = 0;


    std::string GetCodice() const;
    std::string GetNome() const;
    float GetPrezzoInt() const;
    int GetDiscount() const;
    std::string GetCasaProd() const;
    std::string GetImg() const;

    void SetImg64(std::string img);
    void SetCodice(std::string newcodice);
    void SetNome(std::string newnome);
    void SetPrezzo(float newprezzo);
    void SetDiscount(int newdiscount);
    void SetCasaProd(std::string casaprod);

    float GetPrezzoEffettivo() const;

    virtual Prodotto* operator*();
};

class ProdChimico : virtual public Prodotto
{
private:
    int quantitaml;
    bool tossico;

public:
    ProdChimico(std::string c = "", std::string n = "", std::string cP = "",std::string img = "", float p = 0.0 , int dis = 0, int q = 0, bool tx = false) ;
    ProdChimico(const ProdChimico *pC);

    ~ProdChimico() ;

    int GetQuantita() const;
    bool GetTossico() const;

    void SetTossico(bool toxic);
    void SetQuantita(int quantita);

    //clone
    virtual ProdChimico* clone() const;

    //overload
    virtual ProdChimico& operator=(const ProdChimico& pC);
    virtual ProdChimico* operator*();
};

class Shampoo : virtual public ProdChimico
{
protected:
    enum TipoCapelli { GENERALE, RICCI, LISCI, COLORATI, ROVINATI };
    enum TipoShampoo { GENERICO, VOLUMIZZANTE, ANTICADUTA, SEBOREGOLATORE, ANTIFORFORA, COLORANTE };
private:

    static char const tipocapelli_nome[5][9];

    static char const tiposhampoo_nome[6][15];

    TipoCapelli tC;
    TipoShampoo tS;

public:
    Shampoo(std::string c = "", std::string n = "", std::string cP = "",std::string img = "", float p = 0.0 , int dis = 0,int q = 0, bool tx = false,TipoCapelli cap = TipoCapelli::GENERALE, TipoShampoo s = TipoShampoo::GENERICO);
    Shampoo(const Shampoo* s);


    ~Shampoo() { }

    /*Set e Get*/
    TipoCapelli getTC() const;
    TipoShampoo getTS() const;

    void setTC(int x);
    void setTS(int x);

    const char* getTipoCapelli() const;
    const char* getTipoShampoo() const;

    void setTipoCapelli(const TipoCapelli& type);
    void setTipoShampoo(const TipoShampoo& type);

    const char* getArrayTC() const;
    const char* getArrayTS() const;

    virtual Shampoo* clone() const;

    //overload
    virtual Shampoo& operator =(const Shampoo& s);
    virtual Shampoo* operator*();
};

class Tinte : virtual public ProdChimico
{
protected:
    enum TipoTinta{OLIO, CREMA};
private:

    std::string numero;
    static char const tipoT[2][6];
    TipoTinta tt;

public:

    Tinte(std::string c = "", std::string n = "", std::string cP = "",std::string img = "", float p = 0.0 , int dis = 0, int q = 0, bool tx = false, std::string num = "", TipoTinta t = TipoTinta::OLIO );
    Tinte(const Tinte* t);
    ~Tinte() {}

    std::string getNumero() const;
    TipoTinta getTt() const;
    void setTt(int x);

    void setNumero(const std::string &value);
    void setTt(const TipoTinta &value);

    const char* getTipoTinta() const;
    const char* getArrayTt() const;

    //overload
    virtual Tinte* clone() const;
    virtual Tinte& operator =(const Tinte& t);
    virtual Tinte* operator*();
};

class ShamColor : public Tinte, public Shampoo
{
private:

public:
    ShamColor(std::string c = "", std::string n = "", std::string cP = "",std::string img = "", float p = 0.0 , int dis = 0, int q = 0, bool tx = false, std::string num = "", TipoTinta t = TipoTinta::CREMA, TipoCapelli cap = TipoCapelli::GENERALE, TipoShampoo s = TipoShampoo::GENERICO);
    ShamColor(const ShamColor* sC);
    ~ShamColor() {}

    virtual ShamColor* clone() const;

    //overload
    virtual ShamColor& operator =(const ShamColor& sC);
    virtual ShamColor* operator*();
};
#endif // PRODOTTO_H

