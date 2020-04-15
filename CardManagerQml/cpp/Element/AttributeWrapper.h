#ifndef ATTRIBUTEWRAPPER_H
#define ATTRIBUTEWRAPPER_H

#include <QObject>
#include <QList>
#include <QQmlListProperty>

class AttributeData;
class SkillpackWrapper;

class AttributeWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(QQmlListProperty<SkillpackWrapper> skillpacks READ skillpacks NOTIFY skillpacksChanged)

public:
    explicit AttributeWrapper(QObject *parent = nullptr);
    explicit AttributeWrapper(AttributeData *attributeData, QObject *parent = nullptr);

    QString name() const;
    int value() const;

    QQmlListProperty<SkillpackWrapper> skillpacks();
    void appendSkillpack(SkillpackWrapper*);
    int skillpackCount() const;
    SkillpackWrapper *skillpack(int) const;
    void clearSkillpacks();

    bool hasSkillpack(const QString &name) const;

signals:
    void skillpacksChanged();

private:
    static void appendSkillpack(QQmlListProperty<SkillpackWrapper> *, SkillpackWrapper *);
    static int skillpackCount(QQmlListProperty<SkillpackWrapper>*);
    static SkillpackWrapper *skillpack(QQmlListProperty<SkillpackWrapper>*, int);
    static void clearSkillpacks(QQmlListProperty<SkillpackWrapper>*);

private:
    AttributeData *m_pAttributeData{nullptr};
    QList<SkillpackWrapper*> m_skillpacks;
};

#endif // ATTRIBUTEWRAPPER_H
