#include "prodotto.h"
#include <algorithm>
#include <iostream>
using namespace std;

const char Shampoo::tipocapelli_nome[5][9] = {"GENERALE","RICCI","LISCI","COLORATI","ROVINATI"};
const char Shampoo::tiposhampoo_nome[6][15] = {"GENERICO","VOLUMIZZANTE","ANTICADUTA","SEBOREGOLATORE","ANTIFORFORA","COLORANTE"};
const char Tinte::tipoT[2][6] = {"OLIO", "CREMA"};

//Prodotto
Prodotto::Prodotto(string c , string n , string cP ,string img, float p , int dis):
    codice(c),
    nome(n),
    casaProd(cP),
    img64(img),
    prezzo(p),
    discount(dis)
{
    if(discount>100){
        throw MyException("Hai uno sconto pazzesco");
    }
}

Prodotto::~Prodotto()
{

}

std::string Prodotto::GetCodice() const {
    return codice;
}

std::string Prodotto::GetNome() const {
    return nome;
}

float Prodotto::GetPrezzoInt() const {
    return prezzo;
}

float Prodotto::GetPrezzoEffettivo() const {
    return (prezzo*(100 - discount)) / 100;
}

int Prodotto::GetDiscount() const {
    return discount;
}

string Prodotto::GetCasaProd() const
{
    return casaProd;
}

string Prodotto::GetImg() const
{
    return img64;
}

void Prodotto::SetImg64(string img)
{
    img64 = img;
}

void Prodotto::SetCodice(string newcodice) {
    if (newcodice != "")
        codice = newcodice;
}

void Prodotto::SetNome(string newnome) {
    if (newnome != "")
        nome = newnome;
}

void Prodotto::SetPrezzo(float newprezzo) {
    if (newprezzo >= 0.0)
        prezzo = newprezzo;
}

void Prodotto::SetDiscount(int newdiscount = 0) {
    discount = min(100, max(0, newdiscount));
}

void Prodotto::SetCasaProd(string newcasaprod) {
    if (newcasaprod != "")
        casaProd = newcasaprod;
}

//Prodotto Chimico
ProdChimico::ProdChimico(string c , string n , string cP ,string img, float p , int dis,int q, bool tx):
    Prodotto(c,n,cP,img,p,dis),
    quantitaml(q),
    tossico(tx)
{

}

ProdChimico::ProdChimico(const ProdChimico *pC):
    Prodotto(pC->GetCodice(),pC->GetNome(),pC->GetCasaProd(),pC->GetImg(),pC->GetPrezzoInt(),pC->GetDiscount()),
    quantitaml(pC->GetQuantita()),
    tossico(pC->GetTossico())
{

}

ProdChimico::~ProdChimico(){}

int ProdChimico::GetQuantita() const
{
    return quantitaml;
}

bool ProdChimico::GetTossico() const
{
    return tossico;
}

void ProdChimico::SetTossico(bool toxic)
{
    tossico = toxic;
}

void ProdChimico::SetQuantita(int quantita)
{
    quantitaml = quantita;
}

ProdChimico *ProdChimico::clone() const
{
    return new ProdChimico(this);
}

ProdChimico &ProdChimico::operator=(const ProdChimico &pC)
{
    this->SetCodice(pC.GetCodice());
    this->SetNome(pC.GetNome());
    this->SetCasaProd(pC.GetCasaProd());
    this->SetPrezzo(pC.GetPrezzoInt());
    this->SetDiscount(pC.GetDiscount());
    this->SetImg64(pC.GetImg());
    this->SetQuantita(pC.GetQuantita());
    this->SetTossico(pC.GetTossico());
    return *this;

}

ProdChimico *ProdChimico::operator*()
{
    return this;
}

//shampoo
Shampoo::Shampoo(string c, string n, string cP, string img, float p, int dis,int q, bool tx,TipoCapelli cap, TipoShampoo s):
    Prodotto(c,n,cP,img,p,dis),
    ProdChimico(c,n,cP,img,p,dis,q,tx),tC(cap),
    tS(s)
{

}

Shampoo::Shampoo(const Shampoo *s):
    Prodotto(s->GetCodice(),s->GetNome(),s->GetCasaProd(),s->GetImg(),s->GetPrezzoInt(),s->GetDiscount()),
    ProdChimico(s->GetCodice(),s->GetNome(),s->GetCasaProd(),s->GetImg(),s->GetPrezzoInt(),s->GetDiscount(),s->GetTossico(),s->GetQuantita()),
    tC(s->getTC()),
    tS(s->getTS()){}

Shampoo::TipoCapelli Shampoo::getTC() const
{
    return tC;
}

Shampoo::TipoShampoo Shampoo::getTS() const
{
    return tS;
}

const char* Shampoo::getTipoCapelli() const
{
    return Shampoo::tipocapelli_nome[tC];
}

const char* Shampoo::getTipoShampoo() const
{
    return Shampoo::tiposhampoo_nome[tS];
}

void Shampoo::setTipoCapelli(const Shampoo::TipoCapelli &type)
{
    Shampoo::tC = type;
}

void Shampoo::setTipoShampoo(const Shampoo::TipoShampoo &type)
{
    Shampoo::tS = type;
}

Shampoo *Shampoo::clone() const
{
    return new Shampoo(this);
}

Shampoo &Shampoo::operator =(const Shampoo &s)
{
    this->SetCodice(s.GetCodice());
    this->SetNome(s.GetNome());
    this->SetCasaProd(s.GetCasaProd());
    this->SetPrezzo(s.GetPrezzoInt());
    this->SetDiscount(s.GetDiscount());
    this->SetImg64(s.GetImg());
    this->SetQuantita(s.GetQuantita());
    this->SetTossico(s.GetTossico());
    this->setTipoCapelli(s.getTC());
    this->setTipoShampoo(s.getTS());
    return *this;
}

Shampoo *Shampoo::operator*()
{
    return this;
}

//tinte
std::string Tinte::getNumero() const
{
    return numero;
}

void Tinte::setNumero(const std::string &value)
{
    numero = value;
}

Tinte::TipoTinta Tinte::getTt() const
{
    return tt;
}

void Tinte::setTt(const TipoTinta &value)
{
    tt = value;
}

Tinte::Tinte(string c, string n, string cP, string img, float p, int dis, int q, bool tx, string num, Tinte::TipoTinta t):
    Prodotto(c,n,cP,img,p,dis),
    ProdChimico(c,n,cP,img,p,dis,q,tx),
    numero(num),
    tt(t)
{
    if(numero.length()>4){
        throw MyException("Codice tinta non valido, ha un massimo di 4 caratteri");
    }
}

Tinte::Tinte(const Tinte *t):
    Prodotto(t->GetCodice(),t->GetNome(),t->GetCasaProd(),t->GetImg(),t->GetPrezzoInt(),t->GetDiscount()),
    ProdChimico(t->ProdChimico::clone()),
    numero(t->getNumero()),
    tt(t->getTt())
{

}

Tinte *Tinte::clone() const
{
    return new Tinte(this);
}

Tinte &Tinte::operator =(const Tinte& t)
{
    this->SetCodice(t.GetCodice());
    this->SetNome(t.GetNome());
    this->SetCasaProd(t.GetCasaProd());
    this->SetPrezzo(t.GetPrezzoInt());
    this->SetDiscount(t.GetDiscount());
    this->SetImg64(t.GetImg());
    this->SetQuantita(t.GetQuantita());
    this->SetTossico(t.GetTossico());
    this->setNumero(t.getNumero());
    this->setTt(t.getTt());
    return *this;
}

Tinte *Tinte::operator*()
{
    return this;
}

//shamColor
ShamColor::ShamColor(string c, string n, string cP, string img, float p, int dis, int q, bool tx, string num, Tinte::TipoTinta t, Shampoo::TipoCapelli cap, Shampoo::TipoShampoo s):
    Prodotto(c,n,cP,img,p,dis),
    ProdChimico(c,n,cP,img,p,dis,q,tx),
    Tinte(c,n,cP,img,p,dis,q,tx,num,t),
    Shampoo(c,n,cP,img,p,dis,q,tx,cap,s) {}

ShamColor::ShamColor(const ShamColor *sC):
    Prodotto(sC->GetCodice(),sC->GetNome(),sC->GetCasaProd(),sC->GetImg(),sC->GetPrezzoInt(),sC->GetDiscount()),
    ProdChimico(sC->ProdChimico::clone()),
    Tinte(sC->Tinte::clone()),
    Shampoo(sC->Shampoo::clone())
{

}

ShamColor *ShamColor::clone() const
{
    return new ShamColor(this);
}
ShamColor &ShamColor::operator =(const ShamColor& sC)
{
    this->SetCodice(sC.GetCodice());
    this->SetNome(sC.GetNome());
    this->SetCasaProd(sC.GetCasaProd());
    this->SetPrezzo(sC.GetPrezzoInt());
    this->SetDiscount(sC.GetDiscount());
    this->SetImg64(sC.GetImg());
    this->SetQuantita(sC.GetQuantita());
    this->SetTossico(sC.GetTossico());
    this->setTipoCapelli(sC.getTC());
    this->setTipoShampoo(sC.getTS());
    this->setNumero(sC.getNumero());
    this->setTt(sC.getTt());
    return *this;
}

ShamColor *ShamColor::operator*()
{
    return this;
}
