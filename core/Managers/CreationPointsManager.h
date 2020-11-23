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

    bool spendAttribute(const int& value);
    bool spendSpecializationPoints(const int& value);
    bool spendFreeSkillpoints(const int& value);
    void refundAttribute(const int& value);
    void refundSpecializationPoints(const int& value);
    void refundFreeSkillpoints(const int& value);

signals:
    void attributesChanged(const int &value);
    void freeSkillpointsChanged(const int &value);
    void specializationSkillpointsChanged(const int &value);
    void moneyChanged(const int &value);
    void tricksChanged(const int &value);

public slots:
    void spendMoney(const int &value);
    void refundMoney(const int &value);
    void spendTrick(const int &value);
    void refundTrick(const int &value);

private:
    QPair<int, int> m_attributes{40, 40};
    QPair<int, int> m_specPoints{30, 30};
    QPair<int, int> m_freePoints{35, 35};
    QPair<int, int> m_money{100, 100};
    QPair<int, int> m_tricks{1, 1};
};

#endif // CREATIONPOINTSMANAGER_H
