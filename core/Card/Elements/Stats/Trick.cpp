#include "Trick.h"

Trick::Trick(QObject *parent)
    : Data(parent)
{

}

Trick::Trick(const QString &name,
             const QString &description,
             const QString &action,
             QObject *parent)
    : Data(name, description, parent),
      m_action(action)
{

}

QString Trick::action() const
{
    return m_action;
}
