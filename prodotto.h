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

