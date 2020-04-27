#include "CardManager.h"

#include "cpp/Card/CardWrapper.h"

#include "Utils/DataReader.h"
#include "Utils/CardBuilder.h"

#include <tuple>

#include <QUrl>

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
    emit cardAdded(card);
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

void CardManager::loadCard(const QString &fileName)
{
    DataReader reader;

    std::tuple<bool, QJsonObject, QString> data = reader.load( QUrl(fileName).toLocalFile() );

    if ( !std::get<0>(data) ) {
        emit errorMessage( std::get<2>(data) );
        return;
    }

    CardBuilder builder;

    appendCard( new CardWrapper(builder.build(std::get<1>(data))) );
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
