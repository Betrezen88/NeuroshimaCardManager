#ifndef TRICK_H
#define TRICK_H

#include "../../Data.h"

#include "core_global.h"

class CORE_EXPORT Trick : public Data
{
    Q_OBJECT
public:
    Trick(QObject *parent = nullptr);
    Trick(const QString &name,
          const QString &description,
          const QString &action,
          QObject *parent = nullptr);

    QString action() const;

private:
    QString m_action;
};

#endif // TRICK_H
