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
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(bool used READ used CONSTANT)
    Q_PROPERTY(int min READ min CONSTANT)
    Q_PROPERTY(int max READ max CONSTANT)
    Q_PROPERTY(bool isNew READ isNew CONSTANT)

public:
    explicit OtherSkillEdit(QObject *parent = nullptr);
    explicit OtherSkillEdit(OtherSkillData *data, const bool& isNew, QObject* parent = nullptr);

    const QString &name() const;
    const QString &attribute() const;
    QString attributeShort() const;

    int value() const;
    void setValue(int newValue);

    bool used() const;
    int min() const;
    int max() const;
    bool isNew() const;

signals:
    void valueChanged();

private:
    OtherSkillData* m_data{nullptr};
    bool m_isNew;
};

#endif // OTHERSKILLEDIT_H
