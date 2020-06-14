#ifndef CARDCREATOR_H
#define CARDCREATOR_H

#include <QObject>
#include <QMap>

#include "core_global.h"

#include "PageCreator.h"

class CORE_EXPORT CardCreator : public QObject
{
    Q_OBJECT
public:
    explicit CardCreator(QObject *parent = nullptr);

    PageCreator* pageCreator(const PageCreator::Type &type);

private:
    PageCreator* createPageCreator(const PageCreator::Type &type);

private:
    QMap<PageCreator::Type, PageCreator*> m_pageCreators;
};

#endif // CARDCREATOR_H
