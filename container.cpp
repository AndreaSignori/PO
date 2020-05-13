#include "../ProgettoP2/PO/container.h"
#include <strumento.h>
Container::Container(){
    v.push_back(new Strumento());
    v[0]->SetNome("Strum1");
    v[0]->SetCodice("1234");
    v[0]->SetPrezzo(12.3);
};


bool Container::isEmpty() const
{
    return v.empty();
}

void Container::modVett(int index, QObjectList *itF)
{

}

Prodotto *Container::getProd(int index)
{
    return v[index];
}
