#include "StatsSource.h"

#include "Elements/Stats/Origin.h"
#include "Elements/Stats/Profession.h"
#include "../Card/Data.h"
#include "../Card/Elements/Stats/Disease.h"
#include "../Card/Elements/Stats/Attribute.h"

StatsSource::StatsSource(QObject *parent)
    : DataSource(DataSource::Type::STATS, parent)
{

}

QQmlListProperty<Origin> StatsSource::origins()
{
    return QQmlListProperty<Origin>(reinterpret_cast<DataSource*>(this), this,
                                    &StatsSource::addOrigin,
                                    &StatsSource::originsCount,
                                    &StatsSource::origin,
                                    &StatsSource::clearOrigins);
}

void StatsSource::addOrigin(Origin *origin)
{
    m_origins.push_back(origin);
    emit originsChanged();
}

int StatsSource::originsCount() const
{
    return m_origins.count();
}

Origin *StatsSource::origin(const int &index) const
{
    return m_origins.at(index);
}

void StatsSource::clearOrigins()
{
    m_origins.clear();
    emit originsChanged();
}

QQmlListProperty<Profession> StatsSource::professions()
{
    return QQmlListProperty<Profession>(reinterpret_cast<DataSource*>(this), this,
                                        &StatsSource::addProfession,
                                        &StatsSource::professionsCount,
                                        &StatsSource::profession,
                                        &StatsSource::clearProfessions);
}

void StatsSource::addProfession(Profession *profession)
{
    m_professions.push_back(profession);
    emit professionsChanged();
}

int StatsSource::professionsCount() const
{
    return m_professions.count();
}

Profession *StatsSource::profession(const int &index) const
{
    return m_professions.at(index);
}

void StatsSource::clearProfessions()
{
    m_professions.clear();
    emit professionsChanged();
}

QQmlListProperty<Data> StatsSource::specializations()
{
    return QQmlListProperty<Data>(reinterpret_cast<DataSource*>(this), this,
                                  &StatsSource::addSpecialization,
                                  &StatsSource::specializationsCount,
                                  &StatsSource::specialization,
                                  &StatsSource::clearSpecializations);
}

void StatsSource::addSpecialization(Data *specialization)
{
    m_specializations.push_back(specialization);
    emit specializationsChanged();
}

int StatsSource::specializationsCount() const
{
    return m_specializations.count();
}

Data *StatsSource::specialization(const int &index) const
{
    return m_specializations.at(index);
}

void StatsSource::clearSpecializations()
{
    m_specializations.clear();
    emit specializationsChanged();
}

QQmlListProperty<Disease> StatsSource::diseases()
{
    return QQmlListProperty<Disease>(reinterpret_cast<DataSource*>(this), this,
                                     &StatsSource::addDisease,
                                     &StatsSource::diseasesCount,
                                     &StatsSource::disease,
                                     &StatsSource::clearDiseases);
}

void StatsSource::addDisease(Disease *disease)
{
    m_diseases.push_back(disease);
    emit diseasesChanged();
}

int StatsSource::diseasesCount() const
{
    return m_diseases.count();
}

Disease *StatsSource::disease(const int &index) const
{
    return m_diseases.at(index);
}

void StatsSource::clearDiseases()
{
    m_diseases.clear();
    emit diseasesChanged();
}

QQmlListProperty<Attribute> StatsSource::attributes()
{
    return QQmlListProperty<Attribute>(reinterpret_cast<DataSource*>(this), this,
                                       &StatsSource::addAttribute,
                                       &StatsSource::attributesCount,
                                       &StatsSource::attribute,
                                       &StatsSource::clearAttributes);
}

void StatsSource::addAttribute(Attribute *attribute)
{
    m_attributes.push_back(attribute);
    emit attributesChanged();
}

int StatsSource::attributesCount() const
{
    return m_attributes.count();
}

Attribute *StatsSource::attribute(const int &index) const
{
    return m_attributes.at(index);
}

void StatsSource::clearAttributes()
{
    m_attributes.clear();
    emit attributesChanged();
}

Attribute *StatsSource::attribute(const QString &name) const
{
    for ( Attribute* pAttribute: m_attributes ) {
        if ( name == pAttribute->name() )
            return pAttribute;
    }

    return nullptr;
}

QQmlListProperty<NSTrick> StatsSource::tricks()
{
    return QQmlListProperty<NSTrick>(reinterpret_cast<DataSource*>(this), this,
                                   &StatsSource::addTrick,
                                   &StatsSource::tricksCount,
                                   &StatsSource::trick,
                                   &StatsSource::clearTricks);
}

void StatsSource::addTrick(NSTrick *trick)
{
    m_tricks.push_back(trick);
    emit tricksChanged();
}

int StatsSource::tricksCount() const
{
    return m_tricks.count();
}

NSTrick *StatsSource::trick(const int &index) const
{
    return m_tricks.at(index);
}

void StatsSource::clearTricks()
{
    m_tricks.clear();
    emit tricksChanged();
}

void StatsSource::addOrigin(QQmlListProperty<Origin> *list, Origin *origin)
{
    reinterpret_cast<StatsSource*>(list->data)->addOrigin(origin);
}

int StatsSource::originsCount(QQmlListProperty<Origin> *list)
{
    return reinterpret_cast<StatsSource*>(list->data)->originsCount();
}

Origin *StatsSource::origin(QQmlListProperty<Origin> *list, int index)
{
    return reinterpret_cast<StatsSource*>(list->data)->origin(index);
}

void StatsSource::clearOrigins(QQmlListProperty<Origin> *list)
{
    reinterpret_cast<StatsSource*>(list->data)->clearOrigins();
}

void StatsSource::addProfession(QQmlListProperty<Profession> *list, Profession *profession)
{
    reinterpret_cast<StatsSource*>(list->data)->addProfession(profession);
}

int StatsSource::professionsCount(QQmlListProperty<Profession> *list)
{
    return reinterpret_cast<StatsSource*>(list->data)->professionsCount();
}

Profession *StatsSource::profession(QQmlListProperty<Profession> *list, int index)
{
    return reinterpret_cast<StatsSource*>(list->data)->profession(index);
}

void StatsSource::clearProfessions(QQmlListProperty<Profession> *list)
{
    reinterpret_cast<StatsSource*>(list->data)->clearProfessions();
}

void StatsSource::addSpecialization(QQmlListProperty<Data> *list, Data *specialization)
{
    reinterpret_cast<StatsSource*>(list->data)->addSpecialization(specialization);
}

int StatsSource::specializationsCount(QQmlListProperty<Data> *list)
{
    return reinterpret_cast<StatsSource*>(list->data)->specializationsCount();
}

Data *StatsSource::specialization(QQmlListProperty<Data> *list, int index)
{
    return reinterpret_cast<StatsSource*>(list->data)->specialization(index);
}

void StatsSource::clearSpecializations(QQmlListProperty<Data> *list)
{
    reinterpret_cast<StatsSource*>(list->data)->clearSpecializations();
}

void StatsSource::addDisease(QQmlListProperty<Disease> *list, Disease *disease)
{
    reinterpret_cast<StatsSource*>(list->data)->addDisease(disease);
}

int StatsSource::diseasesCount(QQmlListProperty<Disease> *list)
{
    return reinterpret_cast<StatsSource*>(list->data)->diseasesCount();
}

Disease *StatsSource::disease(QQmlListProperty<Disease> *list, int index)
{
    return reinterpret_cast<StatsSource*>(list->data)->disease(index);
}

void StatsSource::clearDiseases(QQmlListProperty<Disease> *list)
{
    reinterpret_cast<StatsSource*>(list->data)->clearDiseases();
}

void StatsSource::addAttribute(QQmlListProperty<Attribute> *list, Attribute *attribute)
{
    reinterpret_cast<StatsSource*>(list->data)->addAttribute(attribute);
}

int StatsSource::attributesCount(QQmlListProperty<Attribute> *list)
{
    return reinterpret_cast<StatsSource*>(list->data)->attributesCount();
}

Attribute *StatsSource::attribute(QQmlListProperty<Attribute> *list, int index)
{
    return reinterpret_cast<StatsSource*>(list->data)->attribute(index);
}

void StatsSource::clearAttributes(QQmlListProperty<Attribute> *list)
{
    reinterpret_cast<StatsSource*>(list->data)->clearAttributes();
}

void StatsSource::addTrick(QQmlListProperty<NSTrick> *list, NSTrick *trick)
{
    reinterpret_cast<StatsSource*>(list->data)->addTrick(trick);
}

int StatsSource::tricksCount(QQmlListProperty<NSTrick> *list)
{
    return reinterpret_cast<StatsSource*>(list->data)->tricksCount();
}

NSTrick *StatsSource::trick(QQmlListProperty<NSTrick> *list, int index)
{
    return reinterpret_cast<StatsSource*>(list->data)->trick(index);
}

void StatsSource::clearTricks(QQmlListProperty<NSTrick> *list)
{
    reinterpret_cast<StatsSource*>(list->data)->clearTricks();
}
