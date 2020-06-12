#include "io_container.h"

QJsonObject IO_Container::fromProdToJson(const typename Container<Prodotto>::iterator &i) const {
    QJsonObject file;
    file["type"] = typeid(&i).name();
    ProdChimico const *PCptr = dynamic_cast<const ProdChimico*>(&*i);
    if(PCptr != nullptr)    {
        file["codice"] = QString::fromStdString(PCptr->GetCodice());
        file["nome"] = QString::fromStdString(PCptr->GetNome());
        file["casaProd"] = QString::fromStdString(PCptr->GetCasaProd());
        file["img64"] = QString::fromStdString(PCptr->GetImg());
        file["prezzo"] = PCptr->GetPrezzoInt();
        file["discount"] = PCptr->GetDiscount();
        file["quantitaml"] = PCptr->GetQuantita();
        file["istoxic"] = PCptr->GetTossico();
        Shampoo const *SHptr = dynamic_cast<const Shampoo*>(&*i);
        Tinte const *TTptr = dynamic_cast<const Tinte*>(&*i);
        if(SHptr != nullptr)    {
            file["tipoCap"] = static_cast<QString>(SHptr->getTipoCapelli());
            file["tipoSha"] = static_cast<QString>(SHptr->getTipoShampoo());
        }
        if(TTptr != nullptr)    {
            file["numero"] = QString::fromStdString(TTptr->getNumero());
            file["tipoTT"] = static_cast<QString>(TTptr->getTipoTinta());
        }
    }
    return file;
}
