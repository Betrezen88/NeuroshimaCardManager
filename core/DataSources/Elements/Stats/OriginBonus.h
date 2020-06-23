#ifndef ORIGINBONUS_H
#define ORIGINBONUS_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT OriginBonus : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList attributes READ attributes CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)

public:
    explicit OriginBonus(QObject *parent = nullptr) : QObject(parent) {}
    explicit OriginBonus(const QStringList &attributes,
                         const int &value,
                         QObject *parent = nullptr)
        : QObject(parent),
          m_attributes(attributes),
          m_value(value)
    {

    }

    QStringList attributes() const { return m_attributes; }
    int value() const { return m_value; }

private:
    QStringList m_attributes;
    int m_value;
};

#endif // ORIGINBONUS_H
