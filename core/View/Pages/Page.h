#ifndef PAGE_H
#define PAGE_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Page : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Page::Type type READ type CONSTANT)

public:
    enum class Type { UNKNOWN
                      , STATS
                      , EQUIPMENT
                      , NOTES
                      , FRIENDS
                      , BEAST
                      , VEHICLE
                      , RULES };
    Q_ENUM(Type)

    explicit Page(QObject *parent = nullptr)
        : QObject(parent)
        , m_type(Type::UNKNOWN)
    {}
    explicit Page(const Page::Type &type, QObject *parent = nullptr)
        : QObject(parent)
        , m_type(type)
    {}

    Page::Type type() const {
        return m_type;
    }

signals:
    void wasModified();

private:
    Page::Type m_type;
};

#endif // PAGE_H
