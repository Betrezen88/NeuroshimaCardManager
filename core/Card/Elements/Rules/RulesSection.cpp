#include "RulesSection.h"

RulesSection::RulesSection(QObject *parent) : QObject(parent)
{

}

RulesSection::RulesSection(const QString &title,
                           const QList<QStringList> &rows,
                           QObject *parent)
    : QObject(parent)
    , m_title(title)
    , m_rows(rows)
{

}

QString RulesSection::title() const
{
    return m_title;
}

QList<QStringList> RulesSection::rows() const
{
    return m_rows;
}
