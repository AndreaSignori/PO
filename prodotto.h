#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <string>
#include <QWidget>
class Prodotto
{
private:
    std::string codice;
    std::string nome;
    float prezzo;
    int discount = 0;
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

    void SetCodice(std::string newcodice);
    void SetNome(std::string newnome);
    void SetPrezzo(float newprezzo);
    void SetDiscount(int newdiscount);
    void SetCasaProd(std::string casaprod);
    void SetFoto(char path);

};
#endif // PRODOTTO_H

