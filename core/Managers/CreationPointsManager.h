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
    Q_PROPERTY(int tricks
               READ tricks
               NOTIFY tricksChanged)

public:
    explicit CreationPointsManager(QObject *parent = nullptr);

    int attributes() const;
    int freeSkillpoints() const;
    int specializationSkillpoints() const;
    int money() const;
    int tricks() const;

signals:
    void attributesChanged(const int &value);
    void freeSkillpointsChanged(const int &value);
    void specializationSkillpointsChanged(const int &value);
    void moneyChanged(const int &value);
    void tricksChanged(const int &value);

public slots:
    void spendAttributes(const int &value);
    void refundAttributes(const int &value);
    void spendFreeSkillpoints(const int &value);
    void refundFreeSkillpoints(const int &value);
    void spendSpecializationSkillpoints(const int &value);
    void refundSpecializationSkillpoints(const int &value);
    void spendMoney(const int &value);
    void refundMoney(const int &value);
    void spendTrick(const int &value);
    void refundTrick(const int &value);

private:
    int m_attributes{50};
    int m_freeSkillpoints{35};
    int m_specializationSkillpoints{30};
    int m_money{100};
    int m_tricks{1};
};

#endif // CREATIONPOINTSMANAGER_H
