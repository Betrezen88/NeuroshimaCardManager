#include "Card.h"

Card::Card(QObject *parent) : QObject(parent)
{

}

void Card::addPage(Page *page)
{
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

QString Card::filePath() const
{
    return m_filePath;
}
