#include "CardManager.h"

#include "View/Card.h"

#include "Utils/DataReader.h"
#include "Utils/DataWriter.h"
#include "Utils/CardBuilder.h"
#include "Utils/Converter.h"

#include <QJsonDocument>
#include <QUrl>

#include <QDebug>

CardManager::CardManager(QObject *parent) : QObject(parent)
{
    // TODO: think and rework Rules page location and loading
    createRulesPage( ":/json/resources/json/Rules.json" );
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
    if ( card == nullptr ) return;

    card->setParent(this);
//    card->addPage(m_pRulesPage);
    m_cards.append(card);

    if ( m_selected == nullptr )
        setSelected( m_cards.first() );

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

Card *CardManager::selected() const
{
    return m_selected;
}

bool CardManager::hasUnsavedData() const
{
    return m_cards.end() != std::find_if(m_cards.begin(),
                                         m_cards.end(),
                                         [](const Card* card){ return card->modified(); });
}

void CardManager::showCard(const int index)
{
    if ( index < 0 || index >= m_cards.count() )
        return;

    setSelected( m_cards.at( index ) );
}

void CardManager::loadCard(const QString &filePath)
{
    DataReader reader;
    QUrl file(filePath);

    if ( isCardLoaded(file.toLocalFile()) )
        return;

    std::tuple<bool, QJsonDocument, QString> data = reader.load( file.toLocalFile() );

    if ( !std::get<0>(data) ) {
        emit errorMessage("Błąd wczytywania", std::get<2>(data) );
        return;
    }

    CardBuilder builder;

    appendCard( builder.build(filePath, std::get<1>(data).object()) );
}

void CardManager::closeCard(const int index)
{
    if ( index < 0 || index >= m_cards.count() )
        return;

    Card* toClose = m_cards.takeAt( index );
    emit cardsChanged();

    if ( m_selected == toClose )
        setSelected( (m_cards.count() == 0) ? nullptr : m_cards.first() );

    toClose->deleteLater();
}

void CardManager::closeCard(Card *card)
{
    closeCard( m_cards.indexOf(card) );
}

void CardManager::saveCard(const int index)
{
    if ( index < 0 || index >= m_cards.count() )
        return;

    saveCard( m_cards.at(index) );
}

void CardManager::saveCard(Card *card)
{
    Converter converter;
    DataWriter writer;

    QUrl file(card->filePath());

    std::tuple<bool, QString> msg = writer.save(
                file.toLocalFile(),
                QJsonDocument(converter.toJson(card)) );

    if ( !std::get<0>(msg) )
        emit errorMessage( "Błąd zapisu", std::get<1>(msg) );
    else {
        card->setModified( false );
        emit infoMessage( "Zapisano kartę", std::get<1>(msg) );
    }
}

void CardManager::saveSelectedCard()
{
    Converter converter;
    DataWriter writer;

    QUrl file(m_selected->filePath());

    std::tuple<bool, QString> msg = writer.save(
                file.toLocalFile(),
                QJsonDocument(converter.toJson(m_selected)) );

    if ( !std::get<0>(msg) )
        emit errorMessage( "Błąd zapisu", std::get<1>(msg) );
    else {
        m_selected->setModified( false );
        emit infoMessage( "Potwierdzenie zapisu", std::get<1>(msg) );
    }
}

void CardManager::saveAndCloseAllCards()
{
    for ( auto it = m_cards.rbegin(); it != m_cards.rend(); ++it ) {
        saveCard( *it );
        closeCard( *it );
    }
}

void CardManager::closeSelectedCard()
{
    const int index = m_cards.indexOf( m_selected );

    if ( index == -1 ) {
        emit errorMessage( "Błąd zamykania", "Karta, którą próbujesz zamknąć nie znajduje się już w pamięci." );
        return;
    }

    closeCard( index );
}

bool CardManager::isCardLoaded(const QString &fileName)
{
    return m_cards.end() != std::find_if(m_cards.begin(),
                                         m_cards.end(),
                                         [&fileName](const Card* card){
        return card->filePath() == fileName;
    });
}

void CardManager::setSelected(Card *card)
{
    if ( m_selected == card )
        return;

    m_selected = card;
    emit selectedChanged();
}

void CardManager::createRulesPage(const QString &filePath)
{
    DataReader reader;

    std::tuple<bool, QJsonDocument, QString> data = reader.load( filePath );

    if ( !std::get<0>(data) ) {
        emit errorMessage("Błąd wczytywania reguł", std::get<2>(data) );
        return;
    }

    CardBuilder builder;
//    m_pRulesPage = builder.rulesPage(std::get<1>(data).array());
}
