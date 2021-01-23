#include "DataWriter.h"

#include <QFile>

DataWriter::DataWriter(QObject *parent) : QObject(parent)
{

}

std::tuple<bool, QString> DataWriter::save(const QString &filePath,
                                           const QJsonDocument &json)
{
    QFile file(filePath);

    if ( !file.open( QIODevice::WriteOnly ) )
        return std::tuple<bool, QString>(false,
                                         QString("Błąd odczytu pliku: "+filePath));

    if ( -1 == file.write(json.toJson()) )
        return std::tuple<bool, QString>(false,
                                         QString("Błąd zapisu pliku: "+filePath));

    return std::tuple<bool, QString>(true,
                                     QString("Plik "+filePath+" zapisany poprawnie"));
}
