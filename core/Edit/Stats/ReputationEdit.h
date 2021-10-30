#ifndef REPUTATIONEDIT_H
#define REPUTATIONEDIT_H

#include <QObject>

#include "../../Data/Stats/ReputationData.h"

class ReputationEdit : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit ReputationEdit(QObject *parent = nullptr);
    explicit ReputationEdit(ReputationData* data, QObject *parent = nullptr);

    const QString &name() const;

    int value() const;
    void setValue(int newValue);

signals:
    void valueChanged();

private:
    ReputationData* m_data{nullptr};
};

#endif // REPUTATIONEDIT_H
