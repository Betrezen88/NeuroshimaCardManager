import QtQuick 2.14
import QtQuick.Controls 2.5

import "./Card"

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Neuroshima Card Manager")

    Card {
        id: card
        cardData: cardManager.cards[0]
        width: parent.width
        height: parent.height
    }
}
