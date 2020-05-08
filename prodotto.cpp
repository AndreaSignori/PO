#include "prodotto.h"
#include <algorithm>

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

void Prodotto::SetCodice(string newcodice) {

}

void Prodotto::SetDiscount(int newdiscount = 0) {

<<<<<<< HEAD
	discount = min(100, max(0, newdiscount));
}
=======
}
>>>>>>> 17bd80ad569300e9e07a6d0323c160d43040292a
