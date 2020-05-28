#ifndef MAINMANAGER_H
#define MAINMANAGER_H

#include <QObject>

class CardManager;
class HeroCreatorManager;

class MainManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CardManager *cardManager READ cardManager CONSTANT)
    Q_PROPERTY(HeroCreatorManager *heroCreator READ heroCreator CONSTANT)

public:
    explicit MainManager(QObject *parent = nullptr);

    CardManager *cardManager() const;
    HeroCreatorManager *heroCreator();

private:
    CardManager *m_pCardManager{nullptr};
    HeroCreatorManager *m_pHeroCreatorManager{nullptr};
};

#endif // MAINMANAGER_H
