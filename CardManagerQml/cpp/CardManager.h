﻿#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include <QObject>
#include <QList>
#include <QQmlListProperty>

class CardWrapper;

class CardManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CardWrapper> cards READ cards NOTIFY cardsChanged)

public:
    explicit CardManager(QObject *parent = nullptr);

    QQmlListProperty<CardWrapper> cards();

    void appendCard(CardWrapper*);
    int cardsCount() const;
    CardWrapper *card(int) const;
    void clearCards();
    Q_INVOKABLE CardWrapper *card(QString filePath) const;

signals:
    void cardsChanged(bool add);
    void cardAdded(CardWrapper *card);
    void errorMessage(QString message) const;

public slots:
    Q_INVOKABLE void loadCard(const QString &fileName);
    Q_INVOKABLE void closeCard(const QString &fileName);

private:
    static void appendCard(QQmlListProperty<CardWrapper>*, CardWrapper*);
    static int cardsCount(QQmlListProperty<CardWrapper>*);
    static CardWrapper *card(QQmlListProperty<CardWrapper>*, int);
    static void clearCards(QQmlListProperty<CardWrapper>*);

private:
    QList<CardWrapper*> m_pCards;
    QStringList m_cardsFiles;
};

#endif // CARDMANAGER_H
