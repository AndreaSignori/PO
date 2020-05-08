#include "prodotto.h"

using namespace std;

std::string Prodotto::GetCodice() const {
	return codice;
}

std::string Prodotto::GetNome() const {
	return nome;
}

float Prodotto::GetPrezzo() const {
	return prezzo;
}

int Prodotto::GetDiscount() const {
	return discount;
}

void Prodotto::SetDiscount(int newdiscount) {
	if (newdiscount || newdiscount < 0) {
		discount = 0;
		return;
	}
	if (newdiscount > 100) {
		discount = 100;
		return;
	}
	discount = newdiscount;
	return;
}
