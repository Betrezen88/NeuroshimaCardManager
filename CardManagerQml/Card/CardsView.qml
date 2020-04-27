import QtQuick 2.0
import QtQuick.Controls 2.5

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
            console.log("Cards on list: ", cardManager.cards.length);
            var length = cardManager.cards.length;
            if ( 0 < length ) {
                var component = Qt.createComponent("CardButton.qml");
                var object = component.createObject(row, {
                                                        card: cardManager.cards[length-1],
                                                        height: upperPanel.height
                                                    });
                console.log("CardButton.size: ", object.width, object.height);
                if ( 1 === length ) {
                    card.cardData = cardManager.cards[length-1];
                    card.visible = true;
                }
            }
            else {
                console.log("No cards in list");
                card.visible = false;
            }
        }
    }
}
