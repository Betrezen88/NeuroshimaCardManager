#include "Card.h"
#include "Pages/Stats.h"
#include "Pages/Equipment.h"
#include "Pages/Notes.h"

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

    connect( page, &Page::wasModified, this,
             [this](){ setModified(true); } );
}

Stats *Card::stats() const
{
    return qobject_cast<Stats*>(m_pages.value(Page::Type::STATS, nullptr));
}

Equipment *Card::equipment() const
{
    return qobject_cast<Equipment*>(m_pages.value(Page::Type::EQUIPMENT, nullptr));
}

Notes *Card::notes() const
{
    return qobject_cast<Notes*>(m_pages.value(Page::Type::NOTES, nullptr));
}

QString Card::filePath() const
{
    return m_filePath;
}

bool Card::modified() const
{
    return m_modified;
}

void Card::setModified(const bool &modified)
{
    if ( m_modified == modified )
        return;

    m_modified = modified;
    emit modifiedChanged();
}

bool Card::hasPage(const Page::Type &type) const
{
    return m_pages.contains( type );
}
