#include "DexterityBonus.h"

DexterityBonus::DexterityBonus(QObject *parent) : QObject(parent)
{

}

DexterityBonus::DexterityBonus(DexterityBonusData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &DexterityBonus::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

int DexterityBonus::value() const
{
    return m_data ? m_data->value : 0;
}
