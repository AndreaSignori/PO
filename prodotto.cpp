#include "prodotto.h"
#include <algorithm>

using namespace std;
Prodotto::Prodotto(){

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

float Prodotto::GetPrezzo() const {
	return (prezzo*(100 - discount)) / 100;
}

float Prodotto::GetPrezzoEffettivo() const {
	return ((100 - discount) * prezzo) / 100;
}

int Prodotto::GetDiscount() const {
	return discount;
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
		casaprod = newcasaprod;
}

