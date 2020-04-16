#ifndef OTHERSKILLWRAPPER_H
#define OTHERSKILLWRAPPER_H

#include <QObject>

class OtherSkillData;

class OtherSkillWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(QString attribute READ attribute CONSTANT)

public:
    explicit OtherSkillWrapper(QObject *parent = nullptr);
    explicit OtherSkillWrapper(OtherSkillData *otherSkill, QObject *parent = nullptr);

    QString name() const;
    int value() const;
    QString attribute() const;

private:
    OtherSkillData *m_pOtherSkillData{nullptr};
};

#endif // OTHERSKILLWRAPPER_H
