#ifndef CARDCREATOR_H
#define CARDCREATOR_H

#include <QObject>
#include <QMap>

#include "core_global.h"

#include "PageCreator.h"
#include "DataSources/DataSource.h"
#include "Utils/Dice.h"

class CreationPointsManager;
class TrickValidator;

class CORE_EXPORT CardCreator : public QObject
{
    Q_OBJECT
public:
    explicit CardCreator(QObject *parent = nullptr);

    Q_INVOKABLE PageCreator* pageCreator(const PageCreator::Type &type);
    Q_INVOKABLE DataSource* dataSource(const DataSource::Type &type);
    Q_INVOKABLE void createDataSource(const DataSource::Type &type,
                                      const QVariantMap &dataFiles);
    Q_INVOKABLE CreationPointsManager* creationPointsManager();

    Q_INVOKABLE TrickValidator *trickValidator() const;

    Q_INVOKABLE int diceRoll() const;
private:
    PageCreator* createPageCreator(const PageCreator::Type &type);

private:
    QMap<PageCreator::Type, PageCreator*> m_pageCreators;
    QMap<DataSource::Type, DataSource*> m_dataSources;
    CreationPointsManager* m_pPointsManager{nullptr};
    TrickValidator *m_pTrickValidator{nullptr};
    Dice m_d20{20};
};

#endif // CARDCREATOR_H
