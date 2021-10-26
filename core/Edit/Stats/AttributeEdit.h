#ifndef ATTRIBUTEEDIT_H
#define ATTRIBUTEEDIT_H

#include <QObject>
#include <QQmlListProperty>

#include "SkillpackEdit.h"

#include "core_global.h"

class AttributeData;

class CORE_EXPORT AttributeEdit : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value NOTIFY valueChanged)
    Q_PROPERTY(int min READ min CONSTANT)
    Q_PROPERTY(int max READ max CONSTANT)
    Q_PROPERTY(bool affordable READ affordable WRITE setAffordable NOTIFY affordableChanged)
    Q_PROPERTY(int cost READ cost WRITE setCost NOTIFY costChanged)
    Q_PROPERTY(QQmlListProperty<SkillpackEdit> skillpacks READ skillpacks CONSTANT)

public:
    explicit AttributeEdit(QObject *parent = nullptr);
    explicit AttributeEdit(AttributeData *data, QObject* parent = nullptr);

    const QString &name() const;

    int value() const;
    int min() const;
    int max() const;

    QQmlListProperty<SkillpackEdit> skillpacks();
    int skillpackCount() const;
    SkillpackEdit* skillpack(const int index) const;
    QVector<SkillpackEdit*> skillpackList();

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

private:
    static int skillpackCount(QQmlListProperty<SkillpackEdit>* list);
    static SkillpackEdit* skillpack(QQmlListProperty<SkillpackEdit>* list, int index);

private:
    AttributeData* m_data{nullptr};
    QVector<SkillpackEdit*> m_skillpacks;
    int m_min{0};
    int m_max{0};
    bool m_affordable;
    int m_cost{0};
};

#endif // ATTRIBUTEEDIT_H
