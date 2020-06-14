#ifndef PROFESSION_H
#define PROFESSION_H

#include "HeroData.h"

#include "core_global.h"

class CORE_EXPORT Profession : public HeroData
{
    Q_OBJECT
    Q_PROPERTY(QString quote READ quote CONSTANT)

public:
    explicit Profession(QObject *parent = nullptr);
    explicit Profession(const QString &name,
                        const QString &description,
                        const QString &image,
                        const QString &quote,
                        QObject *parent = nullptr);

    QString quote() const;

private:
    QString m_quote;
};

#endif // PROFESSION_H
