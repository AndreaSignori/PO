#include <QFile>
#include <QJsonDocument>
#include "myexception.h"
#include "dataaccobj.h"

static string filename;

QJsonObject DataAccObj::fromStringToJson(const std::string &stringa)   {
    return QJsonDocument().fromJson(QString::fromStdString(stringa).toUtf8()).object();
}

void DataAccObj::setFile(const QJsonObject &file)   {
    QFile jfile(QString::fromStdString(filename));
    jfile.open(QFile::WriteOnly);
    if(jfile.isWritable()){
        QJsonDocument doc;
        doc.setObject(file);
        jfile.write(doc.toJson());
    }
    else
        throw MyException("Impossibile leggere il file");
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
