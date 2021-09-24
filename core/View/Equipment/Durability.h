#ifndef DURABILITY_H
#define DURABILITY_H

#include <QObject>

#include "../../Data/Equipment/DurabilityData.h"

#include "core_global.h"

class CORE_EXPORT Durability : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int current READ current WRITE setCurrent NOTIFY currentChanged)
    Q_PROPERTY(int max READ max CONSTANT)

public:
    explicit Durability(QObject *parent = nullptr);
    explicit Durability(DurabilityData* data, QObject *parent = nullptr);

    int current() const;
    void setCurrent(const int newCurrent);

    int max() const;

signals:
    void currentChanged();

private:
    DurabilityData* m_data{nullptr};
};

#endif // DURABILITY_H
