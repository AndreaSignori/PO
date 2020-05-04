#include "prodotto.h"
#include <iostream>

using namespace std;

Prodotto::Prodotto(Prodotto *ptr){
    id = ptr->GetId();
}
