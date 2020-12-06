#include "Card.h"
#include "Pages/Stats.h"
#include "Pages/Rules.h"

Card::Card(QObject *parent) : QObject(parent)
{

}

Card::Card(const QString &filepath, QObject *parent)
    : QObject(parent),
      m_filePath(filepath)
{

}

void Card::addPage(Page *page)
{
    if ( page == nullptr ) return;

    page->setParent(this);
    m_pages.insert(page->type(), page);
}

bool Card::hasPage(const Page::Type &type) const
{
    return m_pages.contains(type);
}

Stats *Card::stats() const
{
    if (hasPage(Page::Type::STATS))
        return dynamic_cast<Stats*>(m_pages.value(Page::Type::STATS));
    return nullptr;
}

Rules *Card::rules() const
{
    if (hasPage(Page::Type::RULES))
        return dynamic_cast<Rules*>(m_pages.value(Page::Type::RULES));
    return nullptr;
}

QString Card::filePath() const
{
    return m_filePath;
}
