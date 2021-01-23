#ifndef DATAWRITER_H
#define DATAWRITER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>

#include <tuple>

class DataWriter : public QObject
{
    Q_OBJECT
public:
    explicit DataWriter(QObject *parent = nullptr);

    std::tuple<bool, QString> save(const QString &filePath,
                                   const QJsonDocument &json);

};

#endif // DATAWRITER_H
