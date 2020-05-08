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

<<<<<<< HEAD
void Prodotto::SetDiscount(int newdiscount) {
    /*if (newdiscount || newdiscount < 0) {
		discount = 0;
		return;
	}
	if (newdiscount > 100) {
		discount = 100;
		return;
	}
	discount = newdiscount;
    return;*/
    switch (newdiscount) {
    case ( < 0):
        discount = 0;
        break;
    case (newdiscount > 100):
        discount = 100;
    break;
    default:
        discount = newdiscount;
        break;
    }
=======
void Prodotto::SetCodice(string newcodice) {

}

void Prodotto::SetDiscount(int newdiscount = 0) {
	switch (newdiscount)
	{
	case <= 0: 
		break;
	default:
		break;
	}
>>>>>>> 48dbae5ac0a053ec1b52f48df843c5a0f8b8f7ed
}
