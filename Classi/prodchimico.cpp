#include "prodchimico.h"

using namespace std;

bool ProdChimico::GetTossico() const {
	return tossico;
}

int ProdChimico::GetQuantita() const {
	return quantitaml;
}

void ProdChimico::SetTossico(bool toxic) {
	tossico = toxic;
}

void ProdChimico::SetQuantita(int quantita) {
	quantitaml = quantita;
}