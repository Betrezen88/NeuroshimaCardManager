#ifndef CREATIONPOINTSMANAGER_H
#define CREATIONPOINTSMANAGER_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT CreationPointsManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int attributes
               READ attributes
               NOTIFY attributesChanged)
    Q_PROPERTY(int freeSkillpoints
               READ freeSkillpoints
               NOTIFY freeSkillpointsChanged)
    Q_PROPERTY(int specializationSkillpoints
               READ specializationSkillpoints
               NOTIFY specializationSkillpointsChanged)
    Q_PROPERTY(int money
               READ money
               NOTIFY moneyChanged)

public:
    explicit CreationPointsManager(QObject *parent = nullptr);

    int attributes() const;
    int freeSkillpoints() const;
    int specializationSkillpoints() const;
    int money() const;

signals:
    void attributesChanged(const int &value);
    void freeSkillpointsChanged(const int &value);
    void specializationSkillpointsChanged(const int &value);
    void moneyChanged(const int &value);

public slots:
    Q_INVOKABLE void spendAttributes(const int &value);
    Q_INVOKABLE void refundAttributes(const int &value);
    Q_INVOKABLE void spendFreeSkillpoints(const int &value);
    Q_INVOKABLE void refundFreeSkillpoints(const int &value);
    Q_INVOKABLE void spendSpecializationSkillpoints(const int &value);
    Q_INVOKABLE void refundSpecializationSkillpoints(const int &value);
    Q_INVOKABLE void spendMoney(const int &value);
    Q_INVOKABLE void refundMoney(const int &value);

private:
    int m_attributes{50};
    int m_freeSkillpoints{35};
    int m_specializationSkillpoints{30};
    int m_money{100};
};

#endif // CREATIONPOINTSMANAGER_H
