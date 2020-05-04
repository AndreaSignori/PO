#ifndef PRODOTTO_H
#define PRODOTTO_H

class Prodotto
{
private:
    int id;
public:
    Prodotto() {}
    Prodotto(int x):id(int(x)) {}
    Prodotto(Prodotto* ptr) ;
    virtual int GetId() const{};
    virtual ~Prodotto() = 0;
};
#endif // PRODOTTO_H
