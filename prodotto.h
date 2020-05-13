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
    char path;

public:
    Prodotto();
    Prodotto(int x);
    virtual ~Prodotto() = 0;
    std::string GetCodice() const;
    std::string GetNome() const;
    float GetPrezzoInt() const;
    int GetDiscount() const;
    float GetPrezzo() const;
    float GetPrezzoEffettivo() const;


    void SetCodice(std::string newcodice);
    void SetNome(std::string newnome);
    void SetPrezzo(float newprezzo);
    void SetDiscount(int newdiscount);
    void SetCasaProd(std::string casaprod);
    void SetFoto(std::string newpath);

};
#endif // PRODOTTO_H

