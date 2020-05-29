#ifndef DATAREADER_H
#define DATAREADER_H

#include <QObject>
#include <QJsonObject>

#include <tuple>

#include "core_global.h"

class CardData;

class CORE_EXPORT DataReader : public QObject
{
    Q_OBJECT
public:
    explicit DataReader(QObject *parent = nullptr);

    std::tuple<bool, QJsonDocument, QString> load(const QString &filePath);

private:
    std::tuple<bool, QString> readFile(const QString &filePath);
};

#endif // DATAREADER_H
