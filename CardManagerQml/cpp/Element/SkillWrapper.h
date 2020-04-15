#ifndef SKILLWRAPPER_H
#define SKILLWRAPPER_H

#include <QObject>

class SkillData;

class SkillWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)

public:
    explicit SkillWrapper(QObject *parent = nullptr);
    explicit SkillWrapper(SkillData *skillData, QObject *parent = nullptr);

    QString name() const;
    int value() const;

private:
    SkillData *m_pSkillData{nullptr};
};

#endif // SKILLWRAPPER_H
