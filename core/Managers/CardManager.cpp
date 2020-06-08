#include "CardManager.h"
#include "Card/Card.h"

#include "Utils/DataReader.h"
#include "Utils/CardBuilder.h"

#include <QJsonDocument>
#include <QUrl>

CardManager::CardManager(QObject *parent) : QObject(parent)
{

}

QQmlListProperty<Card> CardManager::cards()
{
    return QQmlListProperty<Card>(this, this,
                                  &CardManager::appendCard,
                                  &CardManager::cardsCount,
                                  &CardManager::card,
                                  &CardManager::clearCards);
}

void CardManager::appendCard(Card *card)
{
    card->setParent(this);
    m_cards.append(card);
    m_cardsFilePaths.append(card->filePath());
    emit cardsChanged();
}

int CardManager::cardsCount() const
{
    return m_cards.count();
}

Card *CardManager::card(int index) const
{
    return m_cards.at(index);
}

void CardManager::clearCards()
{
    m_cards.clear();
    emit cardsChanged();
}

void CardManager::appendCard(QQmlListProperty<Card> *list, Card *card)
{
    reinterpret_cast<CardManager*>(list->data)->appendCard(card);
}

int CardManager::cardsCount(QQmlListProperty<Card> *list)
{
    return reinterpret_cast<CardManager*>(list->data)->cardsCount();
}

Card* CardManager::card(QQmlListProperty<Card> *list, int index)
{
    return reinterpret_cast<CardManager*>(list->data)->card(index);
}

void CardManager::clearCards(QQmlListProperty<Card> *list)
{
    reinterpret_cast<CardManager*>(list->data)->clearCards();
}

QString CardManager::selectedCard() const
{
    return m_selectedCard;
}

void CardManager::setSelectedCard(const QString &selectedCard)
{
    if ( m_selectedCard == selectedCard )
        return;

    m_selectedCard = selectedCard;
    emit selectedCardChanged();
}

Card *CardManager::card(const QString &fileName) const
{
    if ( !m_cardsFilePaths.contains(fileName) )
        return nullptr;

    return card(m_cardsFilePaths.indexOf(fileName));
}

void CardManager::loadCard(const QString &filePath)
{
    DataReader reader;
    QUrl file(filePath);

    std::tuple<bool, QJsonDocument, QString> data = reader.load( file.toLocalFile() );

    if ( !std::get<0>(data) ) {
        emit errorMessage( std::get<2>(data) );
        return;
    }

    CardBuilder builder;

    appendCard( builder.build(std::get<1>(data).object()) );
}

void CardManager::closeCard(const QString &filePath)
{
    if ( !m_cardsFilePaths.contains(filePath) ) {
        emit errorMessage("Brak karty, którą chcesz zamknąć.");
        return;
    }

    const int index = m_cardsFilePaths.indexOf(filePath);

    m_cards.removeAt( index );
    m_cardsFilePaths.removeAt( index );

    if ( 0 < m_cardsFilePaths.count() && filePath == m_selectedCard )
        setSelectedCard( m_cardsFilePaths.first() );

    emit cardsChanged();
}
