#ifndef PAGECREATOR_H
#define PAGECREATOR_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT PageCreator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Type type READ type CONSTANT)

public:
    enum class Type { STATS,
                      NOTES,
                      EQUIPMENT,
                      BEAST,
                      MACHINE,
                      VEHICLE,
                      FRIEND };
    Q_ENUM(Type)

    explicit PageCreator(QObject *parent = nullptr) : QObject(parent) {}
    explicit PageCreator(const Type &type, QObject *parent = nullptr)
        : QObject(parent),
          m_type(type)
    {}

    Type type() const { return m_type; }

private:
    Type m_type;
};

#endif // PAGECREATOR_H
