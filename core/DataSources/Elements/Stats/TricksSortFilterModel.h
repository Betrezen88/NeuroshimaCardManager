#ifndef TRICKSSORTFILTERMODEL_H
#define TRICKSSORTFILTERMODEL_H

#include <QObject>
#include <QQmlListProperty>

#include "core_global.h"

class Trick;

class CORE_EXPORT TricksSortFilterModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString pattern
               READ pattern
               WRITE setPattern
               NOTIFY patternChanged)
    Q_PROPERTY(Qt::SortOrder order
               READ order
               WRITE setOrder
               NOTIFY orderChanged)
    Q_PROPERTY(bool caseSensitive
               READ caseSensitive
               WRITE setCaseSensitive
               NOTIFY caseSensitiveChanged)
    Q_PROPERTY(QQmlListProperty<Trick> tricks
               READ tricks
               NOTIFY tricksChanged)

public:
    explicit TricksSortFilterModel(QObject *parent = nullptr);

    QQmlListProperty<Trick> tricks();
    void addTrick(Trick *trick);
    Trick* trick(const int &index) const;
    int tricksCount() const;

    void removeTrick(const int &index);

    Trick* findTrickSource(const QString& trickName);

    QString pattern() const;
    Qt::SortOrder order() const;
    bool caseSensitive() const;

signals:
    void patternChanged(QString pattern);
    void orderChanged(Qt::SortOrder order);
    void tricksChanged();
    void caseSensitiveChanged(bool caseSensitive);

public slots:
    void setPattern(const QString &pattern);
    void setOrder(const Qt::SortOrder &order);
    void setCaseSensitive(bool caseSensitive);

private slots:
    void sort(const Qt::SortOrder &order);
    void filter(const QString &pattern);

private:
    bool containsPattern(Trick *trick,
                         const QString &pattern,
                         const bool &caseSensitive);

private:
    QString m_pattern;
    Qt::SortOrder m_order;

    QVector<Trick*> m_sourceModel;
    QList<Trick*> m_tricks;
    bool m_caseSensitive;
};

#endif // TRICKSSORTFILTERMODEL_H
