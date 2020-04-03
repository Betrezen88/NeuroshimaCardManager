﻿#include "ProfessionData.h"

ProfessionData::ProfessionData(const QString &name,
                               const QString &description)
    : m_name(name),
      m_description(description)
{

}

QString ProfessionData::name() const
{
    return m_name;
}

QString ProfessionData::description() const
{
    return m_description;
}
