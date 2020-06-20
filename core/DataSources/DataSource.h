#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT DataSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Type type READ type CONSTANT)

public:
    enum class Type {
        STATS,
        NOTES,
        EQUIPMENT,
        FRIEND,
        BEAST,
        MACHINE,
        VEHICLE
    };
    Q_ENUM(Type)

    explicit DataSource(QObject *parent = nullptr) : QObject(parent) {}
    explicit DataSource(const Type &type, QObject *parent = nullptr)
        : QObject(parent),
          m_type(type)
    {}

    Type type() const { return m_type; }

private:
    Type m_type;
};

#endif // DATASOURCE_H
