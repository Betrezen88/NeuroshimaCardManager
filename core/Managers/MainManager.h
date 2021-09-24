#ifndef MAINMANAGER_H
#define MAINMANAGER_H

#include <QObject>

#include "core_global.h"

class CardManager;
class CardCreator;
class DataSourceCreator;

class CORE_EXPORT MainManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CardManager* cardManager READ cardManager CONSTANT)
//    Q_PROPERTY(CardCreator* cardCreator READ cardCreator CONSTANT)
//    Q_PROPERTY(DataSourceCreator* dataSourceCreator READ dataSourceCreator CONSTANT)

public:
    explicit MainManager(QObject *parent = nullptr);

    CardManager* cardManager() const;
//    CardCreator* cardCreator();
//    DataSourceCreator* dataSourceCreator();

private:
    CardManager* m_pCardManager{nullptr};
//    CardCreator* m_pCardCreator{nullptr};
//    DataSourceCreator* m_pDataSourceCreator{nullptr};
};

#endif // MAINMANAGER_H
