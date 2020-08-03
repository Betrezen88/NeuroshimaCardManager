#include "StatsCreator.h"
#include "../Card/Elements/Stats/OtherSkill.h"

StatsCreator::StatsCreator(QObject *parent)
    : PageCreator(PageCreator::Type::STATS, parent)
{

}

QQmlListProperty<OtherSkill> StatsCreator::otherSkills()
{
    return QQmlListProperty<OtherSkill>(reinterpret_cast<PageCreator*>(this), this,
                                        &StatsCreator::otherSkillsCount,
                                        &StatsCreator::otherSkill);
}

OtherSkill *StatsCreator::otherSkill(const int &index) const
{
    return m_otherSkills.at(index);
}

int StatsCreator::otherSkillsCount() const
{
    return m_otherSkills.count();
}

void StatsCreator::addOtherSkill(const QString &name,
                                 const QString &attribute,
                                 const int &value)
{
    m_otherSkills.push_back(new OtherSkill(name, value, attribute));
    emit otherSkillsChanged();
}

void StatsCreator::removeOtherSkill(const QString &name)
{
    for (int i=0; i<m_otherSkills.count(); ++i)
        if ( name == m_otherSkills.at(i)->name() ) {
            OtherSkill* pOtherSkill = m_otherSkills.takeAt(i);
            delete pOtherSkill;
            emit otherSkillsChanged();
            break;
        }
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

void StatsCreator::setOrigin(const QString &name, const QString &description)
{
    if ( m_pOrigin != nullptr )
        delete m_pOrigin;

    m_pOrigin = new Data(name, description);
}

void StatsCreator::setOriginBonus(const QString &attribute, const int &value)
{
    m_originBonus = QPair<QString, int>(attribute, value);
    emit originBonusChanged(m_originBonus.first, m_originBonus.second);
}

void StatsCreator::setProfession(const QString &name, const QString &description)
{
    if ( m_pProfession != nullptr )
        delete m_pProfession;

    m_pProfession = new Data(name, description);
}

void StatsCreator::setSpecialization(const QString &name, const QString &description)
{
    if ( m_pSpecialization != nullptr )
        delete m_pSpecialization;

    m_pSpecialization = new Data(name, description);
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

OtherSkill *StatsCreator::otherSkill(QQmlListProperty<OtherSkill> *list, int index)
{
    return reinterpret_cast<StatsCreator*>(list->data)->otherSkill(index);
}

int StatsCreator::otherSkillsCount(QQmlListProperty<OtherSkill> *list)
{
    return reinterpret_cast<StatsCreator*>(list->data)->otherSkillsCount();
}
