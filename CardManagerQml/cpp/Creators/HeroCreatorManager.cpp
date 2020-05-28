#include "HeroCreatorManager.h"

#include "Card/Pages/StatsData.h"
#include "Card/Elements/Stats/PersonalData.h"
#include "Card/Elements/Stats/OriginData.h"
#include "Card/Elements/Stats/ProfessionData.h"
#include "Card/Elements/Stats/FeatureData.h"
#include "Card/Elements/Stats/SpecializationData.h"

#include <QDebug>

HeroCreatorManager::HeroCreatorManager(QObject *parent)
    : QObject(parent),
      m_pCardData(nullptr),
      m_pStatsData(new StatsData),
      m_pPersonalData(new PersonalData)
{
    qDebug() << "HeroCreatorManager constructor!";
}

CardData *HeroCreatorManager::cardData() const
{
    return m_pCardData;
}

void HeroCreatorManager::setName(const QString &name)
{
    m_pPersonalData->setName(name);
    qDebug() << name;
}

void HeroCreatorManager::setSurname(const QString &surname)
{
    m_pPersonalData->setSurname(surname);
    qDebug() << surname;
}

void HeroCreatorManager::setNickname(const QString &nickname)
{
    m_pPersonalData->setNickname(nickname);
    qDebug() << nickname;
}

void HeroCreatorManager::setOrigin(OriginData *origin)
{
    m_pPersonalData->setOrigin(origin);
}

void HeroCreatorManager::setOriginFeature(FeatureData *feature)
{
    m_pPersonalData->setOriginFeature(feature);
    originFeatureChanged();
}

void HeroCreatorManager::setProfession(ProfessionData *profession)
{
    m_pPersonalData->setProfession(profession);
}

void HeroCreatorManager::setProfessionFeature(FeatureData *feature)
{
    m_pPersonalData->setProfessionFeature(feature);
    professionFeatureChanged();
}
