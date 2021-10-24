#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include <QObject>
#include <QQmlListProperty>

#include "View/Card.h"

#include "core_global.h"

class Page;

class CORE_EXPORT CardManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Card> cards READ cards NOTIFY cardsChanged)
    Q_PROPERTY(QString selectedCard
               READ selectedCard
               WRITE setSelectedCard
               NOTIFY selectedCardChanged)

public:
    explicit CardManager(QObject *parent = nullptr);

    QQmlListProperty<Card> cards();
    void appendCard(Card *card);
    int cardsCount() const;
    Card *card(int index) const;
    void clearCards();

    QString selectedCard() const;
    void setSelectedCard(const QString &selectedCard);

signals:
    void cardsChanged();
    void selectedCardChanged();
    void errorMessage(const QString& title, const QString &message);
    void infoMessage(const QString& title, const QString& message);

public slots:
    Card *card(const QString &fileName) const;
    Card* currentCard() const;
    void loadCard(const QString &filePath);
    void closeCard(const QString &filePath);
    void saveSelectedCard();

private:
    void createRulesPage(const QString& filePath);

    static void appendCard(QQmlListProperty<Card> *list, Card *card);
    static int cardsCount(QQmlListProperty<Card> *list);
    static Card *card(QQmlListProperty<Card> *list, int index);
    static void clearCards(QQmlListProperty<Card> *list);

private:
    QVector<Card*> m_cards;
    QStringList m_cardsFilePaths;
    QString m_selectedCard;
    Page* m_pRulesPage{nullptr};
};

#endif // CARDMANAGER_H
