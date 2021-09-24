#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QObject>
#include <QQmlListProperty>

#include "../../Data/Stats/AttributeData.h"
#include "Skillpack.h"

#include "core_global.h"

class CORE_EXPORT Attribute : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(QQmlListProperty<Skillpack> skillpacks READ skillpacks CONSTANT)

public:
    explicit Attribute(QObject *parent = nullptr);
    explicit Attribute(AttributeData *data, QObject *parent = nullptr);

    const QString &name() const;
    int value() const;
    QQmlListProperty<Skillpack> skillpacks();
    int skillpackCount() const;
    Skillpack* skillpack(const int index) const;

private:
    static int skillpackCount(QQmlListProperty<Skillpack> *list);
    static Skillpack* skillpack(QQmlListProperty<Skillpack> *list, int index);

private:
    AttributeData* m_data{nullptr};
    QVector<Skillpack*> m_skillpacks;
};

#endif // ATTRIBUTE_H
