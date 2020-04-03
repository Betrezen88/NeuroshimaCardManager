#ifndef DATAREADER_H
#define DATAREADER_H

#include <QObject>

#include "core_global.h"

class CardData;

class CORE_EXPORT DataReader : public QObject
{
    Q_OBJECT
public:
    explicit DataReader(QObject *parent = nullptr);

signals:

public slots:
    CardData *loadCard(const QString &filePath);
};

#endif // DATAREADER_H
