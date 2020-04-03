#ifndef CARD_H
#define CARD_H

#include <QObject>

class CardData;

class Card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fullname READ fullname CONSTANT)

public:
    explicit Card(CardData *cardData, QObject *parent = nullptr);

    QString fullname();

signals:


private:
    CardData *m_pCardData{nullptr};
};

#endif // CARD_H
