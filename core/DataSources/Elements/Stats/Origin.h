#ifndef ORIGIN_H
#define ORIGIN_H

#include "HeroData.h"

#include "core_global.h"

class OriginBonus;

class CORE_EXPORT Origin : public HeroData
{
    Q_OBJECT
    Q_PROPERTY(OriginBonus* bonus READ bonus CONSTANT)

public:
    explicit Origin(QObject *parent = nullptr);
    explicit Origin(const QString &name,
                    const QString &description,
                    const QString &image,
                    OriginBonus* bonus,
                    QObject *parent = nullptr);

    OriginBonus* bonus() const;

private:
    OriginBonus* m_pBonus;
};

#endif // ORIGIN_H
