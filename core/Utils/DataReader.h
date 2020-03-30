#ifndef DATAREADER_H
#define DATAREADER_H

#include <QObject>

#include "core_global.h"

class Card;
class Personal;
class Origin;
class Profession;
class Specialization;
class Disease;

class CORE_EXPORT DataReader : public QObject
{
    Q_OBJECT
public:
    explicit DataReader(QObject *parent = nullptr);

signals:

public slots:
    void open(const QString &file);

private:
    Personal *personal(const QJsonObject &data);
};

#endif // DATAREADER_H
