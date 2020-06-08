#include "Page.h"

Page::Page(QObject *parent)
    : QObject(parent),
      m_type(Page::Type::UNKNOWN)
{

}

Page::Page(const Page::Type &type, QObject *parent)
    : QObject(parent),
      m_type(type)
{

}

Page::Type Page::type() const
{
    return m_type;
}
