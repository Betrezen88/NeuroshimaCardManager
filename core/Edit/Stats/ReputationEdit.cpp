#include "ReputationEdit.h"

ReputationEdit::ReputationEdit(QObject *parent) : QObject(parent)
{

}

ReputationEdit::ReputationEdit(ReputationData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &ReputationEdit::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

int ReputationEdit::value() const
{
    return m_data ? m_data->value : 0;
}

void ReputationEdit::setValue(int newValue)
{
    if (m_data && m_data->value == newValue)
        return;
    m_data->value = newValue;
    emit valueChanged();
}
