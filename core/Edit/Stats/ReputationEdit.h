#ifndef REPUTATIONEDIT_H
#define REPUTATIONEDIT_H

#include <QObject>

#include "../../Data/Stats/ReputationData.h"

#include "core_global.h"

class CORE_EXPORT ReputationEdit : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int min READ min CONSTANT)
    Q_PROPERTY(int max READ max NOTIFY maxChanged)
    Q_PROPERTY(bool isAffordable READ isAffordable WRITE setIsAffordable NOTIFY isAffordableChanged)
    Q_PROPERTY(int cost READ cost WRITE setCost NOTIFY costChanged)

public:
    explicit ReputationEdit(QObject *parent = nullptr);
    explicit ReputationEdit(ReputationData* data, QObject *parent = nullptr);

    const QString &name() const;

    int value() const;
    void setValue(int newValue);

    int min() const;
    int max() const;
    void increaseMax();
    void decreaseMax();

    bool isAffordable() const;
    void setIsAffordable(bool newIsAffordable);

    int cost() const;
    void setCost(int newCost);

signals:
    void valueChanged();
    void maxChanged();
    void isAffordableChanged();
    void costChanged();
    void increased(ReputationEdit* ptr);
    void decreased(ReputationEdit* ptr);

public slots:
    void increase();
    void decrease();

private:
    ReputationData* m_data{nullptr};
    int m_min{0};
    int m_max{0};
    bool m_isAffordable{false};
    int m_cost{0};
};

#endif // REPUTATIONEDIT_H
