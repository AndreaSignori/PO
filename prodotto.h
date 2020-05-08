#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <string>

class Prodotto
{
private:
    std::string codice;
    std::string nome;
    float prezzo;
    int discount;
    std::string casaprod;
    char foto;

public:
    Prodotto();
    Prodotto(int x);
    virtual ~Prodotto() = 0;
    std::string GetCodice() const;
    std::string GetNome() const;
    float GetPrezzo() const;
    int GetDiscount() const;
    void SetDiscount(int newdiscount);
};
#endif // PRODOTTO_H

