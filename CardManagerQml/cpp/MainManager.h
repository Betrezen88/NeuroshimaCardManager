#ifndef MAINMANAGER_H
#define MAINMANAGER_H

#include <QObject>

class CardManager;

class MainManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CardManager *cardManager READ cardManager CONSTANT)

public:
    explicit MainManager(QObject *parent = nullptr);

    CardManager *cardManager() const;

signals:

private:
    CardManager *m_pCardManager{nullptr};
};

#endif // MAINMANAGER_H
