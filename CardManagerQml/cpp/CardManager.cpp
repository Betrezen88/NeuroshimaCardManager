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
    m_cardsFiles.append(card->filePath());
    emit cardsChanged(true);
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
    emit cardsChanged(false);
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
    if ( !m_cardsFiles.contains(fileName) )
        emit errorMessage("Brak karty, którą chcesz zamknąć.");

    const int index = m_cardsFiles.indexOf(fileName);

    m_pCards.removeAt( index );
    m_cardsFiles.removeAt( index );

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
