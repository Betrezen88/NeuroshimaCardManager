#include "ExperienceEditor.h"
#include "../../Data/Stats/ExperienceData.h"
#include "../../Data/Stats/SpecializationData.h"
#include "../../Utils/DataReader.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QDebug>

ExperienceEditor::ExperienceEditor(QObject *parent) : QObject(parent)
{

}

ExperienceEditor::ExperienceEditor(const QString &costFile,
                                   ExperienceData *data,
                                   SpecializationData* specialization,
                                   QObject *parent)
    : QObject(parent)
    , m_costFile(costFile)
    , m_data(data)
    , m_specialization(specialization)
{
    connect( this, &ExperienceEditor::availableChanged,
             this, &ExperienceEditor::checkIfNewSkillIsAffortable );

    loadCostData( m_costFile );
    checkIfNewSkillIsAffortable();
}

int ExperienceEditor::available() const
{
    return m_data ? m_data->gathered - m_data->spended : 0;
}

int ExperienceEditor::spended() const
{
    return m_data ? m_data->spended :  0;
}

int ExperienceEditor::attributeCost(const int level) const
{
    // Attribute starts from value 6
    const int index = level - 6;

    if ( index < 0 || index > m_attributeCost.count() ) {
        qDebug() << "ExperienceEditor::attributeCost(): wrong index:"
                 << index << " of " << m_attributeCost.count();
        return 0;
    }

    return ( index >= m_attributeCost.size()-1 )
            ? m_attributeCost.last() * level
            : m_attributeCost.at(index);
}

int ExperienceEditor::skillCost(const int level, const bool discount) const
{
     if ( level < 0 || level > m_skillCost.count() ) {
         qDebug() << "ExperienceEditor::skillCost(): wrong index:"
                  << level << " of " << m_skillCost.count();
         return 0;
     }

     const int cost = ( level >= m_skillCost.size()-1 )
             ? m_skillCost.last() * level
             : m_skillCost.at(level);

     return (discount) ? cost * m_discount : cost;
}

bool ExperienceEditor::isAttributeAfordable(const int level) const
{
    return attributeCost(level) <= available();
}

bool ExperienceEditor::isSkillAfordable(const int level,
                                        const QStringList &specializations) const
{
    const int index = level;

    if ( index < 0 || index > m_skillCost.count() ) {
        qDebug() << "ExperienceEditor::isSkillAfordable(): wrong index:" << index << " of " << m_skillCost.count();
        return false;
    }

    int cost = ( index >= m_skillCost.size()-1 )
            ? m_skillCost.last() * level
            : m_skillCost.at(index);
    cost = (specializations.contains(m_specialization->name)) ? cost * m_discount : cost;

    return cost <= available();
}

bool ExperienceEditor::isOtherSkillAfordable(const int level) const
{
    return isSkillAfordable(level, QStringList());
}

void ExperienceEditor::attributeIncreased(const int level)
{
    const int cost = attributeCost(level);
    increaseSpended( cost );
}

void ExperienceEditor::attributeDecreased(const int level)
{
    const int cost = attributeCost(level);
    decreaseSpended( cost );
}

void ExperienceEditor::skillIncreased(const int level, const QStringList &specializations)
{
    const int cost = skillCost(level, specializations.contains(m_specialization->name));
    increaseSpended( cost );
}

void ExperienceEditor::skillDecreased(const int level, const QStringList &specializations)
{
    const int cost = skillCost( level, specializations.contains(m_specialization->name) );
    decreaseSpended( cost );
}

void ExperienceEditor::otherSkillIncreased(const int level)
{
    skillIncreased(level, QStringList());
}

void ExperienceEditor::otherSkillDecreased(const int level)
{
    skillDecreased(level, QStringList());
}

void ExperienceEditor::increaseSpended(const int value)
{
    m_data->spended += value;
    emit spendedChanged();
    emit availableChanged();
}

void ExperienceEditor::decreaseSpended(const int value)
{
    m_data->spended -= value;
    emit spendedChanged();
    emit availableChanged();
}

void ExperienceEditor::checkIfNewSkillIsAffortable()
{
    m_isNewSkillAffortable = m_skillCost.first() <= available();
    emit isNewSkillAffortableChanged();
}

void ExperienceEditor::loadCostData(const QString& costFile)
{
    DataReader reader;
    std::tuple<bool, QJsonDocument, QString> data = reader.load(costFile);

    if ( !std::get<0>(data) ) {
        qDebug() << std::get<2>(data);
        return;
    }

    const QJsonObject json = std::get<1>(data).object();

    for ( const QJsonValue& tSkillCost : json.value("skill").toArray() ) {
        const QJsonObject& skillCost = tSkillCost.toObject();
        m_skillCost.push_back( skillCost.value("cost").toInt() );
    }

    for ( const QJsonValue& tAttributeCost : json.value("attribute").toArray() ) {
        const QJsonObject& attributeCost = tAttributeCost.toObject();
        m_attributeCost.push_back( attributeCost.value("cost").toInt() );
    }

    const QJsonObject& reputationCost = json.value("reputation").toObject();
    m_reputationCost.first = reputationCost.value("max").toInt();
    m_reputationCost.second = reputationCost.value("cost").toInt();

    const QJsonObject& trickCost = json.value("trick").toObject();
    m_trickCost.first = trickCost.value("max").toInt();
    m_trickCost.second = trickCost.value("cost").toInt();
}

bool ExperienceEditor::isNewSkillAffortable() const
{
    return m_isNewSkillAffortable;
}
