#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QObject>
#include <QQmlListProperty>

#include "core_global.h"

class Skillpack;

class CORE_EXPORT Attribute : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QQmlListProperty<Skillpack> skillpacks READ skillpacks CONSTANT)

public:
    explicit Attribute(QObject *parent = nullptr);
    explicit Attribute(const QString &name,
                       const int &value,
                       const QVector<Skillpack*> &skillpacks,
                       QObject *parent = nullptr);

    QString name() const;
    int value() const;
    void setValue(const int &value);

    QQmlListProperty<Skillpack> skillpacks();
    int skillpacksCount() const;
    Skillpack* skillpack(const int &index) const;

    QVector<Skillpack*> skillpacks() const;

signals:
    void valueChanged();

private:
    static int skillpacksCount(QQmlListProperty<Skillpack> *list);
    static Skillpack* skillpack(QQmlListProperty<Skillpack> *list, int index);

private:
    QString m_name;
    int m_value;
    QVector<Skillpack*> m_skillpacks;
};

#endif // ATTRIBUTE_H
