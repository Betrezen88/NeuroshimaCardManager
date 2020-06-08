#ifndef MAINMANAGER_H
#define MAINMANAGER_H

#include <QObject>

#include "core_global.h"

class CardManager;

class CORE_EXPORT MainManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CardManager *cardManager READ cardManager CONSTANT)

public:
    explicit MainManager(QObject *parent = nullptr);

    CardManager *cardManager() const;

private:
    CardManager *m_pCardManager{nullptr};
};

#endif // MAINMANAGER_H
