#include "StatsCreator.h"

StatsCreator::StatsCreator(QObject *parent)
    : PageCreator(PageCreator::Type::STATS, parent)
{

}

void StatsCreator::setName(const QString &name)
{
    m_name = name;
}

void StatsCreator::setSurname(const QString &surname)
{
    m_surname = surname;
}

void StatsCreator::setNickname(const QString &nickname)
{
    m_nickname = nickname;
}

void StatsCreator::setOrigin(Origin *origin)
{

}

void StatsCreator::setProfession(Profession *profession)
{

}

void StatsCreator::setSpecialization(Data *specialization)
{
    m_pSpecialization = specialization;
}

void StatsCreator::setOriginFeature(Feature *feature)
{

}

void StatsCreator::setProfessionFeature(Feature *feature)
{

}

void StatsCreator::setDisease(Disease *disease)
{

}

void StatsCreator::setReputation(const QString &place, const int &value)
{
    m_reputation.insert(place, value);
}
