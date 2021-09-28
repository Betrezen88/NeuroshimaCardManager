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
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int min READ min CONSTANT)
    Q_PROPERTY(int max READ max CONSTANT)
    Q_PROPERTY(QQmlListProperty<SkillpackEdit> skillpacks READ skillpacks CONSTANT)

public:
    explicit AttributeEdit(QObject *parent = nullptr);
    explicit AttributeEdit(AttributeData *data, QObject* parent = nullptr);

    const QString &name() const;

    int value() const;
    void setValue(int newValue);

    int min() const;
    int max() const;

    QQmlListProperty<SkillpackEdit> skillpacks();
    int skillpackCount() const;
    SkillpackEdit* skillpack(const int index) const;

signals:
    void valueChanged();

private:
    static int skillpackCount(QQmlListProperty<SkillpackEdit>* list);
    static SkillpackEdit* skillpack(QQmlListProperty<SkillpackEdit>* list, int index);

private:
    AttributeData* m_data{nullptr};
    QVector<SkillpackEdit*> m_skillpacks;
};

#endif // ATTRIBUTEEDIT_H
