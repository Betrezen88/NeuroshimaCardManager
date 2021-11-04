#ifndef REPUTATIONEDIT_H
#define REPUTATIONEDIT_H

#include <QObject>

#include "../../Data/Stats/ReputationData.h"

#include "core_global.h"

class CORE_EXPORT ReputationEdit : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int min READ min CONSTANT)
    Q_PROPERTY(int max READ max CONSTANT)

public:
    explicit ReputationEdit(QObject *parent = nullptr);
    explicit ReputationEdit(ReputationData* data, QObject *parent = nullptr);

    const QString &name() const;

    int value() const;
    void setValue(int newValue);

    int min() const;
    int max() const;

signals:
    void valueChanged();

private:
    ReputationData* m_data{nullptr};
    int m_min{0};
    int m_max{0};
};

#endif // REPUTATIONEDIT_H
