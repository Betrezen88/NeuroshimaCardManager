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
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int min READ min CONSTANT)
    Q_PROPERTY(int max READ max CONSTANT)
    Q_PROPERTY(bool used READ used CONSTANT)
    Q_PROPERTY(bool affordable READ affordable WRITE setAffordable NOTIFY affordableChanged)

public:
    explicit SkillEdit(QObject* parent = nullptr);
    explicit SkillEdit(SkillData* data, QObject* parent = nullptr);

    const QString &name() const;

    int value() const;
    void setValue(int newValue);

    int min() const;
    int max() const;
    bool used() const;

    bool affordable() const;
    void setAffordable(bool newAffordable);

signals:
    void valueChanged();
    void affordableChanged();

public slots:
    void increase();
    void decrease();

private:
    SkillData* m_data{nullptr};
    bool m_affordable;
};

#endif // SKILLEDIT_H
