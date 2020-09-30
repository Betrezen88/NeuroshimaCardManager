#include "StatsCreator.h"
#include "../Card/Elements/Stats/Attribute.h"
#include "../Card/Elements/Stats/Skillpack.h"
#include "../Card/Elements/Stats/OtherSkill.h"
#include "../Card/Elements/Stats/Skill.h"

#include "../Utils/DataReader.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

StatsCreator::StatsCreator(QObject *parent)
    : PageCreator(PageCreator::Type::STATS, parent)
{
    DataReader reader;
    std::tuple<bool, QJsonDocument, QString> data =
            reader.load(":/json/resources/json/Attributes.json");
    for ( const QJsonValue &attribute: std::get<1>(data).array() ) {
        const QJsonObject &tAttribute = attribute.toObject();

        QVector<Skillpack*> skillpacks;
        for ( const QJsonValue &skillpack: tAttribute.value("skillpacks").toArray() ) {
            const QJsonObject &tSkillpack = skillpack.toObject();

            QStringList specs;
            for ( const QJsonValue &specialization: tSkillpack.value("specializations").toArray() ) {
                specs << specialization.toString();
            }

            QVector<Skill*> skills;
            for ( const QJsonValue &skill: tSkillpack.value("skills").toArray() ) {
                skills.push_back(new Skill(skill.toString(), 0));
                m_skills.push_back(skills.last());
            }

            const Skillpack::Type &type = (skills.count() != 3)
                    ? Skillpack::Type::CHOOSABLE
                    : Skillpack::Type::CONSTANT;

            skillpacks.push_back( new Skillpack(tSkillpack.value("name").toString(),
                                                specs,
                                                skills,
                                                type) );
        }

        m_attributes.append(new Attribute(tAttribute.value("name").toString(),
                                          0,
                                          skillpacks) );
        emit attributesChanged();
    }
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

QQmlListProperty<Attribute> StatsCreator::attributes()
{
    return QQmlListProperty<Attribute>(reinterpret_cast<PageCreator*>(this), this,
                                       &StatsCreator::attributesCount,
                                       &StatsCreator::attribute);
}

int StatsCreator::attributesCount() const
{
    return m_attributes.count();
}

Attribute *StatsCreator::attribute(const int &index) const
{
    return m_attributes.at(index);
}

Attribute *StatsCreator::attribute(const QString &name)
{
    for ( Attribute* pAttribute: m_attributes )
        if ( name == pAttribute->name() )
            return pAttribute;

    return nullptr;
}

Attribute *StatsCreator::getAttribute(const QString &name) const
{
    for ( Attribute* pAttribute: m_attributes )
        if ( name == pAttribute->name() )
            return pAttribute;

    return nullptr;
}

QVector<Attribute *> StatsCreator::attributes() const
{
    return m_attributes;
}

Skill *StatsCreator::getSkill(const QString &name) const
{
    for ( Skill* skill: m_skills )
        if ( name == skill->name() )
            return skill;

    return nullptr;
}

QString StatsCreator::profession() const
{
    return m_pProfession->name();
}

void StatsCreator::setName(const QString &name)
{
    m_name = name;
    emit nameChanged(m_name);
}

void StatsCreator::setSurname(const QString &surname)
{
    m_surname = surname;
    emit surnameChanged(m_surname);
}

void StatsCreator::setNickname(const QString &nickname)
{
    m_nickname = nickname;
    emit nicknameChanged(m_nickname);
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
    m_pDisease = disease;
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

Attribute *StatsCreator::attribute(QQmlListProperty<Attribute> *list, int index)
{
    return reinterpret_cast<StatsCreator*>(list->data)->attribute(index);
}

int StatsCreator::attributesCount(QQmlListProperty<Attribute> *list)
{
    return reinterpret_cast<StatsCreator*>(list->data)->attributesCount();
}
