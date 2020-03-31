#ifndef DATAREADER_H
#define DATAREADER_H

#include <QObject>

#include "core_global.h"

class Card;

class CORE_EXPORT DataReader : public QObject
{
    Q_OBJECT
public:
    explicit DataReader(QObject *parent = nullptr);

signals:

public slots:
    Card *loadCard(const QString &filePath);
};

#endif // DATAREADER_H
