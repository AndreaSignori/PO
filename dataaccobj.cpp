
#include "myexception.h"
#include "dataaccobj.h"
#include "iostream"

static string filename;

QJsonObject DataAccObj::fromStringToJson(const std::string &stringa)   {
    return QJsonDocument().fromJson(QString::fromStdString(stringa).toUtf8()).object();
}

void DataAccObj::setFile(const QJsonObject &json)   {
    QJsonDocument document;
    document.setObject(json);
    QFile jsonFile;
    if(filename != ""){
        QFile jsonFile(QString::fromStdString(filename));
        jsonFile.open(QFile::WriteOnly);
        jsonFile.write(document.toJson());
    }
    else    {
        QFile jsonFile(QString::fromStdString("prodotti.json"));
        jsonFile.open(QFile::WriteOnly);
        jsonFile.write(document.toJson());
    }
}

QJsonObject DataAccObj::getFile()   {
    QFile jfile(QString::fromStdString(filename));
    jfile.open(QFile::ReadOnly);
    if(!jfile.isReadable())
        throw MyException("Impossibile leggere il file");
    return QJsonDocument().fromJson(jfile.readAll()).object();
}

string DataAccObj::getPath()    {
    return filename;
}

void DataAccObj::setPath(const std::string &path)   {
    filename = path;
}
