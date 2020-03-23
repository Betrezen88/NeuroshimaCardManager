#ifndef CORE_H
#define CORE_H

#include "core_global.h"

#include <QObject>

class CORE_EXPORT Card : public QObject
{
public:
    explicit Card(QObject *parent = nullptr);
};

#endif // CORE_H
