#include "../ProgettoP2/PO/container.h"

Container::Container(){};


bool Container::isEmpty() const
{
    return v.empty();
}

void Container::modVett(int index, QObjectList *itF)
{
    for(auto it = itF->begin(); it != itF.end() ; it++)
    {
        if(dynamic_cast <QLineEdit*> (it)){

        }
    }
}
