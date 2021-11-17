#ifndef SKILLEDIT_H
#define SKILLEDIT_H

#include <QObject>
#include <QString>

#include "core_global.h"

class SkillData;

class CORE_EXPORT SkillEdit : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value NOTIFY valueChanged)
    Q_PROPERTY(int min READ min CONSTANT)
    Q_PROPERTY(int max READ max CONSTANT)
    Q_PROPERTY(bool used READ used CONSTANT)
    Q_PROPERTY(bool affordable READ affordable WRITE setAffordable NOTIFY affordableChanged)
    Q_PROPERTY(int cost READ cost WRITE setCost NOTIFY costChanged)

public:
    friend class StatsEditor;

    explicit SkillEdit(QObject* parent = nullptr);
    explicit SkillEdit(SkillData* data, QObject* parent = nullptr);

    const QString &name() const;

    int value() const;

    int min() const;
    int max() const;
    bool used() const;

    bool affordable() const;
    void setAffordable(bool newAffordable);

    int cost() const;
    void setCost(int newCost);

signals:
    void valueChanged();
    void increased(const int value);
    void decreased(const int value);
    void affordableChanged();
    void costChanged();

public slots:
    void increase();
    void decrease();
    void unuse();

private:
    SkillData* m_data{nullptr};
    int m_min{0};
    int m_max{0};
    bool m_affordable;
    int m_cost{0};
};

#endif // SKILLEDIT_H
