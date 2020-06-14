#ifndef ORIGIN_H
#define ORIGIN_H

#include "HeroData.h"

#include "core_global.h"

class CORE_EXPORT Origin : public HeroData
{
    Q_OBJECT
    Q_PROPERTY(QString attribute READ attribute CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)

public:
    explicit Origin(QObject *parent = nullptr);
    explicit Origin(const QString &name,
                    const QString &description,
                    const QString &image,
                    const QString &attribute,
                    const int &value,
                    QObject *parent = nullptr);

    QString attribute() const;
    int value() const;

private:
    QPair<QString, int> m_bonus;
};

#endif // ORIGIN_H
