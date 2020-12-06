#include "Rules.h"

#include "../Elements/Rules/RulesSection.h"

Rules::Rules(QObject *parent) : Page(Page::Type::RULES, parent)
{

}

void Rules::addSection(const QString &title, const QList<QStringList> &rows)
{
    m_sections.append(new RulesSection(title, rows, this));
}

QQmlListProperty<RulesSection> Rules::sections()
{
    return QQmlListProperty<RulesSection>(this, &m_sections);
}
