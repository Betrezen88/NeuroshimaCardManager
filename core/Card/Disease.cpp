#include "Disease.h"

Disease::Disease(QObject *parent) : QObject(parent)
{

}

QString Disease::name() const
{
    return m_name;
}
