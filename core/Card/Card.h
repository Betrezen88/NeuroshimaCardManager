#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QMap>

#include "core_global.h"

#include "Pages/Page.h"

class Stats;
class Equipment;
class Notes;
class Rules;

class CORE_EXPORT Card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Stats *stats READ stats CONSTANT)
    Q_PROPERTY(Equipment *equipment READ equipment CONSTANT)
    Q_PROPERTY(Notes *notes READ notes CONSTANT)
    Q_PROPERTY(Rules *rules READ rules CONSTANT)
    Q_PROPERTY(QString filePath READ filePath CONSTANT)

public:
    explicit Card(QObject *parent = nullptr);
    explicit Card(const QString &filepath, QObject *parent = nullptr);

    void addPage(Page *page);

    Q_INVOKABLE bool hasPage(const Page::Type &type) const;

    Stats *stats() const;
    Equipment *equipment() const;
    Notes* notes() const;
    Rules* rules() const;

    QString filePath() const;

private:
    QMap<Page::Type, Page*> m_pages;
    QString m_filePath;
};

#endif // CARD_H
