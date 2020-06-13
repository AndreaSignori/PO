#include "io_container.h"

QJsonObject IO_Container::fromProdToJson(const typename Container<Prodotto>::iterator &i) {
    QJsonObject file;
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
        file["type"] = typeid(ProdChimico).name();
        Shampoo const *SHptr = dynamic_cast<const Shampoo*>(&*i);
        Tinte const *TTptr = dynamic_cast<const Tinte*>(&*i);
        if(SHptr != nullptr)    {
            file["tipoCap"] = static_cast<QString>(SHptr->getTipoCapelli());
            file["tipoSha"] = static_cast<QString>(SHptr->getTipoShampoo());
            file["type"] = typeid(Shampoo).name();
        }
        if(TTptr != nullptr)    {
            file["numero"] = QString::fromStdString(TTptr->getNumero());
            file["tipoTT"] = static_cast<QString>(TTptr->getTipoTinta());
            file["type"] = typeid(Tinte).name();
        }
        if(TTptr != nullptr && SHptr != nullptr)
            file["type"] = typeid(ShamColor).name();
    }
    return file;
}

Prodotto* IO_Container::fromJsonToProd(const QJsonObject &file)  {
    auto tiposalvato = file["type"].toString();
    Prodotto* newprod;
    if(tiposalvato == typeid(ProdChimico).name())
        newprod = new ProdChimico(file["codice"].toString().toStdString(),file["nome"].toString().toStdString(),file["casaprod"].toString().toStdString(),file["img64"].toString().toStdString(),file["prezzo"].toDouble(),file["discount"].toInt(),file["quantitaml"].toInt(),file["istoxic"].toBool());
    if(tiposalvato == typeid(Shampoo).name())
        newprod = new Shampoo(file["codice"].toString().toStdString(),file["nome"].toString().toStdString(),file["casaprod"].toString().toStdString(),file["img64"].toString().toStdString(),file["prezzo"].toDouble(),file["discount"].toInt(),file["quantitaml"].toInt(),file["istoxic"].toBool(),(TipoCapelli)file["tipoCap"].toInt(),(TipoShampoo)file["tipoSha"].toInt());
    if(tiposalvato == typeid(Tinte).name())
        newprod = new Tinte(file["codice"].toString().toStdString(),file["nome"].toString().toStdString(),file["casaprod"].toString().toStdString(),file["img64"].toString().toStdString(),file["prezzo"].toDouble(),file["discount"].toInt(),file["quantitaml"].toInt(),file["istoxic"].toBool(), file["numero"].toString().toStdString(), (TipoTinta)file["tipoTT"].toInt());
    if(tiposalvato == typeid(ShamColor).name())
        newprod = new ShamColor(file["codice"].toString().toStdString(),file["nome"].toString().toStdString(),file["casaprod"].toString().toStdString(),file["img64"].toString().toStdString(),file["prezzo"].toDouble(),file["discount"].toInt(),file["quantitaml"].toInt(),file["istoxic"].toBool(),file["numero"].toString().toStdString(), (TipoTinta)file["tipoTT"].toInt(),(TipoCapelli)file["tipoCap"].toInt(),(TipoShampoo)file["tipoSha"].toInt());
    return newprod;
}

QJsonObject IO_Container::fromContToJson(Container<Prodotto> *c) {
    QJsonObject file;
    QJsonArray vet;
    for (auto it = c->begin(); it; ++it )
        vet.append(fromProdToJson(it));
    file["data"] = vet;
    return file;
}

void IO_Container::fromJsonToCont(const QJsonObject &file,Container<Prodotto> *c)   {
    QJsonArray vet = file["data"].toArray();
    for(int i = 0; i < vet.size(); i++)
        c->push_front(fromJsonToProd(vet[i].toObject()));
        //fromJsonToProd(vet[i].toObject());
}

