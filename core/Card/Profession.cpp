#include "Profession.h"

Profession::Profession(QObject *parent) : QObject(parent)
{

}

QString Profession::name() const
{
    return m_name;
}
