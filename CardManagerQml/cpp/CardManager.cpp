#include "CardManager.h"

#include "cpp/Card/CardWrapper.h"

#include "Utils/DataReader.h"
#include "Utils/CardBuilder.h"

#include <tuple>

#include <QUrl>

#include <QDebug>

CardManager::CardManager(QObject *parent) : QObject(parent)
{

}

QString CardManager::selectedCard() const
{
    return m_selectedCard;
}

void CardManager::setSelectedCard(const QString &selectedCard)
{
    if ( selectedCard != m_selectedCard ) {
        m_selectedCard = selectedCard;
        emit selectedCardChanged();
    }
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
    m_cardsFiles.append(card->filePath());
    emit cardsChanged(true);

    if ( 1 == m_pCards.count() )
        setSelectedCard(card->filePath());
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
    emit cardsChanged(false);
}

CardWrapper *CardManager::card(QString filePath) const
{
    if ( !m_cardsFiles.contains(filePath) ) {
        emit errorMessage("Karta, którą chcesz wyświetlić, nie istnieje.");
        return nullptr;
    }
    return m_pCards.at( m_cardsFiles.indexOf(filePath) );
}

void CardManager::loadCard(const QString &fileName)
{
    DataReader reader;
    QUrl filePath(fileName);

    std::tuple<bool, QJsonObject, QString> data = reader.load( filePath.toLocalFile() );

    if ( !std::get<0>(data) ) {
        emit errorMessage( std::get<2>(data) );
        return;
    }

    CardBuilder builder;

    appendCard( new CardWrapper(filePath.toLocalFile(),
                                builder.build(std::get<1>(data)),
                                this) );
}

void CardManager::closeCard(const QString &fileName)
{
    if ( !m_cardsFiles.contains(fileName) ) {
        emit errorMessage("Brak karty, którą chcesz zamknąć.");
        return;
    }

    const int index = m_cardsFiles.indexOf(fileName);

    m_pCards.removeAt( index );
    m_cardsFiles.removeAt( index );

    if ( 0 < m_cardsFiles.count() && fileName == m_selectedCard )
        setSelectedCard( m_cardsFiles.first() );

    emit cardsChanged(false);
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
