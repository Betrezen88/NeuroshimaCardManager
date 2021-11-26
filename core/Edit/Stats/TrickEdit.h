#ifndef TRICKEDIT_H
#define TRICKEDIT_H

#include <QObject>
#include <QQmlListProperty>

#include "../../Data/Stats/TrickData.h"
#include "../../View/Common/Requirement.h"

#include "core_global.h"

/*
TODO: ? Replace isNew with enum
State {
    BOUGTH,
    NEWLY_BOUGTH,
    TO_BUY
}
*/

class CORE_EXPORT TrickEdit : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString action READ action CONSTANT)
    Q_PROPERTY(QQmlListProperty<Requirement> requirements READ requirements CONSTANT)
    Q_PROPERTY(bool meetsRequirements READ meetsRequirements NOTIFY meetsRequirementsChanged)
    Q_PROPERTY(bool isNew READ isNew CONSTANT)
    Q_PROPERTY(bool isAffordable READ isAffordable WRITE setIsAffordable NOTIFY isAffordableChanged)
    Q_PROPERTY(int cost READ cost WRITE setCost NOTIFY costChanged)

public:
    explicit TrickEdit(QObject *parent = nullptr);
    explicit TrickEdit(const TrickData& data, QObject* parent = nullptr);
    explicit TrickEdit(const TrickData& data, const bool isNew, QObject* parent = nullptr);

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

    const TrickData& data() const;

    bool isAffordable() const;
    void setIsAffordable(bool newIsAffordable);

    int cost() const;
    void setCost(int newCost);
    bool isNew() const;

signals:
    void meetsRequirementsChanged();
    void isAffordableChanged();
    void costChanged();

public slots:
    bool canBeBougth() const;

private:
    static int requirementCount(QQmlListProperty<Requirement>* list);
    static Requirement* requirement(QQmlListProperty<Requirement>* list, int index);

private:
    TrickData m_data;
    QVector<Requirement*> m_requirements;
    bool m_meetsRequirements{false};
    bool m_isNew{false};
    bool m_isAffordable{false};
    int m_cost{0};
};

#endif // TRICKEDIT_H
