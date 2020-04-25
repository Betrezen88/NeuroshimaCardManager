﻿#include "CardManager.h"

#include "cpp/Card/CardWrapper.h"

CardManager::CardManager(QObject *parent) : QObject(parent)
{

}

QQmlListProperty<CardWrapper> CardManager::cards()
{
    return QQmlListProperty<CardWrapper>(this, this,
                                         &CardManager::appendCard,
                                         &CardManager::cardsCount,
                                         &CardManager::card,
                                         &CardManager::clearCards);
}

void CardManager::appendCard(CardWrapper *card)
{
    m_pCards.append(card);
    emit cardsChanged();
}

int CardManager::cardsCount() const
{
    return m_pCards.count();
}

CardWrapper *CardManager::card(int index) const
{
    return m_pCards.at(index);
}

void CardManager::clearCards()
{
    m_pCards.clear();
    emit cardsChanged();
}

void CardManager::appendCard(QQmlListProperty<CardWrapper> *list, CardWrapper *card)
{
    reinterpret_cast<CardManager*>(list->data)->appendCard(card);
}

int CardManager::cardsCount(QQmlListProperty<CardWrapper> *list)
{
    return reinterpret_cast<CardManager*>(list->data)->cardsCount();
}

CardWrapper *CardManager::card(QQmlListProperty<CardWrapper> *list, int index)
{
    return reinterpret_cast<CardManager*>(list->data)->card(index);
}

void CardManager::clearCards(QQmlListProperty<CardWrapper> *list)
{
    reinterpret_cast<CardManager*>(list->data)->clearCards();
}
