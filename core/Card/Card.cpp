#include "Card.h"
#include "Pages/Stats.h"
#include "Pages/Equipment.h"
#include "Pages/Notes.h"
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

Equipment *Card::equipment() const
{
    if (hasPage(Page::Type::EQUIPMENT))
        return dynamic_cast<Equipment*>(m_pages.value(Page::Type::EQUIPMENT));
    return nullptr;
}

Notes *Card::notes() const
{
    if (hasPage(Page::Type::NOTES))
        return dynamic_cast<Notes*>(m_pages.value(Page::Type::NOTES));
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
