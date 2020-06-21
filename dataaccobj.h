#ifndef DATAACCOBJ_H
#define DATAACCOBJ_H

#include <string>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>
#include <QDir>

class DataAccObj
{
public:
    /*
     * Lo scopo della classe DAO è quella di fornire tutti i metodi base per la gestione dell'Input/Output
     * di dati da/a un file json.
    */
    static void setPath(const std::string &path);
    static std::string getPath();
    static void setFile(const QJsonObject &file);
    static QJsonObject getFile();
    static QJsonObject fromStringToJson(const std::string& dato);
    virtual QJsonObject getJson () const = 0;
    virtual void getDataFromJson (const QJsonObject &) = 0;
};

#endif // DATAACCOBJ_H
