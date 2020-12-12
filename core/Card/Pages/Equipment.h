#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Page.h"

#include "core_global.h"

class CORE_EXPORT Equipment : public Page
{
    Q_OBJECT
public:
    explicit Equipment(QObject *parent = nullptr);
};

#endif // EQUIPMENT_H
