#ifndef DEXTERITYBONUS_H
#define DEXTERITYBONUS_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT DexterityBonus: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
public:
    DexterityBonus(QObject* parent = nullptr)
        : QObject(parent)
    {}

    DexterityBonus(const QString& name,
                   const int& value,
                   QObject* parent = nullptr)
        : QObject(parent)
        , m_name(name)
        , m_value(value)
    {}

    QString name() const { return m_name; }
    int value() const { return m_value; }

private:
    QString m_name{};
    int m_value{0};
};

#endif // DEXTERITYBONUS_H
