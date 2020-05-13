#include "prodchimico.h"

using namespace std;

bool ProdChimico::GetTossico() const {
	return tossico;
}

int ProdChimico::GettQuantita() const {
	return quantitaml;
}

void SetTossico(bool toxic) {
	tossico = toxic;
}

void SetQuantita(int quantita) {
	quantitaml = quantita;
}