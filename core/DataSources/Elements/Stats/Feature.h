#ifndef FEATURE_H
#define FEATURE_H

#include "../../../Card/Data.h"

#include "core_global.h"

class Bonus;

class CORE_EXPORT Feature : public Data
{
    Q_OBJECT
    Q_PROPERTY(Bonus* bonus READ bonus CONSTANT)
    Q_PROPERTY(bool hasBonus READ hasBonus CONSTANT)

public:
    explicit Feature(QObject *parent = nullptr);
    explicit Feature(const QString &name,
                     const QString &description,
                     Bonus *bonus,
                     QObject *parent = nullptr);

    Bonus* bonus() const;

    bool hasBonus() const;

private:
    Bonus* m_bonus{nullptr};
};

#endif // FEATURE_H
