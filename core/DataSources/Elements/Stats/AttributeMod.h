#ifndef ATTRIBUTEMOD_H
#define ATTRIBUTEMOD_H

#include <QObject>
#include <QQmlListProperty>

#include "core_global.h"

class Attribute;
class SkillpackMod;

class CORE_EXPORT AttributeMod : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<SkillpackMod> skillpacks READ skillpacks CONSTANT)
    Q_PROPERTY(Attribute* attribute READ attribute CONSTANT)
    Q_PROPERTY(int min READ min WRITE setMin NOTIFY minChanged)
    Q_PROPERTY(int max READ max WRITE setMax NOTIFY maxChanged)

public:
    explicit AttributeMod(QObject* parent = nullptr);
    explicit AttributeMod(Attribute* attribute,
                          QObject* parent = nullptr);
    explicit AttributeMod(Attribute* attribute,
                          const int& min,
                          const int& max,
                          QObject *parent = nullptr);
    ~AttributeMod() = default;

    Attribute* attribute() const;
    int min() const;
    int max() const;

    QQmlListProperty<SkillpackMod> skillpacks();

public slots:
    void setMin(int min);
    void setMax(int max);
    void setValue(const int& value);

signals:
    void minChanged(int min);
    void maxChanged(int max);

private:
    void init();

private:
    Attribute* m_pAttribute{nullptr};
    QPair<int, int> m_range;
    QList<SkillpackMod*> m_skillpacks;
};

#endif // ATTRIBUTEMOD_H
