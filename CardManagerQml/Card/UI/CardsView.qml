import QtQuick 2.0
import QtQuick.Controls 2.5

import "../"

Item {
    id: main

    ScrollView {
        id: upperPanel
        height: 40
        width: main.width

        Row {
            id: row
            spacing: 2
            anchors.fill: upperPanel
        }
    }

    Card {
        id: card
        anchors {
            top: upperPanel.bottom
            left: main.left
            right: main.right
            bottom: main.bottom
        }

        visible: false
    }

    Connections {
        target: cardManager
        onCardsChanged: {
            var length = cardManager.cards.length;
            if ( add ) {
                var component = Qt.createComponent("CardButton.qml");
                var object = component.createObject(row, {
                                                        card: cardManager.cards[length-1],
                                                        height: upperPanel.height
                                                    });
                if ( 1 === length ) {
                    card.cardData = cardManager.cards[length-1];
                    card.visible = true;
                }
            }
            else {
                if ( 0 === length ) card.visible = false;
            }
        }
    }
}
