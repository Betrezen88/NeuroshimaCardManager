﻿import QtQuick 2.0
import QtQuick.Controls 2.5

import "../"

Item {
    id: main

    Column {
        anchors.fill: parent
        spacing: 1
        ScrollView {
            id: upperPanel
            height: 40
            width: main.width

            Row {
                property var objects: []
                id: row
                spacing: 2
                anchors.fill: parent
            }
        }

        Card {
            id: card
            visible: false
            width: main.width
            height: main.height - upperPanel.height
        }
    }

    Connections {
        target: cardManager
        onCardsChanged: {
            var length = cardManager.cards.length;
            if ( add ) {
                var component = Qt.createComponent("CardButton.qml");
                var cardData = cardManager.cards[length-1];
                var object = component.createObject(row, {
                                                        cardPath: cardData.filePath,
                                                        fullname: cardData.stats.personal.fullname,
                                                        height: upperPanel.height
                                                    });
                row.objects.push(object);
                if ( 1 === length ) {
                    card.visible = true;
                }
            }
            else {
                if ( 0 === length ) card.visible = false;
            }
        }
        onSelectedCardChanged: {
            card.cardData = cardManager.card( cardManager.selectedCard );
        }
    }
}
