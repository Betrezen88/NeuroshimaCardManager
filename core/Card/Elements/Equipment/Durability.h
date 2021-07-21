#ifndef DURABILITY_H
#define DURABILITY_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Durability: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int max READ max CONSTANT)
    Q_PROPERTY(int current READ current WRITE setCurrent NOTIFY currentChanged)

public:
    Durability(QObject* parent = nullptr) : QObject(parent) {}
    Durability(const int max,
               const int current,
               QObject* parent = nullptr)
        : QObject(parent)
        , m_max(max)
        , m_current(current)
    {}

    int max() const { return m_max; }
    int current() const { return m_current; }

signals:
    void currentChanged(const int current);

public slots:
    void setCurrent(const int current) {
        if ( m_current == current )
            return;

        m_current = current;
        emit currentChanged(m_current);
    }

public:
    int m_max{0};
    int m_current{0};
};

#endif // DURABILITY_H
