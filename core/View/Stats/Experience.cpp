#include "Experience.h"

Experience::Experience(QObject *parent) : QObject(parent)
{

}

Experience::Experience(ExperienceData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

int Experience::gathered() const
{
    return m_data ? m_data->gathered : 0;
}

int Experience::spended() const
{
    return m_data ? m_data->spended : 0;
}

int Experience::availble() const
{
    return m_data ? m_data->gathered - m_data->spended : 0;
}

void Experience::addExperience(const int experience)
{
    if ( !m_data )
        return;

    m_data->gathered += experience;
    emit gatheredChanged();
}
