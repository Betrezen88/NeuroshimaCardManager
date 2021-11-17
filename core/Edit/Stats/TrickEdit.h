#ifndef TRICKEDIT_H
#define TRICKEDIT_H

#include <QObject>
#include <QQmlListProperty>

#include "../../Data/Stats/TrickData.h"
#include "../../View/Common/Requirement.h"

#include "core_global.h"

class CORE_EXPORT TrickEdit : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString action READ action CONSTANT)
    Q_PROPERTY(QQmlListProperty<Requirement> requirements READ requirements CONSTANT)
    Q_PROPERTY(bool meetsRequirements READ meetsRequirements NOTIFY meetsRequirementsChanged)

public:
    explicit TrickEdit(QObject *parent = nullptr);
    explicit TrickEdit(const TrickData& data, QObject* parent = nullptr);

    const QString &name() const;
    const QString &description() const;
    const QString &action() const;

    QQmlListProperty<Requirement> requirements();
    int requirementCount() const;
    Requirement* requirement(const int index) const;

    QVector<Requirement*> attributes() const;
    QVector<Requirement*> skills(const bool optional) const;

    bool meetsRequirements() const;
    void setMeetsRequirements(const bool meetsRequirements);

signals:
    void meetsRequirementsChanged();

private:
    static int requirementCount(QQmlListProperty<Requirement>* list);
    static Requirement* requirement(QQmlListProperty<Requirement>* list, int index);

private:
    TrickData m_data;
    QVector<Requirement*> m_requirements;
    bool m_meetsRequirements;
    //bool m_isNew;
};

#endif // TRICKEDIT_H
