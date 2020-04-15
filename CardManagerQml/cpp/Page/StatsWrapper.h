#ifndef STATSWRAPPER_H
#define STATSWRAPPER_H

#include <QObject>
#include <QList>
#include <QQmlListProperty>

class StatsData;
class PersonalWrapper;
class AttributeWrapper;

class StatsWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PersonalWrapper *personal READ personal NOTIFY attributesChanged)
    Q_PROPERTY(QQmlListProperty<AttributeWrapper> attributes READ attributes NOTIFY attributesChanged)

public:
    explicit StatsWrapper(QObject *parent = nullptr);
    explicit StatsWrapper(StatsData *statsData, QObject *parent = nullptr);

    PersonalWrapper *personal() const;
    QQmlListProperty<AttributeWrapper> attributes();
    void appendAttribute(AttributeWrapper*);
    int attributeCount() const;
    AttributeWrapper *attribute(int) const;
    void clearAttributes();

signals:
    void attributesChanged();

private:
    static void appendAttribute(QQmlListProperty<AttributeWrapper> *, AttributeWrapper *);
    static int attributeCount(QQmlListProperty<AttributeWrapper>*);
    static AttributeWrapper *attribute(QQmlListProperty<AttributeWrapper>*, int);
    static void clearAttributes(QQmlListProperty<AttributeWrapper>*);

private:
    StatsData *m_pStatsData{nullptr};
    PersonalWrapper *m_pPersonalWrapper{nullptr};
    QList<AttributeWrapper*> m_attributes;
};

#endif // STATSWRAPPER_H
