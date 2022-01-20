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
    Q_PROPERTY(Card* selected READ selected NOTIFY selectedChanged)

public:
    explicit CardManager(QObject *parent = nullptr);

    QQmlListProperty<Card> cards();
    void appendCard(Card *card);
    int cardsCount() const;
    Card *card(int index) const;
    void clearCards();

    Card *selected() const;

signals:
    void cardsChanged();
    void selectedChanged();
    void errorMessage(const QString& title, const QString &message);
    void infoMessage(const QString& title, const QString& message);

public slots:
    void showCard(const int index);
    void loadCard(const QString &filePath);
    void closeCard(const int index);
    void saveSelectedCard();

private:
    bool isCardLoaded(const QString &fileName);
    void setSelected(Card* card);
    void createRulesPage(const QString& filePath);

    static void appendCard(QQmlListProperty<Card> *list, Card *card);
    static int cardsCount(QQmlListProperty<Card> *list);
    static Card *card(QQmlListProperty<Card> *list, int index);
    static void clearCards(QQmlListProperty<Card> *list);

private:
    QVector<Card*> m_cards;
    Card* m_selected{nullptr};
    Page* m_pRulesPage{nullptr};
};

#endif // CARDMANAGER_H
