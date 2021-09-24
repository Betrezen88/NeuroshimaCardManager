#ifndef DEXTERITYBONUS_H
#define DEXTERITYBONUS_H

#include <QObject>

#include "../../Data/Equipment/DexterityBonusData.h"

#include "core_global.h"

class CORE_EXPORT DexterityBonus : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)

public:
    explicit DexterityBonus(QObject *parent = nullptr);
    explicit DexterityBonus(DexterityBonusData* data, QObject *parent = nullptr);

    const QString &name() const;
    int value() const;

private:
    DexterityBonusData* m_data{nullptr};
};

#endif // DEXTERITYBONUS_H
