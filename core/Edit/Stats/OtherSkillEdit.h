#ifndef OTHERSKILLEDIT_H
#define OTHERSKILLEDIT_H

#include <QObject>

#include "core_global.h"

class OtherSkillData;

class CORE_EXPORT OtherSkillEdit : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString attribute READ attribute CONSTANT)
    Q_PROPERTY(QString attributeShort READ attributeShort CONSTANT)
    Q_PROPERTY(int value READ value NOTIFY valueChanged)
    Q_PROPERTY(bool used READ used CONSTANT)
    Q_PROPERTY(int min READ min CONSTANT)
    Q_PROPERTY(int max READ max CONSTANT)
    Q_PROPERTY(bool isNew READ isNew CONSTANT)
    Q_PROPERTY(bool isAffordable READ isAffordable WRITE setIsAffordable NOTIFY isAffordableChanged)
    Q_PROPERTY(int cost READ cost WRITE setCost NOTIFY costChanged)

public:
    explicit OtherSkillEdit(QObject *parent = nullptr);
    explicit OtherSkillEdit(OtherSkillData *data, const bool& isNew, QObject* parent = nullptr);

    const QString &name() const;
    const QString &attribute() const;
    QString attributeShort() const;

    int value() const;
    bool used() const;
    int min() const;
    int max() const;
    bool isNew() const;

    bool isAffordable() const;
    void setIsAffordable(bool newIsAffordable);

    int cost() const;
    void setCost(int newCost);

signals:
    void valueChanged();
    void increased(const int value);
    void decreased(const int value);
    void isAffordableChanged();
    void costChanged();

public slots:
    void increase();
    void decrease();

private:
    OtherSkillData* m_data{nullptr};
    int m_min{0};
    int m_max{0};
    bool m_isNew;
    bool m_isAffordable;
    int m_cost{0};
};

#endif // OTHERSKILLEDIT_H
