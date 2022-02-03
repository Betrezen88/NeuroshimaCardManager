#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QMap>

#include "Pages/Page.h"
#include "core_global.h"

class Stats;
class Equipment;
class Notes;

class CORE_EXPORT Card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ filePath CONSTANT)
    Q_PROPERTY(Stats* stats READ stats CONSTANT)
    Q_PROPERTY(Equipment* equipment READ equipment CONSTANT)
    Q_PROPERTY(Notes* notes READ notes CONSTANT)
    Q_PROPERTY(bool modified READ modified NOTIFY modifiedChanged)

public:
    explicit Card(QObject *parent = nullptr);
    explicit Card(const QString &filepath, QObject *parent = nullptr);

    void addPage(Page *page);

    Stats* stats() const;
    Equipment* equipment() const;
    Notes *notes() const;

    QString filePath() const;

    bool modified() const;
    void setModified(const bool& modified);

signals:
    void modifiedChanged();

public slots:
    bool hasPage(const Page::Type& type) const;

private:
    QMap<Page::Type, Page*> m_pages;
    QString m_filePath;
    bool m_modified{false};
};

#endif // CARD_H
